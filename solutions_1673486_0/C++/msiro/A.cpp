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
		int A, B;
		fin >> A;
		fin >> B;
		vector<double> p(A);
		FOR( i, 0, A )
			fin >> p[i];

		int l = B-A;
		double opt = 10000000;

		int n = 1;
		FOR( i, 0, A )
			n *= 2;
		vector<double> pp(n, 1.0);
		FOR( i, 0, n ){
			FOR( j, 0, A ){
				if( i & (1<<((A-1)-j)) ){
					pp[i] *= (1-p[j]);
				}else{
					pp[i] *= p[j];
				}
			}
		}

		double t;
		if( A == 1 ){
			//keep
			opt = pp[0] * (l+1) + (1-pp[0]) * ((l+1)+B+1);

			// once
			t = 1 + B + 1;
			if( t < opt ) opt = t;
		}else if( A == 2 ){
			//keep
			opt = pp[0] * (l+1) + (1-pp[0]) * ((l+1)+B+1);

			// once
			t = (pp[0]+pp[1]) * (1+(l+1)+1) + (pp[2]+pp[3]) * (1+(l+1)+1+B+1);
			if( t < opt ) opt = t;

			// twice
			t = 2+(l+2)+1;
			if( t < opt ) opt = t;
		}else{
			// keep
			opt = pp[0] * (l+1) + (1-pp[0]) * ((l+1)+B+1);

			// once
			t = (pp[0]+pp[1]) * (1+(l+1)+1) + (1-(pp[0]+pp[1])) * (1+(l+1)+1+B+1);
			if( t < opt ) opt = t;

			// twice
			t = (pp[0]+pp[1]+pp[2]+pp[3]) * (2+(l+2)+1) + (1-(pp[0]+pp[1]+pp[2]+pp[3])) * (2+(l+2)+1+B+1);
			if( t < opt ) opt = t;

			// third
			t = 3+(l+3)+1;
			if( t < opt ) opt = t;
		}
		t = 1+B+1;
		if( t < opt ) opt = t;

	/////////////////////////////
		fprintf(fout,"Case #%d: %lf\n", test_case, opt);
		if( fin.eof() ){
			if( test_case != CASE ){
				OUTPUTLOG( "in-file error:eof" );
			}
			break;
		}
	}

	OUTPUTLOG( "program end" );
}