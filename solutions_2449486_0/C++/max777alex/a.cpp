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
#define TASK "B-small-attempt0"


int n, m;
int a[100][100];

void init()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			scanf("%d", &a[i][j]);
}

void solve(int test) 
{
	vi rmin(m, INF);
	vi rmax(m, 0);
	vi cmin(n, INF);
	vi cmax(n, 0);
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cmin[i] = min(cmin[i], a[i][j]);
			cmax[i] = max(cmax[i], a[i][j]);
			rmin[j] = min(rmin[j], a[i][j]);
			rmax[j] = max(rmax[j], a[i][j]);
		}
	}
	printf("Case #%d: ", test);
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(a[i][j] < cmax[i] && a[i][j] < rmax[j])
			{
				puts("NO");
				return;
			}
		}
	}
	puts("YES");
}

int main() 
{
#ifndef ONLINE_JUDGE
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif
	int test;
	cin >> test;
	for(int i = 0; i < test; ++i)
	{
		init();
		solve(i + 1);
	}
    return 0;
}