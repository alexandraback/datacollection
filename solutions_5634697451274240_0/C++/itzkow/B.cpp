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
typedef long double LD;

#define FOR(i,s,e) for (int i = s; i <= e; i++)
#define FORR(i,e,s) for (int i = e; i >= s; i--)


ifstream fin ("C:\\CodeJam\\2016\\Qualifications\\B\\B-small-attempt0.in");
ofstream fout ("C:\\CodeJam\\2016\\Qualifications\\B\\B-small-attempt0.out");

int testCase = 0;

/*

who are you stop looking i dont like you

for (int i = 0; i < N; i++)
for (int j = 0; j < N; j++)
for (int k = 0; k < N; k++)

std::sort(A, A + N, std::less<int>());

vector.erase(vector.begin()+i);

*/

char A[200];
char B[200];

void Solve()
{

	fin>>A;
	int L = strlen(A);

	int sum = 0;
	while(true)
	{
		int l = -1;
		FORR(i,L-1,0)
		{
			if (A[i] == '-')
			{
				l=i;
				break;
			}
		}
		if (l == -1)
			break;
		if (A[0] == '+')
		{
			FOR(i,0,L)
			{
				l = i;
				if (A[i] == '-')
					break;
			}
			l--;
			FOR(i,0,l)
			{
				B[i] = A[l-i];
			}
			FOR(i,0,l)
			{
				if (B[i] == '+')
					A[i] = '-';
				else
					A[i] = '+';
			}

		}
		else
		{
			FOR(i,0,l)
			{
				B[i] = A[l-i];
			}
			FOR(i,0,l)
			{
				if (B[i] == '+')
					A[i] = '-';
				else
					A[i] = '+';
			}
		}
		sum++;
	}




	fout << "Case #" << testCase << ": "<<sum<<endl;

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



