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
typedef unsigned long long ULL;
typedef long double LD;

#define FOR(i,s,e) for (int i = s; i <= e; i++)
#define FORR(i,e,s) for (int i = e; i >= s; i--)
#define ZERO(ARR) memset(ARR,0,sizeof(ARR));


ifstream fin ("C-small-attempt0.in");
ofstream fout ("C-small-attempt0.out");

int testCase = 0;

/*

who are you stop looking i dont like you

std::sort(A, A + N, std::less<int>());

vector.erase(vector.begin()+i);

*/


int N;
char WA[1001][21];
char WB[1001][21];
bool REAL[16];

void Solve()
{

	fin>>N;

	FOR(i,0,N-1)
	{
		fin>>WA[i];
		fin>>WB[i];
	}

	int BL = 0;

	FOR(K, 0, 65536-1)
	{
		int X=K;
		FOR(i, 0, N-1)
		{			
			REAL[i] = X%2;
			X/=2;
		}
		
		bool pos = true;
		FOR(i, 0, N-1)
		{
			if (!REAL[i])
			{
				bool AOK = false;
				bool BOK = false;
				FOR(j, 0, N-1)
				{
					if (REAL[j])
					{
						if (strcmp(WA[i],WA[j]) == 0)
							AOK = true;
						if (strcmp(WB[i],WB[j]) == 0)
							BOK = true;
					}
				}
				if (!AOK || !BOK)
					pos = false;
			}
		}
		if (pos)
		{
			int L=0;
			FOR(i, 0, N-1)
				if (!REAL[i])
					L++;
			BL=max(L,BL);
		}

	}




	fout << "Case #" << testCase << ": "<<BL<<endl;

}




void main()
{

	fout.precision(15);
	cout.precision(15);
	

	int TestCases = 0;
	fin>>TestCases;

	for (testCase = 1; testCase <= TestCases; testCase++) {
		
		Solve();
		if (testCase == 1+TestCases/20) {
			cout<<"5%"<<endl;
		} else if (testCase == 1+TestCases/4) {
			cout<<"25%"<<endl;
		} else if (testCase == 1+2*TestCases/4) {
			cout<<"50%"<<endl;
		} else if (testCase == 1+3*TestCases/4) {
			cout<<"75%"<<endl;
		}

	}

	cout<<"100%"<<endl;
	cout<<"finished"<<endl;
	getchar();

}



