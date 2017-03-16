
#include "stdafx.h"

#include <stdlib.h>
#include <math.h>

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <map>

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

struct TestData {
	long A;
	long B;
	long K;
};

struct InputDataSet {
	int T;
	vector<TestData> vecData;
};

void Resolve( InputDataSet& data , ofstream& ofs ) 
{
	long long output = 0;

	//cout << "Input (" << data.lineNumber << ") " << data.name << " n=" << data.n << endl;

	for( int i = 0; i < data.vecData.size() ; i++ ) {
		TestData test = data.vecData.at(i);
		
		//memset( ans , 0 , test.R*test.C );

		cout << "T:" << i << endl;
		cout << "A:" << test.A
			<< "B:" << test.B
			<< "K:" << test.K
			<< endl;

		int nAns = 0;
		for( int j = 0 ; j < test.A ; j++ ) {
			for( int k = 0 ; k < test.B ; k++ ) {
				if( ((j & k) < test.K) /*&& (0 != (j & k))*/ ) {
					nAns++;
				}
			}
		}


		cout << "Case #" << i+1 << ": "
			<< nAns
			<< endl;
		ofs << "Case #" << i+1 << ": "
			<< nAns
			<< endl;
		//ofs << fixed << setprecision(7) 
		//	<< "Case #" << i+1 << ": " 
		//	<< timeTotalPrev << endl;

		// test bad magician
		//cout << "Case #" << i+1 << ": " <<  "Bad magician!" << endl;
		//ofs << "Case #" << i+1 << ": " <<  "Bad magician!" << endl;

	}

	//cout << "Case #" << data.lineNumber << ": " << output << endl;
	//ofs <<  "Case #" << data.lineNumber << ": " << output << endl;
}

void ParseInput( ifstream& ifs ,  ofstream& ofs )
{
	InputDataSet inputData;

	string lineBuf;
	vector<string> splittedLineBuf;
	vector<long> splittedLineNums;

	int lineCount = 0;
	int Tcount = 0;
	TestData testData;
	TestData testDataEmpty = {};

	while(ifs) {
		splittedLineBuf.clear();
		lineBuf.clear();
		splittedLineNums.clear();

		if( !getline(ifs, lineBuf) ) {
			cout << "eof" << endl;
			break;
		}
		split( lineBuf , ' ' , splittedLineBuf );
		
		if( lineCount == 0 ) {
			Tcount = StringToNumber<int>( lineBuf );
			inputData.T = Tcount;
		}
		else  {
			testData.A = StringToNumber<long>( splittedLineBuf[0] );
			testData.B = StringToNumber<long>( splittedLineBuf[1] );
			testData.K = StringToNumber<long>( splittedLineBuf[2] );

			inputData.vecData.push_back( testData );
			testData = testDataEmpty;
		}

		lineCount++;
	}

	Resolve( inputData , ofs );

}

int _tmain(int argc, _TCHAR* argv[])
{
	if( argc > 3 || argc == 1 ) {
		cout << "invalid args" << endl;
		return -1;
	}

	ifstream ifs( argv[1] );
	ofstream ofs( OUTPUT_FILENAME );

	ParseInput( ifs , ofs );

	ifs.close();
	ofs.close();

	cout << "enter any key ..." << endl;
	char in;
	cin.get(in);

	return 0;
}

