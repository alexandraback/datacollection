#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

char tmp[32];
int n, m;
vector<int> g[64];
string la[64];

string ans;

int stop;
int st[64];
int can_pop[64];

int left[64];
int ins[64];

int sd[64];

bool us[64];

void dfs(int st)
{
	if (left[st] || us[st])
		return;
	us[st] = 1;
	for (int i = 0; i < (int) g[st].size(); ++i)
	{
		dfs(g[st][i]);
	}
}

bool can_reach(int st)
{
	memset(us, 0, sizeof(us));
	dfs(st);
	for (int i = 1; i <= n; i++)
	{
		if (left[i] == 0 && us[i] == 0)
			return false;
	}
	return true;
}

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; ++t)
	{
		scanf("%d %d", &n, &m);
		ans = "";
		for (int i = 0; i <= n; ++i)
		{
			g[i].clear();
			la[i] = "";
		}
		for (int i = 1; i <= n; ++i)
		{
			scanf("%s", tmp);
			la[i] = tmp;
		}

		for (int i = 1; i <= m; ++i)
		{
			int j, k;
			scanf("%d %d", &j, &k);
			g[j].push_back(k);
			g[k].push_back(j);
		}

		int bi = 1;
		for (int i = 1; i <= n; ++i)
		{
			if (la[i] < la[bi])
				bi = i;
		}

		memset(left, 0, sizeof(left));
		memset(ins, 0, sizeof(ins));
		memset(sd, -1, sizeof(sd));
		
		ans = la[bi];
		stop = 1;
		st[stop] = bi;
		ins[bi] = 1;
		int rest = n - 1;
		sd[bi] = 1;
		while (rest > 0)
		{
			memset(can_pop, 0, sizeof(can_pop));
			for (int i = stop; i > 0; --i)
			{
				left[st[i]] = 1;
				if (can_reach(bi))
				{
					can_pop[i] = 1;
				}
			}
			for (int i = stop; i > 0; --i)
				left[st[i]] = 0;

			int bne = 0;
			for (int i = stop; i > 0; --i)
			{
				int v = st[i];
				for (int j = 0; j < (int) g[v].size(); ++j)
				{
					//~ printf("NEI %d %d __ %d %d\n", v, g[v][j], left[g[v][j]], ins[g[v][j]]);
					if (!left[g[v][j]] && !ins[g[v][j]])
					{
						if (bne == 0 || la[g[v][j]] < la[bne])
							bne = g[v][j];
					}
				}
				if (!can_pop[i])
					break;
			}
			//~ printf("NE %d %d\n", st[stop], bne);
			if (left[bne] || ins[bne])
			{
				//~ printf("ERROR! BLOCKED STATE! %d %d %d\n", st[stop], stop, bne);
				break;
			}

			int bs = st[1];
			for (int i = 0; i < (int) g[bne].size(); ++i)
			{
				int u = g[bne][i];
				if (ins[u] && sd[u] > sd[bs])
				{
					bs = u;
				}
			}

			while (st[stop] != bs)
			{
				left[st[stop]] = 1;
				ins[st[stop]] = 0;
				--stop;
			}
			ans += la[bne];
			st[++stop] = bne;
			sd[bne] = sd[st[stop-1]] + 1;
			ins[bne] = 1;
			--rest;
		}

		printf("Case #%d: %s\n", t, ans.c_str());
	}
	return 0;
}
