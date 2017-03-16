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
#define TEST "A-large"
#define EPS 1e-6

int n;
vector<vector<int> > g;
bool was[1000][1000] = {0};
int64 d[1000][1000] = {0};


int64 dfs(int x, int v)
{
	if(was[x][v]) return d[x][v];
	if(x == v) return 1; 
	int64 res = 0;
	for(int i = 0; i < (int)g[x].size(); ++i)
	{
		int to = g[x][i];
		res += dfs(to, v);
	}
	was[x][v] = 1;
	return d[x][v] = res;
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
		scanf("%d", &n);
		g.assign(n, vector<int>(0));
		for(int i = 0; i < n; ++i)
		{
			int m;
			scanf("%d", &m);
			for(int j = 0; j < m; ++j)
			{
				int v;
				scanf("%d", &v);
				--v;
				g[i].push_back(v);
			}
		}
		bool found = 0;
		memset(was, 0, sizeof was);
		memset(d, 0, sizeof d);
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if(i == j) continue;
				int64 val = dfs(i, j);
				if(val >= 2)
				{
					found = 1;
					break;
				}
			}
			if(found) break;
		}
		printf("Case #%d: ", test); 
		if(found) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}