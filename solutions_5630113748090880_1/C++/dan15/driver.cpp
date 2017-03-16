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
	size_t N;
	for (size_t x = 1; x <= cases; x++) {
		outfile << "Case #" << x << ": ";
		infile >> N;
		std::map<int, int> myMap;
		size_t temp;
		for (size_t i = 0; i < N*((2*N)-1); i++) {
			infile >> temp;
			if (myMap.find(temp) == myMap.end()) {
				myMap[temp] = 1;
			}
			else {
				myMap.erase(temp);
			}
		}
		for (std::map<int, int>::iterator it = myMap.begin(); it != myMap.end(); it++) {
			outfile << it->first << " ";
		}
		outfile << endl;
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