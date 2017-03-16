// FairAndSquare.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "vector"
#include "string"
#include "set"
#include "sstream"
#include "algorithm"
#include "cmath"
#include "cassert"
#include "iostream"
#include <fstream>
using namespace std;

#define int64 long long

int _tmain(int argc, _TCHAR* argv[])
{
	/*stringstream stream;
	for (int64 i = 1; i < 100000000; i++ )
	{
		
		stream << i;
	

		string str = stream.str();
		string revString = str;
		reverse(revString.begin(), revString.end());

		stream.str( std::string() );
		stream.clear();

		if (revString == str )
		{
			int64 sq = i*i;
			
			stream << sq;
			string strSq = stream.str();
			string revStringSq = strSq;
			reverse(revStringSq.begin(), revStringSq.end());
			if (revStringSq == strSq )
			{
				
				//cout << str << endl;
				cout << strSq << ",";
				
			}

			stream.str( std::string() );
			stream.clear();
		}
	}*/

	int64 allNum[48]= {1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004,100000020000001,100220141022001,102012040210201,102234363432201,121000242000121,121242363242121,123212464212321,123456787654321,400000080000004};
	ofstream fout("out.txt");
	ifstream fin("in.txt");
	int T;
	fin >> T;
	for (int t = 0; t < T; ++t)
	{
		int64 a;
		int64 b;
		fin >> a >> b;
		int count = 0;
		for (int i = 0; i < 48; ++i)
		{
			if (a <= allNum[i]  && allNum[i] <= b)
			{
				count++;
			}
		}
		fout << "Case #" << t + 1 << ": " << count << endl;

	}
	return 0;
}

