// Round1C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdlib.h>
#include <math.h>

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

const string OUTPUT_FILENAME = "output.txt";

template <typename T>
T StringToNumber ( const string &Text )
{
	istringstream ss(Text);
	T result;
	return ss >> result ? result : 0;
}

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

struct InputLineData {
	string& lineBuf;
	vector<string>& splittedLineBuf;
	vector<int>& splittedLineNums;
};

struct InputDataSet {
	int lineNumber;
	string name;
	int n;
};

bool isVowels( char c ) {
	switch( c ) {
	case 'a' :
	case 'e' :
	case 'i' :
	case 'o' :
	case 'u' :
		return true;
	default:
		return false;
	}
}

void Calc( InputDataSet& data , ofstream& ofs ) 
{
	long long output = 0;

	cout << "Input (" << data.lineNumber << ") " << data.name << " n=" << data.n << endl;

	int nConsCount = 0;
	int nConfCount = 0;
	const char* pName = data.name.c_str();
	int nN = data.n;
	int nNameSize = data.name.size();
	
	for( int i = 0; i < nNameSize ; i++ ) {
		if( !isVowels(pName[i]) ) {
			nConsCount++;
			if( nConsCount >= nN ) {
				// after
				long long nAft = nNameSize - i;
				output += nAft;
				// before
				long long nBef = i - nConfCount - nN + 1;
				output += nBef * nAft;
				
				nConfCount+=nBef+1;
			}
		}
		else {
			nConsCount = 0;
		}
	}

	cout << "Case #" << data.lineNumber << ": " << output << endl;
	ofs <<  "Case #" << data.lineNumber << ": " << output << endl;
}

void MainFunc( ifstream& ifs ,  ofstream& ofs )
{
	string lineBuf;
	vector<string> splittedLineBuf;
	vector<long double> splittedLineNums;
	int lineCount = 0;
	int Tcount = 0;
	while(ifs) {
		splittedLineBuf.clear();
		lineBuf.clear();
		splittedLineNums.clear();

		if( !getline(ifs, lineBuf) ) {
			break;
		}
		split( lineBuf , ' ' , splittedLineBuf );
		
		//for each( const string& out in splittedLineBuf ) {
		//	long long llInput = _atoi64(out.c_str());
		//	long double ld = llInput;
		//	splittedLineNums.push_back( ld );
		//	cout << setprecision(32) << ld << "/";
		//}
		//cout << endl;

		if( lineCount == 0 ) {
			Tcount = StringToNumber<int>( lineBuf );
			lineCount++;
			continue;
		}
		else {
			InputDataSet data;
			data.lineNumber = lineCount;
			data.name = splittedLineBuf[0];
			data.n = StringToNumber<int>( splittedLineBuf[1].c_str() );
			Calc( data , ofs );
			lineCount++;
		}

	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	if( argc > 3 || argc == 1 ) {
		cout << "invalid args" << endl;
		return -1;
	}

	ifstream ifs( argv[1] );
	ofstream ofs( OUTPUT_FILENAME );

	MainFunc( ifs , ofs );

	ifs.close();
	ofs.close();

	cout << "enter any key ..." << endl;
	char in;
	cin.get(in);

	return 0;
}

