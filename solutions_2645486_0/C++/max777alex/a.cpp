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
#pragma comment(linker, "/STACK:1024000000")
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
#define TASK "B-small-attempt1"
//----------------------------------------------------------


int E, R, n;
int a[1 << 17];
int dp[10][6];

int f(int ind, int e)
{
	if(ind == n || e < 0) return 0;
	if(dp[ind][e] != -1) return dp[ind][e];
	int res = 0;
	for(int i = 0; i < e + 1; ++i)
		res = max(res, f(ind + 1, min(e - i + R, E)) + a[ind] * i);
	return dp[ind][e] = res;
}

void solve(int test)
{
	scanf("%d%d%d", &E, &R, &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	memset(dp, -1, sizeof dp);
	int res = f(0, E);
	printf("Case #%d: %d\n", test + 1, res);
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