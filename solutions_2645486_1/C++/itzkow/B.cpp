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


ifstream fin ("C:\\CodeJam\\Round1\\B\\B-large.in");
ofstream fout ("C:\\CodeJam\\Round1\\B\\B-large.out");

long long testCase = 0;
long long V[10002] = {0};
long long RES[10002] = {0};

long long E,R,N;

void Do(long long a, long long b)
{
	if (a == b)
		return;
	long long i;
	long long maxv,maxi;
	maxi = a;
	maxv = V[a];
	for (i = a+1; i <= b; i++) 
	{
		if (V[i] > maxv) {
			maxv = V[i];
			maxi = i;
		}
	}
	
	if (a == maxi) {
		RES[a+1] = max(RES[b+1]-R*((b+1)-(a+1)), R);
		Do(a+1,b);
		return;
	}

	RES[maxi] = min(E,  (maxi-a)*R+RES[a]);
	Do(a,maxi-1);
	Do(maxi,b);




}

void Solve()
{
	

	fin>>E>>R>>N;

	long long i;
	memset(V, 0, sizeof(V));
	memset(RES, -1, sizeof(RES));
	for(i = 0; i < N; i++)
		fin>>V[i];

	
	RES[0] = E;
	RES[N] = R;
	Do(0,N-1);
	long long s = 0;
	for (i = 0; i < N; i++) {
		s+=(RES[i]-RES[i+1]+R)*V[i];
	}




	fout << "Case #" << testCase << ": "<<s<<endl;

}






void main()
{

	fout.precision(15);
	cout.precision(15);
	

	long long TestCases = 0;
	fin>>TestCases;

	for (testCase = 1; testCase <= TestCases; testCase++) {
		
		Solve();

	}

	cout<<"finished"<<endl;
	getchar();

}



