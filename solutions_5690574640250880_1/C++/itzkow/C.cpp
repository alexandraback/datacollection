#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long LL;


ifstream fin ("C:\\CodeJam\\2014\\Qualifications\\C\\C-large.in");
ofstream fout ("C:\\CodeJam\\2014\\Qualifications\\C\\C-large.out");

int testCase = 0;

char BOARD[50][50] = {0};


void Solve()
{
	int i,j,k;
	
	int R,C,M;

	fout << "Case #" << testCase << ":"<<endl; 

	fin>>R>>C>>M;

	int L = R*C-M;
	
	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			BOARD[i][j] = '*';
		}
	}

	BOARD[0][0] = 'c';
	if (L == 1) {
		goto printSolution;
	}
	if (R == 1) {
		for (i = 1; i < L; i++) {
			BOARD[0][i] = '.';
		}
		goto printSolution;
	}
	if (C == 1) {
		for (i = 1; i < L; i++) {
			BOARD[i][0] = '.';
		}
		goto printSolution;
	}
	if (R == 2) {
		if (L % 2 == 1 || L == 2) {
			fout<<"Impossible"<<endl;
			return;
		}
		BOARD[1][0] = '.';
		for (i = 1; i < L/2; i++) {
			BOARD[0][i] = '.';
			BOARD[1][i] = '.';
		}
		goto printSolution;

	}	
	if (C == 2) {
		if (L % 2 == 1 || L == 2) {
			fout<<"Impossible"<<endl;
			return;
		}
		BOARD[0][1] = '.';
		for (i = 1; i < L/2; i++) {
			BOARD[i][0] = '.';
			BOARD[i][1] = '.';
		}
		goto printSolution;
	}



	if (L == 2 || L == 3 || L == 5 || L == 7) {
		fout<<"Impossible"<<endl;
		return;
	}
	if (L % 2 == 0) {
		BOARD[0][1] = '.';
		BOARD[1][0] = '.';
		BOARD[1][1] = '.';
		L -= 4;
	} else {
		BOARD[0][1] = '.';
		BOARD[0][2] = '.';
		BOARD[1][0] = '.';
		BOARD[1][1] = '.';
		BOARD[1][2] = '.';
		BOARD[2][0] = '.';
		BOARD[2][1] = '.';
		BOARD[2][2] = '.';
		L -= 9;
	}

	if (L == 0)
		goto printSolution;

	for (i = 0; i < C; i++) {
		if (BOARD[0][i] == '*') {
			BOARD[0][i] = '.';
			BOARD[1][i] = '.';
			L -= 2;
		}
		if (L == 0)
			goto printSolution;
	}

	for (i = 2; i < R; i++) {
		for (j = 0; j < C; j++) {
			
			if (BOARD[i][j] == '*') {
				BOARD[i][j] = '.';
				L --;
			}
			if (L == 0) {

				if (j == 0) {
					BOARD[i-1][C-1] = '*';
					BOARD[i][1] = '.';
				}
				goto printSolution;

			}

		}
	}






printSolution:
	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			fout << BOARD[i][j];
		}
		fout<<endl;
	}
	

}




void main()
{

	fout.precision(15);
	cout.precision(15);
	

	int TestCases = 0;
	fin>>TestCases;

	for (testCase = 1; testCase <= TestCases; testCase++) {
		
		Solve();

	}

	cout<<"finished"<<endl;
	getchar();

}



