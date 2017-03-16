/*
ID: dixtosa1
PROG: milk2
LANG: C++11
*/
#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <string>
//#include <string.h>
#include <list>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <sstream>
#include <assert.h>
#include <functional> //std::greater<int>
//#include <tuple>

//#include "Biginteger.cpp"
//#include "sqrt.cpp"
//#include "tree.cpp"
//#include "funcs.cpp"

typedef long long ll;
typedef std::pair<ll, ll> pii;
#define ALL(x)           (x).begin(), (x).end()
#define forn(N)          for(long long i = 0; i < (long long)N; i++)
#define fornj(N)         for(long long j = 0; j < (long long)N; j++)
#define fornk(N)         for(long long k = 0; k < (long long)N; k++)
#define foreach(c,itr)   for(auto itr=(c).begin();itr!=(c).end();itr++)
#define PI 3.1415926535897932384626433
#define LINF (1LL<<60)
#define INF (1<<30)
#define awesome vector<int> A(N); forn(N) scanf("%d", &A[i]);
#define v vector
#define File "Patterns"
using namespace std;

ll M, B,N;
int mat[60][60];

void aage(int x)
{
	forn(x)
	{
		for (int j = i + 1; j < x; j++)
		{
			mat[i][j] = 1;
		}
	}
}
ll mypow(ll x, ll a)
{
	ll ans = 1;
	forn(a)
		ans *= x;
	return ans;
}
int main()
{
#if defined(_DEBUG) || defined(_RELEASE)
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(File".in", "r", stdin); freopen(File".out", "w", stdout);
#endif

	int T; cin >> T;
	for (int test = 1; test <= T; test++)
	{
		cin >> B >> M;


		for (N = 2; N <= B; N++)
		{
			if (mypow(2, N - 2) >= M)
			{
				cout << "Case #"<< test << ": " << "POSSIBLE\n";

				forn(B) {
					fornj(B)
					{
						mat[i][j] = 0;
					}
				}

				aage(N - 1);
				

				ll K =  M;

				if (mypow(2, N - 2) == M)
				{
					forn(N - 1)
						mat[i][B - 1] = 1;
				}
				else
				{

					int ind = 1;
					while (K > 0)
					{
						if (K % 2 == 1)
						{
							mat[ind][B - 1] = 1;
						}
						K /= 2;
						ind++;
					}
				}

				forn(B) {
					fornj(B)
					{
						cout << mat[i][j];
					}
					cout << endl;
				}

				break;
			}
		}
		if (N > B)
			cout << "Case #" << test << ": " << "IMPOSSIBLE\n";
	}
	//printf("\n\ntime-%.3lf", clock()*1e-3);
	return 0;
}