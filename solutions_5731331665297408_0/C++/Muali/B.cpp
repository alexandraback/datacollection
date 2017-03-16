#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

bool c[250];
bool used[51];
vector<pair<int, int>> G[51];

int dfs(int v, int pos, vector<int>& seq)
{
	used[v] = true;
	if (pos >= seq.size())
	{
		for (int i = 0; i < G[v].size(); ++i)
		{
			int u = G[v][i].first;
			if (!used[u])
				dfs(u, pos, seq);
		}
	}
	else
	{
		for (int i = 0; i < G[v].size(); ++i)
		{
			int u = G[v][i].first;
			if (u == seq[pos])
			{
				pos = dfs(v, dfs(u, pos + 1, seq), seq);
				break;
			}
		}
	}
	return pos;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < 51; ++i)
		G[i].clear();
	vector<pair<int, int>> v;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		v.push_back(make_pair(tmp, i));
	}
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a, --b;
		G[a].push_back(make_pair(b, i));
		G[b].push_back(make_pair(a, i));
	}
	sort(v.begin(), v.end());
	string ans = to_string(v[0].first);
	int root = v[0].second;
	v.erase(v.begin());
	vector<int> seq;
	for (int i = 1; i < n; ++i)
	{
		for (int k = 0; k < v.size(); ++k)
		{
			seq.push_back(v[k].second);
			for (int j = 0; j < n; ++j)
				used[j] = false;
			dfs(root, 0, seq);
			bool ok = true;
			for (int j = 0; j < n; ++j)
			{
				if (!used[j])
					ok = false;
			}
			if (ok)
			{
				ans += to_string(v[k].first);
				v.erase(v.begin() + k);
				break;
			}
			else
			{
				seq.pop_back();
			}
		}
	}
	cout << ans;
}

void main()
{
	freopen("i.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}
	

}