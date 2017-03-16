
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
#include <algorithm>

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
	long N;
	vector<string> cars;
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

		cout << "T:" << i
			<< " N:" << test.N
			<< " cars:";
		for( int j = 0 ; j < test.N ; j++ ) {
			cout << test.cars[j] << " ";
		}
		cout
			<< endl;

		 std::vector<int> data;
		// [0, 1, 2, ....]というサイズnの配列を作成
		for(int j=0; j<test.N; ++j){
			data.push_back(j);
		}

		int count = 0;

		// 全ての順列を出力
		do{
			//std::cout << "[ " << test.cars[data[0]];
			//for(unsigned int j=1; j<data.size(); ++j){
				//std::cout << ", " << test.cars[data[j]];
			//}
			//std::cout << " ]" << std::endl;


			if( test.N == 1 ) {
				//cout << "] " <<  endl;
				continue;
			}

			
			{
				string str1 = test.cars[data[0]];
				string str2 = test.cars[data[1]];
				if( str1.back() != str2.front() ) {
					//cout << "] " <<  endl;
					continue;
				}
			}
			// 最後の接続
			{
				string str1 = test.cars[data[data.size()-2]];
				string str2 = test.cars[data[data.size()-1]];
				if( str1.back() != str2.front() ) {
					//cout << "] " <<  endl;
					continue;
				}
			}

			bool valid = true;
			for(unsigned int j=1; j<data.size()-1; ++j){
				string str1 = test.cars[data[j-1]];
				string str2 = test.cars[data[j]];
				string str3 = test.cars[data[j+1]];

				if( ( str1.back() != str2.front() ) &&
					( str2.back() != str3.front() ) ) {
					valid = false;
					break;
				}
			}

			if( valid ) {
				//cout << "] valid" << endl;
				count++;
			}
			else {
				//cout << "] " <<  endl;
			}

		}while(next_permutation(data.begin(), data.end()));

		cout << "Case #" << i+1 << ": "
			<< count
			<< endl;
		ofs << "Case #" << i+1 << ": "
			<< count
			<< endl;

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

		//	//cout << "kenWinDeceitful:" << nKenWinCountDeceitful << endl;


		//	cout << "Case #" << i+1 << ": "
		//		<< test.N - nKenWinCountDeceitful << " "
		//		<< test.N - nKenWinCountNormal
		//		<< endl;
		//	ofs << "Case #" << i+1 << ": "
		//		<< test.N - nKenWinCountDeceitful << " "
		//		<< test.N - nKenWinCountNormal
		//		<< endl;
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
	TestData testDataEmpty;

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
		else if( lineCount % 2 == 1 ) {
			testData.N = StringToNumber<long>( lineBuf );
		}
		else if( lineCount % 2 == 0 ) {
			//	for( int i = 0 ; i < testData.N ; i++ ) {
			//		testData.Naomi.push_back( StringToNumber<double>( splittedLineBuf[i] ) );
			//	}
			//}
			//else if( lineCount % 3 == 0 ) {
			//	for( int i = 0 ; i < testData.N ; i++ ) {
			//		testData.Ken.push_back( StringToNumber<double>( splittedLineBuf[i] ) );
			//	}

			for( int i = 0 ; i < testData.N ; i++ ) {
				testData.cars.push_back( splittedLineBuf[i] );
			}

			inputData.vecData.push_back( testData );
			testData.N = 0;
			testData.cars.clear();
			//testData = testDataEmpty;
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

