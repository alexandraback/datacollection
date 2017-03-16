#include <iostream>
#include <fstream>

#include <string>
#include <sstream>
#include <cstdlib>
#include "math.h"
#include <vector>
#include <stack>
#include <map>


using namespace std;

// open input and output files
// pre: user is prepared to enter file names at the keyboard
// post: files have been opened
void openFiles(ifstream &infile, ofstream &outfile);

int main()
{
	
	ifstream infile;
	ofstream outfile;
	openFiles(infile, outfile);

	cout << "Reading the input file..." << endl;

	size_t cases;
	infile >> cases;
	string input = "";
	string acc = "";
	for (size_t x = 1; x <= cases; x++) {
		outfile << "Case #" << x << ": ";
		infile >> input;
		acc = input[0];
		for (size_t i = 1; i < input.length(); i++) {
			if (input[i] < acc[0]) {
				acc = acc + input[i];
			}
			else {
				acc = input[i] + acc;
			}
		}
		outfile << acc << endl;
	}
	cout << "Enter a char to exit:" << endl;
	char c;
	cin >> c;

	// close the files
	infile.close();
	outfile.close();
	cout << "Done." << endl;
	
}


// open input and output files
// pre: user is prepared to enter file names at the keyboard
// post: files have been opened
void openFiles(ifstream &infile, ofstream &outfile)
{

	// open input data file
	string inFileName;
	cout << "Enter the name of the input file: ";
	cin >> inFileName;
	infile.open(inFileName.c_str());
	if (infile.fail()) {
		cout << "Error opening input data file" << endl;
		char junk;
		cout << "press enter to exit";
		junk = cin.get();
		junk = cin.get();
		exit(1);
	}

	// open output data file
	string outFileName;
	cout << "Enter the name of the output file: ";
	cin >> outFileName;
	outfile.open(outFileName.c_str());
	if (outfile.fail()) {
		cout << "Error opening output data file" << endl;
		char junk;
		cout << "press enter to exit";
		junk = cin.get();
		junk = cin.get();
		exit(1);
	}

}