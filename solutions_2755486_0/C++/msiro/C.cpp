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
		int N;
		fin >> N;

		vector<int> d(N);
		vector<int> n(N);
		vector<int> w(N);
		vector<int> e(N);
		vector<int> s(N);
		vector<int> d_d(N);
		vector<int> d_p(N);
		vector<int> d_s(N);
		for( int i = 0; i < N; i++ ){
			fin >> d[i];
			fin >> n[i];
			fin >> w[i];
			fin >> e[i];
			fin >> s[i];
			fin >> d_d[i];
			fin >> d_p[i];
			fin >> d_s[i];
		}

		vector<int> wall(1000,0);
		vector<int> wall_c(1000,0);
		int offset = 500;

		int comp_trib = 0;
		int success = 0;

		int day;
		int attack_trib;
		while( comp_trib < N ){
			day = INT_MAX;
			for( int i = 0; i < N; i++ ){
				if( n[i] == 0 )
					continue;
				if( d[i] < day ){
					day = d[i];
				}
			}

			for( attack_trib = 0; attack_trib < N; attack_trib++ ){
				if( n[attack_trib] == 0 )
					continue;
				if( d[attack_trib] == day ){
					bool bIncrease = false;
					for( int pos = w[attack_trib] +  offset; pos <= e[attack_trib]-1 + offset; pos++ ){
						if( wall[pos] < s[attack_trib] ){
							bIncrease = true;
							wall_c[pos] = max( wall_c[pos], s[attack_trib] );
						}
					}
					if( bIncrease ){
						success++;
					}

					d[attack_trib] += d_d[attack_trib];
					n[attack_trib]--;
					if( n[attack_trib] == 0 ){
						comp_trib++;
					}
					w[attack_trib] += d_p[attack_trib];
					e[attack_trib] += d_p[attack_trib];
					s[attack_trib] += d_s[attack_trib];
				}
			}

			copy( wall_c.begin(), wall_c.end(), wall.begin() );
		}


	/////////////////////////////
		fprintf(fout,"Case #%d: %d\n", test_case, success);
		if( fin.eof() ){
			if( test_case != CASE ){
				OUTPUTLOG( "in-file error:eof" );
			}
			break;
		}
	}

	OUTPUTLOG( "program end" );
}