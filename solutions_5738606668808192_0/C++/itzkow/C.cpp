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


ifstream fin ("C:\\CodeJam\\2016\\Qualifications\\C\\C-small-attempt1.in");
ofstream fout ("C:\\CodeJam\\2016\\Qualifications\\C\\C-small-attempt1.out");

int testCase = 0;

/*

who are you stop looking i dont like you

for (int i = 0; i < N; i++)
for (int j = 0; j < N; j++)
for (int k = 0; k < N; k++)

std::sort(A, A + N, std::less<int>());

vector.erase(vector.begin()+i);

*/


int A[33];
int B[11];
int N,J;
std::set<LL> was;

int mod(int b, int k)
{
	int sum = 0;
	FOR(i,0,N-1)
	{
		if (A[i] == 0)
			continue;
		int mul = 1;
		FOR(j,0,i-1)
		{
			mul *= b%k;
			mul %= k;
		}
		sum += mul;
		sum = sum%k;
	}
	return sum%k;
}

void Solve()
{
	fin>>N>>J;
	fout << "Case #1:" <<endl;
	FOR(i,0,N-1)
	{
		A[i] = 0;
	}
	int jams = 0;
	while (true)
	{
		FOR(i,0,N-1)
		{
			A[i] = rand()%2;
			//r/=2;
		}
		A[0] = 1;
		A[N-1] = 1;

		
		LL n = 0;
		FOR(i,0,N-1)
		{
			n*=2;
			n+=A[i];
		}
		if (was.find(n) != was.end())
			continue;

		bool jam = true;
		FOR(b,2,10)
		{
			bool found = false;
			FOR(k, 2,14)
			{
				if (mod(b, k) == 0)
				{
					B[b] = k;
					found = true;
					break;
				}
			}
			if (!found)
			{
				jam = false;
				break;
			}
		}
		if (jam)
		{
			was.insert(n);

			FORR(i,N-1,0)
				fout<<A[i];
			FOR(i,2,10)
				fout<<" "<<B[i];
			fout<<std::endl;
			jams++;
			if (jams == J)
				return;
			//cout<<jams<<std::endl;
		}

	}

	fout << "Case #" << testCase << ": "<<"Yes"<<endl;

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



