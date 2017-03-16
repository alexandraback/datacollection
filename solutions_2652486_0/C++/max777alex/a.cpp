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
#define TASK "C-small-1-attempt0"
//----------------------------------------------------------

struct ans
{
	int r[3];
	ans(int a, int b, int c)
	{
		r[0] = a;
		r[1] = b;
		r[2] = c;
	}
	ans(){}
};

int n, m, k;
int a[12];
vector<ans> res;

bool ok(int r[])
{
	bool was[7] = {0};
	for(int i = 0; i < (1 << n); ++i)
	{
		int t = 1;
		for(int j = 0; j < n; ++j)
			if(i & (1 << j)) t *= r[j];
		for(int j = 0; j < k; ++j)
			if(t == a[j]) was[j] = 1;
	}
	for(int i = 0; i < k; ++i)
		if(!was[i]) return 0;
	return 1;
}

void solve(int test)
{
	res.clear();
	for(int j = 0; j < k; ++j)
		scanf("%d", &a[j]);
	for(int i = 2; i < m + 1; ++i)
	{
		if(n == 1)
		{
			int r[1] = {i};
			if(ok(r)) 
				res.pb(ans(i, 0, 0));
			continue;
		}
		for(int j = 2; j < m + 1; ++j)
		{
			if(n == 2)
			{
				int r[2] = {i, j};
				if(ok(r))
					res.pb(ans(i, j, 0));
				continue;
			}
			for(int l = 2; l < m + 1; ++l)
			{
				int r[3] = {i, j, l};
				if(ok(r))
					res.pb(ans(i, j, l));
			}
		}
	}
	/*for(int i = 0; i < sz(res); ++i)
	{
		for(int j = 0; j < n; ++j)
			cerr << res[i].r[j];
		cerr << endl;
	}
	cerr << "----------------" << endl;*/
	int ind = rand() % sz(res);
	for(int i = 0; i < n; ++i)
		printf("%d", res[ind].r[i]);
	puts("");
}

int main()
{
    freopen(TASK ".in", "r", stdin);
	freopen(TASK ".out", "w", stdout);
	srand(int(time(0)));
	int test;
	cin >> test;
	puts("Case #1:");
	cin >> test >> n >> m >> k;
	for(int i = 0; i < test; ++i)
		solve(i);
	return 0;
}