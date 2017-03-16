// Round1C2.cpp : Defines the entry point for the console application.
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
	int x;
	int y;
};

void Calc( InputDataSet& data , ofstream& ofs ) 
{
	string output = "";
	cout << "input " << data.x << "," << data.y << endl;
	int nX = data.x;
	int nY = data.y;
	int nCX = 0;
	int nCY = 0; 
	int nStep = 0;

	bool bTurnX = true;
	bool bDXEast = true;
	bool bDYNorth = true;
	if( nX < 0 ) {
		nX = -nX;
		bDXEast = false;
	}
	if( nY < 0 ) {
		nY = -nY;
		bDYNorth = false;
	}
	// go x WE , y NS
	while(1) {
		if( ( nCX < nX ) && ( bTurnX ) ) {
			nStep++;
			bTurnX = false;
			nCX += nStep;
			output += bDXEast ? 'E' : 'W';
		}
		else if( ( nCY < nY ) && ( !bTurnX ) ) {
			nStep++;
			bTurnX = true;
			nCY += nStep;
			output += bDYNorth ? 'N' : 'S';
		}
		else if(( nCX >= nX )&&( nCY >= nY )){
			break;
		}
		bTurnX ^= true;
	}
	// back
	while(1) {
		if( ( nCX == nX ) && ( nCY == nY ) ) {
			break;
		}
		int nL = nX - nCX;
		while( nCX > nX ) {
			nStep++;
			nCX += nStep;
			nStep++;
			nCX -= nStep;
			output += bDXEast ? "EW" : "WE";
		}
		while( nCY > nY ) {
			nStep++;
			nCY += nStep;
			nStep++;
			nCY -= nStep;
			output += bDYNorth ? "NS" : "SN";
		}
		break;
	}
	cout << "x " << nCX << "/" << nX << " y " << nCY << "/" << nY << endl; 

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
		
		for each( const string& out in splittedLineBuf ) {
			long long llInput = _atoi64(out.c_str());
			long double ld = llInput;
			splittedLineNums.push_back( ld );
			//cout << setprecision(32) << ld << "/";
		}
		cout << endl;

		if( lineCount == 0 ) {
			Tcount = (int)splittedLineNums[0];
			lineCount++;
			continue;
		}
		else {
			InputDataSet data;
			data.lineNumber = lineCount;
			data.x = (int)splittedLineNums[0];
			data.y = (int)splittedLineNums[1];
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

