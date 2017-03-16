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


const int NN = 1000001;
int A[NN];


ifstream fin ("C:\\CodeJam\\2015\\1B\\A\\A-small-attempt1.in");
ofstream fout ("C:\\CodeJam\\2015\\1B\\A\\A-small-attempt1.out");

int testCase = 0;

/*

who are you stop looking i dont like you

for (int i = 0; i < N; i++)
for (int j = 0; j < N; j++)
for (int k = 0; k < N; k++)

std::sort(A, A + N, std::less<int>());

vector.erase(vector.begin()+i);

*/

LL swap(LL x)
{
	LL new_num = 0;
    while(x > 0)
    {
            new_num = new_num*10 + (x % 10);
            x = x/10;
    }
    return new_num;
}

LL f(LL N)
{
	
	if (N==0)
		return 0;
	if (N==1)
		return 1;

	int c = 0;
	LL M = N;
	while (M)
	{
		M /= 10;
		c++;
	}

	LL pp = ((LL)pow((LD)10,int(c/2)));

	if (N%pp)
	{
		LL sum = N%pp+swap(N/pp);
		LL Ne = ((LL)pow((LD)10,c-1));
		return min(N-Ne,sum)+f(Ne-1)+1;
	} else {
		LL Ne = ((LL)pow((LD)10,c-1));
		LL sum = pp+swap(N/pp-1);
		return min(N-Ne,sum)+f(Ne-1)+1;
	}
}

LL f2(LL N)
{
	
	if (A[N] != -1)
		return A[N];

	if (N==1)
		return 1;
	if (N%10 != 0 && swap(N) < N) {
		A[N] = min(1+f2(swap(N)),f2(N-1)+1);
		return A[N];
	}
	A[N] = f2(N-1)+1;
	return A[N];
}

void Solve()
{

	LL N;
	fin>>N;
	



	fout << "Case #" << testCase << ": "<<f(N)<<endl;

}




void main()
{
	
	for (int i = 0; i < NN; i++)
		A[i] = -1;
	
	//for (int i = 0; i < NN; i++)
	//	A[i] = f2(i);

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



