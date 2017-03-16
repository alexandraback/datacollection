#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <iomanip>
#include <ctime>
#include <iostream>
#include <sstream>
#include <deque>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
template<class T> inline T sqr(T a) {return a * a;}
#define INF 123456789
#define MOD 1000000007
#define PRIME 1103
#define TEST "C-small-attempt2"
#define EPS 1e-6

vector<pair<int, int64> > a, b;
int n, m;

int64 f(int i1, int i2, int64 q1, int64 q2)
{
	if(i1 == n || i2 == m) return 0;
	int64 res = 0;
	if(a[i1].first == b[i2].first)
	{
		res = min(q1, q2);
		q1 -= res;
		q2 -= res;
		if(!q1 && !q2)
			return res + f(i1 + 1, i2 + 1, a[i1 + 1].second, b[i2 + 1].second);
		if(!q1)
			return res + f(i1 + 1, i2, a[i1 + 1].second, q2);
		return res + f(i1, i2 + 1, q1, b[i2 + 1].second);
	}
	return max(f(i1 + 1, i2, a[i1 + 1].second, q2), f(i1, i2 + 1, q1, b[i2 + 1].second));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen(TEST ".in", "r", stdin);
	freopen(TEST ".out", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for(int test = 1; test <= t; ++test)
	{
		scanf("%d%d", &n, &m);
		a.resize(n + 1);
		b.resize(m + 1);
		for(int i = 0; i < n; ++i)
		{
			int type;
			int64 q;
			scanf("%lld%d", &q, &type);
			a[i] = make_pair(type, q);
		}
		for(int i = 0; i < m; ++i)
		{
			int type;
			int64 q;
			scanf("%lld%d", &q, &type);
			b[i] = make_pair(type, q);
		}
		a[n] = make_pair(0, 0);
		b[m] = make_pair(0, 0);
		int64 res = f(0, 0, a[0].second, b[0].second);

		printf( "Case #%d: %lld\n", test, res);
	}
	return 0;
}