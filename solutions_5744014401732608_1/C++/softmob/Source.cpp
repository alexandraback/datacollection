#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdint>
#include <algorithm>
using namespace std;

struct graph
{
	vector<vector<int> > g;
	vector< char > used;
	vector< int64_t > dp;
	int s = 0;
	void dfs(int v)
	{
		used[v] = true;
		int64_t sum = v == s;
		for (int i = 0; i < (int)g[v].size(); ++i)
		{
			int to = g[v][i];
			if (!used[to])
			{
				dfs(to);
			}
			sum += dp[to];
		}
		dp[v] = sum;
	}
};

void solve(int num_test)
{
	int n;
	cin >> n;
	int64_t m;
	cin >> m;
	graph g;
	g.g.resize(n);
	g.used.resize(n);
	g.s = n - 1;
	g.dp.resize(n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			g.g[i].push_back(j);
		}
	}
	g.dfs(0);	
	vector<bool> ans(n);
	for (int i = 1; i < n; ++i)
	{
		if (m >= g.dp[i])
		{
			m -= g.dp[i];
			ans[i] = true;
		}
	}
	cout << "Case #" << num_test << ": ";
	if (m != 0)
	{
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	cout << "POSSIBLE" << endl;
	vector<vector<int> > gr(n, vector<int>( n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < (int)g.g[i].size(); ++j)
		{
			int to = g.g[i][j];
			gr[i][to] = 1;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (!ans[i])
			gr[0][i] = 0;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << gr[i][j];
		}
		cout << endl;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		solve(i+1);
	}
	return 0;
}