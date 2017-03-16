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
		int P, Q;
		char d;
		fin >> P;
		fin >> d;
		fin >> Q;

		int pa = P;
		while(1){
			if( (pa&1) == 0 )
				pa /= 2;
			else break;
		}
		int qa = Q;
		while(1){
			if( (qa&1) == 0 )
				qa /= 2;
			else break;
		}
		if( qa != 1 ){
			if( pa % qa != 0 ){
				fprintf(fout,"Case #%d: impossible\n", test_case);
				continue;
			}
		}

		double v = (double)P/(double)Q;
		int ans = 1;
		double c = 0.5;
		while(1){
			if( v >= c-(1e-5) )
				break;
			c /= 2.0;
			ans++;
		}

	/////////////////////////////
		fprintf(fout,"Case #%d: %d\n", test_case, ans);
		if( fin.eof() ){
			if( test_case != CASE ){
				OUTPUTLOG( "in-file error:eof" );
			}
			break;
		}
	}

	OUTPUTLOG( "program end" );
}