#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <complex>
#include <random>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int MAXN = 1005;
int T, N;
vector<pair<int, int> > adj[MAXN];
int vis[MAXN];
vector<int> cycle;
int a1, a2;
int sz;

void dfs(int cur, int idx)
{
	if (vis[cur] == 1) //found cycle
	{
		for (int i = 0; i < cycle.size(); i++)
			if (cycle[i] == cur)
			{
				sz = (int)cycle.size() - i;
				if (sz == 2)
				{
					a1 = cycle[i];
					a2 = cycle[i + 1];
				}
				break;
			}
		return;
	}

	vis[cur] = 1;
	cycle.push_back(cur);

	for (int i = 0; i < adj[cur].size(); i++)
	{
		int next = adj[cur][i].first;
		if (vis[next] == 2 || adj[cur][i].second == idx)
			continue;
		dfs(next, adj[cur][i].second);
	}

	cycle.pop_back();
	vis[cur] = 2;
}

int go2(int cur, int bad, int prev)
{
	int ret = 0;
	for (int i = 0; i < adj[cur].size(); i++)
	{
		int next = adj[cur][i].first;
		if (next == bad || next == prev)
			continue;
		ret = max(ret, go2(next, bad, cur));
	}
	return ret + 1;
}

int go()
{
	int ans = 0, cnt = 0;
	for (int i = 1; i <= N; i++)
		if (vis[i] == 0)
		{
			cycle.clear();
			dfs(i, 0);
			if (sz >= 3)
				ans = max(ans, sz);
			else if (sz == 2)
				cnt += go2(a1, a2, 0) + go2(a2, a1, 0);
		}

	return max(ans, cnt);
}

int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	ios::sync_with_stdio(0);

	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		for (int i = 0; i < MAXN; i++)
			adj[i].clear();
		memset(vis, 0, sizeof(vis));

		cin >> N;
		for (int i = 1, f; i <= N; i++)
		{
			cin >> f;
			adj[i].push_back(make_pair(f, i));
			adj[f].push_back(make_pair(i, i));
		}

		cout << "Case #" << t << ": " << go() << "\n";
	}

	return 0;
}