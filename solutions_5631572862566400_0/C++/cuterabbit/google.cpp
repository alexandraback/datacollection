#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int e[100000];
int v[100000];
int d[10000];
int gain[10000];
vector<int> adj[2000];

int dfs(int i)
{
	v[i] = 1;
	int ans = 0;
	for (auto j: adj[i])
	{
		if (!v[j])
			ans = max(ans, dfs(j));
	}
	return 1 + ans;
}

int f() 
{
	int n;
	int ans = 0, ans2 = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i )
	{
		v[i] = d[i] = 0;
		adj[i].clear();
	}
	for (int i = 1; i <= n; ++i )
	{
		cin >> e[i];
		adj[e[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i )
	{
		if (!v[i] && e[e[i]]==i)
		{
			v[i] = 1;
			v[e[i]] = 1;
			ans2 += dfs(i) + dfs(e[i]);
		}
	}

	for (int i = 1; i <= n; ++i )
	{
		if (!v[i])
		{
			vector<int> tmp;
			int t = 1;
			v[i] = t;
			int x = i;
			tmp.push_back(x);
			while (true) 
			{
				int y = e[x];
				if (v[y])
				{
					ans = max(ans, t-v[y]+1);
					for (auto au: tmp) dfs(au);
					break;
				}
				else 
				{
					x = y;
					v[x] = ++t;
					tmp.push_back(x);
				}
			}
		}
	}	
	return max(ans, ans2);
}

int main() 
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int n_test;
	cin >> n_test;
	for (int i_test = 0; i_test < n_test; ++i_test) 
	{
		cout << "Case #" << i_test+1 << ": " << f() << endl;
	}
}