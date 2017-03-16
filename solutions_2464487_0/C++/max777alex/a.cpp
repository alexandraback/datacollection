#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#include <functional>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>
#include <queue>
#include <list>
#include <memory.h>
#include <complex>
using namespace std;
#pragma comment(linker, "/STACK:256000000")
#define mp make_pair
#define pb push_back
#define all(C) (C).begin(), (C).end()
#define sz(C) (int)(C).size()
#define PRIME 1103
#define INF (1 << 20)
#define MOD 7340033
#define FAIL ++*(int*)0
#define EPS 1e-9
template<class T> T sqr(T a) {return a * a;} 
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<int64> vi64;
typedef vector<pii> vpii;
typedef vector<vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vector<pair<int, int > > > vvpii;
typedef complex<long double> cd;
#define TASK "A-small-attempt0"
//----------------------------------------------------------

int64 r, t;

bool ok(int64 n)
{
	if(r > (1ll << 62) / n) return 0;
	return (2 * r + 1 + 2 * (n - 1)) * n <= t;
}

void solve(int test)
{
	cin >> r >> t;
	int64 res = 0;
	int64 L = 1, R = 1ll << 30;
	while(L <= R)
	{
		int64 m = (L + R) >> 1;
		if(ok(m))
		{
			res = m;
			L = m + 1;
		}
		else R = m - 1;
	}

	printf("Case #%d: %lld\n", test + 1, res);
}

int main()
{
    freopen(TASK ".in", "r", stdin);
	freopen(TASK ".out", "w", stdout);
	int test;
	cin >> test;
	for(int i = 0; i < test; ++i)
		solve(i);
	return 0;
}