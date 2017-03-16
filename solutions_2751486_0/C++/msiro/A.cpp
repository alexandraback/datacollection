#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <windows.h>

using namespace std;
#pragma warning(disable: 4996)

#define OUTPUTLOG2(X,Y)\
{\
	char msg[1024];\
	sprintf( msg, X, Y );\
	OutputDebugString(msg);\
}
#define OUTPUTLOG OutputDebugString

#define FOR(r,a,b) for(r=(a); r<(b); r++)
#define REP(r,b) for(r=0; r<(b); r++)
#define TRV(type,cnt,it) for(type::iterator it=(cnt).begin(); it!=(cnt).end(); it++)

bool isconsonants( char c ){
	if( c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' )
		return true;

	return false;
}

void main(int argc, char*argv[]) // usage: main.exe in.txt out.txt
{
	int i,j,k,l,m,n;

	ifstream fin(argv[1]);
	if( fin == NULL ){
		OUTPUTLOG2("cannot open in-file : %s\n", argv[1]);
		return;
	}
	FILE* fout = fopen(argv[2],"w");
	if( fin == NULL ){
		OUTPUTLOG2("cannot open out-file : %s\n", argv[2]);
		return;
	}

/////////////////////////////
	char line[1024];
	int CASE;
	fin >> CASE;
	for( int test_case = 1; test_case <= CASE; test_case++ ){
	/////////////////////////////

		string s;
		fin >> s;
		int n;
		fin >> n;
		__int64 L = s.length();

		int cpos = 0;
		int pcpos = -1;
		__int64 ret = 0;
		for( int pos = 0; pos <= L-n; pos++ ){
			bool bconsec = true;
			for( int check = pos; check < pos+n; check++ ){
				if( isconsonants( s[check] ) ){
					bconsec = false;
					break;
				}
			}
			if( bconsec == false )
				continue;

			cpos = pos;

			__int64 left = L - (cpos + n-1);
			__int64 right = cpos - (pcpos);
			if( right <= 0 )
				right = 1;

			ret += left * right;

			pcpos = cpos;
		}




	/////////////////////////////
		fprintf(fout,"Case #%d: %I64d\n", test_case, ret);
		if( fin.eof() ){
			if( test_case != CASE ){
				OUTPUTLOG( "in-file error:eof" );
			}
			break;
		}
	}

	OUTPUTLOG( "program end" );
}