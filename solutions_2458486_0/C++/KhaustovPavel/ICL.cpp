#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <algorithm>
#include <cstdio>
#include <ctime>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <iostream>
#include <cmath>
#include <sstream>
#include <complex>
#include <memory.h>

using namespace std;

#pragma comment(linker, "/STACK:64000000")

typedef long long int64;
typedef unsigned long long uint64;

#define y1 _dsfkjdsfksdj
#define y0 _sfsdkfdop

typedef unsigned uint;
typedef vector<int64> vi64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<int64,int64> pii64;
typedef pair<int,pii> piii;
typedef pair<pii,pii> piiii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef pair<double,int> pdi;
typedef pair<double,double> pdd;

int nt;
int n, m;
int key[20];
map <int, int> a;
vvi g;
int f[1 << 20];
int p[1 << 20];

inline void init()
{
	a.clear();
	g.clear();
	int x;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &x);
		a[x]++;
	}
	g.resize(n);
	for (int i = 0; i < n; ++i)
	{
		int K;
		scanf("%d%d", &key[i], &K);
		for (int j = 0; j < K; ++j)
		{
			scanf("%d", &x);
			g[i].push_back(x);
		}
	}
}

int rec(int mask)
{
	if (f[mask] != -1) return f[mask];
	
	if (mask + 1 == (1 << n)) return f[mask] = 1;

	map <int, int> b = a;
	for (int i = 0; i < n; ++i)
	{
		if (mask & (1 << i))
		{
			b[key[i]]--;
			for (int j = 0; j < (int)g[i].size(); ++j)
				b[g[i][j]]++;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (mask & (1 << i)) continue;
		if (!b[key[i]]) continue;
		int cur = rec(mask | (1 << i));
		if (!cur) continue;
		p[mask] = i;
		return f[mask] = 1;
	}

	return f[mask] = 0;
}

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	scanf("%d", &nt);
	++nt;
	for (int tn = 1; tn < nt; ++tn)
	{
		cerr << tn << endl;
		init();

		memset(f, -1, sizeof f);

		int cur = rec(0);
		if (!cur)
		{
			printf("Case #%d: IMPOSSIBLE\n", tn);
			continue;
		}

		printf("Case #%d:", tn);
		int mask = 0;
		while (mask + 1 != (1 << n))
		{
			printf(" %d", p[mask] + 1);
			mask |= (1 << p[mask]);
		}
		printf("\n");
	}

    return 0;
}