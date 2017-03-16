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


ifstream fin ("A-large.in");
ofstream fout ("A-large.out");

int testCase = 0;

/*

who are you stop looking i dont like you

std::sort(A, A + N, std::less<int>());

vector.erase(vector.begin()+i);

*/

char S[2001];
char *C[]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int A[]={0,8,6,2,7,5,9,4,1,3};
int M[30];
int CC[10];

void Solve()
{

	fin>>S;

	//FOR(i, 'A', 'Z')
	{

	}
	fout << "Case #" << testCase << ": ";
	ZERO(M);
	ZERO(CC);

	FOR(i, 0, strlen(S)-1)
	{
		M[S[i]-'A']++;
	}
	FOR(ii, 0, 9)
	{
		int i = A[ii];
		bool possible = true;
		while (possible)
		{
			int k;
			FOR(j,0,strlen(C[i])-1)
			{
				if (M[C[i][j]-'A'] > 0)
				{
					M[C[i][j]-'A']--;
				}
				else
				{
					k = j-1;
					possible = false;
					break;
				}
			}
			if(possible)
			{
				CC[i]++;
				//fout<<(char)('0'+i);
			}
			else
			{
				FOR(j,0,k)
				{
					M[C[i][j]-'A']++;
				}
			}
		}
	}
	FOR(i,0,9)
	{
		FOR(j,0,CC[i]-1)
		{
			fout<<(char)('0'+i);
		}
	}
	fout<<endl;

	FOR(i, 'A','Z')
	{
		if (M[i-'A'] != 0)
			cout<<"ERROR"<<endl;
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



