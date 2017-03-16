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
#pragma comment(linker, "/STACK:512000000")
#define mp make_pair
#define pb push_back
#define all(C) (C).begin(), (C).end()
#define sz(C) (int)(C).size()
#define PRIME 1103
#define INF (1 << 30)
#define MOD 1000000007
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
#define TASK "C-large-1"

vi64 a;

void solve(int test) 
{
	int64 l, r;
	cin >> l >> r;
	int res = 0;
	for(int i = 0; i < sz(a); ++i)
		if(a[i] >= l && a[i] <= r) 
			++res;
	printf("Case #%d: %d\n", test, res);
}

int t[20];

bool isPal(int64 a)
{
	int k = 0;
	while(a)
	{
		int r = a % 10;
		a /= 10;
		t[k++] = r;
	}
	for(int i = 0; i < k / 2; ++i)
		if(t[i] != t[k - i - 1])
			return 0;
	return 1;
}

void calc(int64 n)
{
	for(int64 i = 1; i * i <= n; ++i)
	{
		if(isPal(i) && isPal(sqr(i)))
			a.pb(sqr(i));
	}
	/*cerr << sz(a) << endl;
	for(int i = 0; i < sz(a); ++i)
		cerr << a[i] << endl;*/
}

int main() 
{
#ifndef ONLINE_JUDGE
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif
	calc(1ll << 47);

	int test;
	cin >> test;
	for(int i = 0; i < test; ++i)
	{
		solve(i + 1);
	}
    return 0;
}