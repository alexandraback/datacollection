#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

long long mod = 1000000000 + 7;

char s[104][104];
int len[104];
int n;

int one[35];
vector<int> cnt[36][3];

vector<int> g[105];
bool u[105];


int dfs(int v, int p = -1)
{
	u[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		if (!u[g[v][i]])
		{
			if (dfs(g[v][i], v))
				return 1;
		}
		else if (g[v][i] != p)
			return 1;
	}
	return 0;
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int t;
	scanf("%d", &t);

	for (int tt = 0; tt < t; tt++)
	{
		memset(s, 0, sizeof(s));
		for (int i = 0; i < 105; i++)
			g[i].clear();
		for (int i = 0; i < 35; i++)
			for (int j = 0; j < 3; j++)
				cnt[i][j].clear();
		memset(u, 0, sizeof(u));
		memset(one, 0, sizeof(one));

		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%s", s[i]), len[i] = strlen(s[i]);

		bool bad = 0;

		for (int i = 0; i < n; i++)
		{
			int le = 0, ri = len[i] - 1;
			while (le < len[i] && s[i][le] == s[i][0])
				le++;
			while (ri >= 0 && s[i][ri] == s[i][len[i] - 1])
				ri--;
			int id = le;
			while (id <= ri)
			{
				int cur = id;
				while (s[i][id] == s[i][cur])
					id++;
				one[s[i][cur] - 'a'] ++;
			}
			if (le <= ri && s[i][0] == s[i][len[i] - 1])
				bad = 1;
		}

		for (int i = 0; i < n; i++) {
			if (one[s[i][0] - 'a'] > 0 || one[s[i][len[i] - 1] - 'a'] > 0)
				bad = 1;
		}
		for (int i = 0; i < 35; i++) {
			if (one[i] > 1)
				bad = 1;
		}

		if (bad)
		{
			printf("Case #%d: 0\n", tt + 1);
			continue;
		}

		for (int i = 0; i < n; i++)
		{
			int c1 = s[i][0], c2 = s[i][len[i] - 1];
			if (c1 == c2)
				cnt[c1 - 'a'][2].push_back(i);
			else
			{
				cnt[c1 - 'a'][0].push_back(i);
				cnt[c2 - 'a'][1].push_back(i);
			}
		}

		for (int i = 0; i < 35; i++)
		{
			if (cnt[i][0].size() > 1 || cnt[i][1].size() > 1)
				bad = 1;
		}
		if (bad)
		{
			printf("Case #%d: 0\n", tt + 1);
			continue;
		}

		for (int i = 0; i < 35; i++)
		{
			vector<int> pos;
			if (cnt[i][1].size() > 0)
				pos.push_back(cnt[i][1][0]);
			for (int j = 0; j < cnt[i][2].size(); j++)
				pos.push_back(cnt[i][2][j]);
			if (cnt[i][0].size() > 0)
				pos.push_back(cnt[i][0][0]);

			for (int i = 1; i < pos.size(); i++)
				g[pos[i]].push_back(pos[i - 1]), g[pos[i - 1]].push_back(pos[i]);
		}

		int comp = 0;
		for (int i = 0; i < n; i++)
		{
			if (!u[i])
			{
				comp++;
				if (dfs(i))
					bad = 1;
			}
		}
		if (bad)
		{
			printf("Case #%d: 0\n", tt + 1);
			continue;
		}

		long long ans = 1;
		for (int i = 2; i <= comp; i++)
			ans = (ans * i) % mod;

		for (int i = 0; i < 35; i++)
		{
			for (int j = 2; j <= cnt[i][2].size(); j++)
				ans = (ans * j) % mod;
		}
		printf("Case #%d: %lld\n", tt + 1, ans);
	}
	

	return 0;
}