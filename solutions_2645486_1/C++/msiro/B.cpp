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

__int64 calc( int Ps, int Pe, int Es, int Ee )
{
	if( Ps > Pe )
		return 0;
	if( Ps == Pe ){
		return (__int64)v[Ps] * (__int64)(Es - Ee);
	}

	if( Ee < 0 )
		Ee = 0;

	// max_pos <= v[Ps] - v[Pe]
	int max_pos;
	int maxv = 0;
	for( int i = Ps; i <= Pe; i++ ){
		if( v[i] > maxv ){
			maxv = v[i];
			max_pos = i;
		}
	}

	int reserve = Ee - (Pe - max_pos) * R;
	if( reserve < 0 )
		reserve = 0;
	int consume = Es + (max_pos - Ps) * R;
	if( consume > E )
		consume = E;
	consume = consume - reserve;

	return __int64(consume * maxv) + calc(Ps, max_pos-1, Es, (consume+reserve) - R ) + calc(max_pos+1, Pe, reserve+R, Ee);
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
		for( int i = 0; i < N; i++ ){
			fin >> v[i];
		}

		__int64 ans = calc( 0, N-1, E, 0 );
		
	/////////////////////////////
		fprintf(fout,"Case #%d: %I64d\n", test_case, ans);
		if( fin.eof() ){
			if( test_case != CASE ){
				OUTPUTLOG( "in-file error:eof" );
			}
			break;
		}
	}

	OUTPUTLOG( "program end" );
}