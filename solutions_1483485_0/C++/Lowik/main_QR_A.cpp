#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

using namespace std;


int main(int argc, char* argv[]) {

	/* First, build the correspondance Googlerese -> English */
	std::map<char, char> correspondance;

	correspondance['a'] = ' ';
	correspondance['b'] = ' ';
	correspondance['c'] = ' ';
	correspondance['d'] = ' ';
	correspondance['e'] = 'o';
	correspondance['f'] = ' ';
	correspondance['g'] = ' ';
	correspondance['h'] = ' ';
	correspondance['i'] = ' ';
	correspondance['j'] = 'u';
	correspondance['k'] = ' ';
	correspondance['l'] = ' ';
	correspondance['m'] = 'l';
	correspondance['n'] = ' ';
	correspondance['o'] = ' ';
	correspondance['p'] = 'r';
	correspondance['q'] = 'z';
	correspondance['r'] = ' ';
	correspondance['s'] = 'n';
	correspondance['t'] = ' ';
	correspondance['u'] = ' ';
	correspondance['v'] = ' ';
	correspondance['w'] = ' ';
	correspondance['x'] = ' ';
	correspondance['y'] = 'a';
	correspondance['z'] = ' ';
	correspondance[' '] = ' ';

	string inExampleName, outExampleName;

	cout << "Enter in example name : " << endl;
	cin >> inExampleName;
	cout << endl;

	cout << "Enter out example name : " << endl;
	cin >> outExampleName;
	cout << endl;

	ifstream inExampleFile(inExampleName.c_str());
	if(!inExampleFile.is_open()) {
		cout << "Can't open input file" << endl;
		system("PAUSE");
		return 1;
	}

	ifstream outExampleFile(outExampleName.c_str());
	if(!outExampleFile.is_open()) {
		cout << "Can't open input file" << endl;
		system("PAUSE");
		return 1;
	}

	/* Read in file here */
	string dummy;

	getline(inExampleFile, dummy);
	for(int n = 0; n < 3; n++) {
		string iline;
		string oline;
		getline(inExampleFile, iline);

		getline(outExampleFile, oline);

		for(size_t i = 0; i< iline.size(); i++) {
			char ic = iline.at(i);
			char oc = oline.at(i);
			correspondance[ic] = oc;
		}
	}
	correspondance['z'] = 'q';

	inExampleFile.close();
	outExampleFile.close();


	/* Now we can translate */
	string inTestName, outTestName;

	cout << "Enter the in test file name : " << endl;
	cin >> inTestName;
	cout << endl;

	cout << "Enter the out test file name : " << endl;
	cin >> outTestName;
	cout << endl;

	/* Open file */
	ifstream inFile(inTestName.c_str());
	if(!inFile.is_open()) {
		cout << "Can't open input file" << endl;
		system("PAUSE");
		return 1;
	}

	ofstream outFile(outTestName.c_str());
	if(!outFile.is_open()) {
		cout << "Can't open output file" << endl;
		system("PAUSE");
		return 1;
	}

	int Ntest;
	inFile >> Ntest;
	getline(inFile, dummy);

	for(int n = 0; n < Ntest; n++) {
		/* Read input text */
		string inText;
		getline(inFile, inText);
		/* Translate */
		string outText;
		for(size_t c = 0; c < inText.size(); c++) {
			outText.push_back(correspondance[inText.at(c)]);
		}

		/* Write */
		outFile << "Case #" << n+1 << ": " << outText << endl;
	}

	outFile.close();
	inFile.close();

	system("PAUSE");
	return 0;
}

