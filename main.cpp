#include<fstream>
#include<string>
#include<iostream>
#include<MacEncoding.h>

int main( int argc, char *argv[] ){
	std::string inputFileName;
	std::string outputFileName;
	//read file containing the network address, e.g., 00-10-18-4e-62-91
	MacEncoding* mac = nullptr;

	switch (argc)
	{
		using namespace std;
	case 1:
		mac = new MacEncoding;
		break;
	case 2:
		if (!string("-h").compare(argv[1])) {
			cout << "help:" << endl;
			cout << "for mac address:" << endl;
			cout << "-m your mac address" << endl;
			cout << "for *.txt contains mac address:" << endl;
			cout << "-f your file name" << endl;
			cout << "no parameters:" << endl;
			cout << "this computer's mac address" << endl;
			break;

		}
	case 3:
		if (!string("-m").compare(argv[1])) {
			mac = new MacEncoding(argv[2]);
			break;
		}
		if (!string("-f").compare(argv[1])) {
			ifstream in;    // Create an input file stream.
			inputFileName = argv[2];
			in.open(inputFileName.c_str());  // Use it to read from a file.
			char ch[18];
			in >> ch;
			in.close();
			mac = new MacEncoding(ch);
			break;
		}
	default:
		cerr << "wrong parameters" << endl;
		cerr << "try \"-h\" parameter" << endl;
		break;
	}
	if (mac != nullptr) {
		std::cout << mac->MAC << std::endl;
		outputFileName = "license.dat";
		std::ofstream out;    // Create an output file stream.
		out.open(outputFileName.c_str());	// Use it to write a file.
		out << mac->encodeString() << '\n';	//write the encoded, e.g.,
		out.close();
		delete mac;
	}

	return 0;
}





