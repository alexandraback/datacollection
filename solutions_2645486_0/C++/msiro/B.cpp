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

vector<int> v;
int E,R,N;

vector<vector<int>> memo;

int calc( int vi, int energy )
{
	int r = 0;
	if( vi >= N )
		return 0;

	int tmp;

	energy += R;
	if( energy > E )
		energy = E;

	for( int e = energy; e >= 0; e-- ){
//		if( memo[vi+1][e] >= 0 ){
	//		tmp = (energy-e) * v[vi] + memo[vi+1][e];
	//	}else{
			tmp = (energy-e) * v[vi] + calc( vi+1, e );
	//	}
		r = max( r, tmp );
	}

	memo[vi][energy] = r;
	return r;
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
		fin >> E;
		fin >> R;
		fin >> N;
		v.assign(N,0);
		memo.assign(N+1,vector<int>(E+1,-1));
		for( int i = 0; i < N; i++ ){
			fin >> v[i];
		}

		int ans = calc( 0, E );
		
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