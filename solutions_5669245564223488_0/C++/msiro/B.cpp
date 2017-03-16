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

bool valid( string& s )
{
	for( int c = 0; c < s.size(); ){
		int last = c;
		bool bSame = true;
		for( int p = c+1; p < s.size(); p++ ){
			if( bSame ){
				if( s[c] != s[p] ){
					bSame = false;
					last = p;
				}
			}else{
				if( s[c] == s[p] )
					return false;
			}
		}
		if( bSame )
			return true;
		c = last;
	}

	return true;
}

void main(int argc, char*argv[]) // usage: main.exe in.txt out.txt
{
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
		int N;
		fin >> N;
		vector<string> car(N);
		for( int i = 0; i < N; i++ ){
			fin >> car[i];
			string::iterator it = unique(car[i].begin(), car[i].end());
			car[i].erase(it, car[i].end());
		}

		vector<int> p(N);
		for( int i = 0; i < N; i++ ){
			p[i] = i;
		}

		int ans = 0;
		do{
			string s;
			for( int i = 0; i < N; i++ )
				s += car[p[i]];

			if( valid(s) )
				ans++;

		}while( next_permutation( p.begin(), p.end()) );

	/////////////////////////////
		fprintf(fout,"Case #%d: %d\n", test_case, ans);
		OUTPUTLOG("xxx\n");
		if( fin.eof() ){
			if( test_case != CASE ){
				OUTPUTLOG( "in-file error:eof" );
			}
			break;
		}
	}

	OUTPUTLOG( "program end" );
}