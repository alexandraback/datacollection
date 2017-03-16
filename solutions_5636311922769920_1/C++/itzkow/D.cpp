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


ifstream fin ("C:\\CodeJam\\2016\\Qualifications\\D\\D-large.in");
ofstream fout ("C:\\CodeJam\\2016\\Qualifications\\D\\D-large.out");

int testCase = 0;

/*

who are you stop looking i dont like you

for (int i = 0; i < N; i++)
for (int j = 0; j < N; j++)
for (int k = 0; k < N; k++)

std::sort(A, A + N, std::less<int>());

vector.erase(vector.begin()+i);

*/

int K,C,S;

void Solve()
{

	fin>>K>>C>>S;

	fout << "Case #" << testCase << ": ";
	if (S * C < K)
	{
		fout<<"IMPOSSIBLE"<<endl;
		return;
	}
	FOR(i,0,S-1)
	{
		ULL sum = 0; 
		FOR(j,C*i,C*i+C-1)
		{
			int jj = min(j,K-1);
			sum *= K;
			sum+= jj;
		}
		fout<<sum+1<<" ";
		if (C*i+C-1>=K-1)
			break;
	}
	fout<<endl;


	//fout << "Case #" << testCase << ": "<<"Yes"<<endl;

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



