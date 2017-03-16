
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
	long long P;
	long long Q;
};

struct InputDataSet {
	int T;
	vector<TestData> vecData;
};

// 最大公約数を求める関数
long long gcd(long long a, long long b)
{
	while(a != b) {
		if (a < b) b -= a;
		else a-= b;
	}
	return a;
}

void Resolve( InputDataSet& data , ofstream& ofs ) 
{
	long long output = 0;

	//cout << "Input (" << data.lineNumber << ") " << data.name << " n=" << data.n << endl;

	for( int i = 0; i < data.vecData.size() ; i++ ) {
		TestData test = data.vecData.at(i);
		
		//memset( ans , 0 , test.R*test.C );

		cout << "T:" << i 
			<< " P:" << test.P
			<< " Q:" << test.Q
			<< endl;

		long long max = 1LL << 40;

		long long yaku = 1;
		if( test.P <= 256 ) {
		//if( 0 ){
			for( int n = 256 ; n > 0 ; n-- ) {
				if( test.P % (long long)n == 0 ) {
					if( test.Q % (long long)n == 0 ) {
						yaku = n;
						break;
					}
				}
			}
		} 
		else {
			yaku = gcd( test.Q , test.P );
		}
		long long waru = test.Q;
		waru /= yaku;

		long long bunsi = test.P / yaku;

		long long rest = max % waru;

		cout << "max:" << max
			<< " yaku:" << yaku
			<< " waru:" << waru
			<< " Rest:" << rest 
			<< endl;

		if( rest != 0 ) {
			cout << "Case #" << i+1 << ": "
				<< "impossible"
				<< endl;
			ofs << "Case #" << i+1 << ": "
				<< "impossible"
				<< endl;
		}
		else {
			double pq = (double)bunsi / waru;
			cout << "pq:" << pq << endl;
			int resultGen = 0;
			for( int gen = 1 ; gen <= 40 ; gen++ ) {
				double testGen = 1.0 / (double)( 1LL << gen );
				if( pq >= testGen ) {
					resultGen = gen;
					break;
				}
			}
			cout << "Case #" << i+1 << ": "
				<< resultGen
				<< endl;
			ofs << "Case #" << i+1 << ": "
				<< resultGen
				<< endl;
		}

	//	map<double,double> mKen;
	//	map<double,double> mNaomi;

	//	for( int j = 0 ; j < test.N ; j++ ) {
	//		//cout << fixed << setprecision(5) 
	//		//	<< test.Naomi[j] << " ";
	//		mNaomi.insert( map<double,double>::value_type(test.Naomi[j],test.Naomi[j]) );
	//	}
	////	cout << endl;
	//	for( int j = 0 ; j < test.N ; j++ ) {
	//		//cout << fixed << setprecision(5) 
	//		//	<< test.Ken[j] << " ";
	//		mKen.insert( map<double,double>::value_type(test.Ken[j],test.Ken[j]) );
	//	}
	////	cout << endl;

	//	map<double,double>::iterator it;
	//	for( it = mNaomi.begin() ; it != mNaomi.end() ; ++it ) {
	//		//cout << fixed << setprecision(5) 
	//		//	<< it->second << " ";
	//	}
	////	cout << endl;
	//	for( it = mKen.begin() ; it != mKen.end() ; ++it ) {
	//		//cout << fixed << setprecision(5) 
	//		//	<< it->second << " ";
	//	}
	////	cout << endl;

	//	int nKenWinCountNormal = 0;
	//	map<double,double> mNaomiWork = mNaomi;
	//	map<double,double> mKenWork = mKen;

	//	map<double,double>::reverse_iterator rit;
	//	for( rit = mNaomi.rbegin() ; rit != mNaomi.rend() ; ++rit ) {

	//		map<double,double>::iterator it2;
	//		it2 = mKenWork.begin();
	//		for( it2 ; it2 != mKenWork.end() ; ++it2 ) {
	//			if( it2->second > rit->second ) {
	//				nKenWinCountNormal++;
	//				mKenWork.erase( it2 );
	//				break;
	//			}
	//		}
	//	}
	//	//cout << endl;

	//	//cout << "kenWin:" << nKenWinCountNormal << endl;

	//	int nKenWinCountDeceitful = 0;
	//	mKenWork = mKen;
	//	for( it = mNaomi.begin() ; it != mNaomi.end() ; ++it ) {
	//		map<double,double>::iterator it2;
	//		it2 = mKenWork.begin();
	//		if( it2->second > it->second ) {
	//			// 相手の一番弱いwaitよりも軽かったら必ず負ける
	//			nKenWinCountDeceitful++;
	//			// しかし、一番重いウェイトをなくすことができる。
	//			map<double,double>::reverse_iterator it3 = mKenWork.rbegin();
	//			mKenWork.erase( it3->first );
	//		}
	//		else {
	//			// 相手の一番弱いウェイトはこちらの一番弱いウェイトで勝てる（重ければ）
	//			mKenWork.erase( it2->first );
	//		}
	//	}

		//cout << "kenWinDeceitful:" << nKenWinCountDeceitful << endl;


		//cout << "Case #" << i+1 << ": "
		//	<< endl;
		//ofs << "Case #" << i+1 << ": "
		//	<< endl;
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
		split( lineBuf , '/' , splittedLineBuf );
		
		if( lineCount == 0 ) {
			Tcount = StringToNumber<int>( lineBuf );
			inputData.T = Tcount;
		}
		else {
			testData.P = StringToNumber<long long>( splittedLineBuf[0] );
			testData.Q = StringToNumber<long long>( splittedLineBuf[1] );

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

