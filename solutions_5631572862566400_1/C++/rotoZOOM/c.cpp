#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define in_str(b) scanf("%s",(b))
#define in_int1(a) scanf("%d",&(a))
#define in_int2(a,b) scanf("%d%d",&(a),&(b))
#define in_int3(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
#define in_int4(a,b,c,d) scanf("%d%d%d%d",&(a),&(b),&(c),&(d))
#define so(a) sort((a).begin(), (a).end())
#define rso(a) sort((a).rbegin(), (a).rend())
#define mp(a,b) make_pair(a,b)
#define mset(a,n) memset(a,n,sizeof(a))
#define readints(mas,n) for (int _i=0;_i<(n);_i++) in_int1((mas)[_i])
#define readdoubles(mas,n) for (int _i=0;_i<(n);_i++) scanf("%lf", &(mas)[_i])
#define unq(src) src.erase(unique((src).begin(), (src).end()), (src).end())
#define MOD 1000000007
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

int mas[1010];
int step[1010];
int used[1010];

int go(int u, int s)
{
	if (used[u]) return 0;
	if (step[u] > 0)
	{
		// found loop
		used[u] = 1;
		int ans = s - step[u];
		return ans;
	}
	
	step[u] = s;
	int ans = go(mas[u], s + 1);
	used[u] = 1;
	return ans;
}

vector<int> adj[1010];

int dfs(int u)
{
	int best = 0;
	for (int i = 0; i < adj[u].size(); i++)
	{
		int ret = dfs(adj[u][i]);
		best = max(best, ret);
	}

	return best + 1;
}

void Solve()
{
	int i, j, k, n, m;

	int tests;
	in_int1(tests);
	for (int test = 1; test <= tests; test++)
	{
		in_int1(n);
		
		readints(&mas[1], n);
		mset(step, 0);
		mset(used, 0);
		int best = 0;
		for (i = 1; i <= n; i++)
		{
			if (!used[i])
			{
				int ret = go(i, 1);
				best = max(best, ret);
			}
		}

		int total = 0;
		for (i = 1; i <= n; i++) adj[i].clear();

		for (i = 1; i <= n;i++)
		{
			adj[mas[i]].push_back(i);
		}

		mset(used, 0);
		for (i = 1; i <= n; i++)
		{
			if (mas[mas[i]] == i && i < mas[i])
			{
				int u = mas[i];

				int bb = 0;
				int ret = 2;

				// found double
				for (j = 0; j < adj[i].size(); j++)
				{
					if (adj[i][j] == u) continue;
					int r = dfs(adj[i][j]);
					bb = max(bb, r);
				}
				ret += bb;

				bb = 0;
				for (j = 0; j < adj[u].size(); j++)
				{
					if (adj[u][j] == i) continue;
					int r = dfs(adj[u][j]);
					bb = max(bb, r);
				}
				ret += bb;
				total += ret;
			}
		}

		best = max(best, total);
		printf("Case #%d: %d", test, best);
		printf("\n");
	}
}

int main()
{
#ifdef __LOCAL_RUN__
#define _MAX_BUF_SIZE 32
	FILE *res_output = freopen("output.txt", "wt", stdout);
	FILE *res_input = freopen("input.txt", "rt", stdin);
	Solve();
#else
	Solve();
#endif
	return 0;
}