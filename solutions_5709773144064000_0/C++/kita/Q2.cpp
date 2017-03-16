
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

struct TestData {
	double C;
	double F;
	double X;
};

struct InputDataSet {
	int T;
	vector<TestData> vecData;
};

void Calc( InputDataSet& data , ofstream& ofs ) 
{
	long long output = 0;

	//cout << "Input (" << data.lineNumber << ") " << data.name << " n=" << data.n << endl;

	for( int i = 0; i < data.vecData.size() ; i++ ) {
		TestData test = data.vecData.at(i);
		//vector<double> spendTimeList;
		double timeTotalPrev = 10000000.0;
		double timeTotal = timeTotalPrev-1;
		double timeToC = 0.0;
		double g = 2.0;
		double maxTotal = test.X / g;
		cout << fixed << setprecision(7) 
			<< "T:" << i << " Input " << test.C << " " << test.F << " " << test.X  << endl;
		cout << "T:" << i << " Max " << maxTotal << endl;
		int retCount = 0;
		while( timeTotalPrev > timeTotal ) {
			timeTotalPrev = timeTotal;

			if( timeTotal == 0.0 ) {
				timeTotal = test.X / g;
				timeToC = test.C / g;
			}
			else {
				timeTotal = timeToC + test.X / g;
				timeToC += test.C / g;
			}
			//spendTimeList.push_back(timeTotal);
			//cout << "RetCount:" << retCount 
			//	<< " g:" << g
			//	<< "  Time: " << timeTotal << "(" << test.X / g << ") "
			//	<< "  TimePrev: " << timeTotalPrev 
			//	<< "  TimeC: " << timeToC  << "(" << test.C / g << ") "
			//	<< endl;

			g += test.F;		
			retCount++;
		}

		cout << fixed << setprecision(7) 
			<< "Case #" << i+1 << ": " 
			<< timeTotalPrev << endl;

		ofs << fixed << setprecision(7) 
			<< "Case #" << i+1 << ": " 
			<< timeTotalPrev << endl;

		// test bad magician
		//cout << "Case #" << i+1 << ": " <<  "Bad magician!" << endl;
		//ofs << "Case #" << i+1 << ": " <<  "Bad magician!" << endl;

	}

	//cout << "Case #" << data.lineNumber << ": " << output << endl;
	//ofs <<  "Case #" << data.lineNumber << ": " << output << endl;
}

void MainFunc( ifstream& ifs ,  ofstream& ofs )
{
	InputDataSet inputData;

	string lineBuf;
	vector<string> splittedLineBuf;
	vector<long> splittedLineNums;

	int lineCount = 0;
	int Tcount = 0;
	TestData testData;

	while(ifs) {
		splittedLineBuf.clear();
		lineBuf.clear();
		splittedLineNums.clear();

		if( !getline(ifs, lineBuf) ) {
			cout << "eof" << endl;
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
			inputData.T = Tcount;
		}
		else {
			if( splittedLineBuf.size() < 3 ) {
				continue;
			}

			testData.C = StringToNumber<double>( splittedLineBuf[0] );
			testData.F = StringToNumber<double>( splittedLineBuf[1] );
			testData.X = StringToNumber<double>( splittedLineBuf[2] );
			
			inputData.vecData.push_back( testData );
			memset( &testData , 0 , sizeof(testData) );
		}

		lineCount++;
	}

	Calc( inputData , ofs );

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

