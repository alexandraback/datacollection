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
		int K,L,S;
		fin >> K;
		fin >> L;
		fin >> S;
		vector<char> KBD(K);
		for( int i = 0; i < K; i++ ){
			fin >> KBD[i];
		}
		vector<char> TGT(L);
		for( int i = 0; i < L; i++ ){
			fin >> TGT[i];
		}

		vector<int> IDX(S, 0);
		int cnt = 0;
		int total_pay = 0;
		int max_pay = 0;
		while(1){
			int pay = 0;

			for( int i = 0; i <= (S-1)-(L-1); i++ ){
				bool bNotPay = false;
				for( int j = 0; j < L; j++ ){
					if( KBD[IDX[i+j]] != TGT[j] ){
						bNotPay = true;
						break;
					}
				}
				if( bNotPay == false )
					pay++;
			}

			total_pay += pay;
			if( pay > max_pay ){
				max_pay = pay;
			}
			cnt++;

			int f = S-1;
			{
carry:
				if( IDX[f] == K-1 ){
					if( f == 0 )
						break;
					IDX[f] = 0;
					f--;
					goto carry;
				}else{
					IDX[f]++;
				}
			}
		}

		double ans = (double)max_pay - (double)total_pay / (double)cnt;

	/////////////////////////////
		fprintf(fout,"Case #%d: %lf\n", test_case, ans);
		if( fin.eof() ){
			if( test_case != CASE ){
				OUTPUTLOG( "in-file error:eof" );
			}
			break;
		}
	}

	OUTPUTLOG( "program end" );
}