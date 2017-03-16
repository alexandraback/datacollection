#include <bits/stdc++.h>
using namespace std;

vector<int> adjlst[1111];
int bff[1111];
bool in_loop[1111], vis[1111];

int dfs(int nd)
{
	int d = 0;
	vis[nd] = true;
	for (int i = 0; i < adjlst[nd].size(); i++)
	{
		d = max(d, dfs(adjlst[nd][i]));
	}
	return d + 1;
}

int main()
{
	int T, N, ans, tans;
	
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", bff + i);
			adjlst[i].clear();
		}
		for (int i = 1; i <= N; i++)
		{
			adjlst[bff[i]].push_back(i);
		}
		
		memset(in_loop, false, sizeof(in_loop));
		memset(vis, false, sizeof(vis));
		
		ans = 0;
		tans = 0;
		for (int i = 1; i <= N; i++)
		{
			if (vis[i])
				continue;
			int nd = i;
			while (!vis[nd])
			{
				vis[nd] = true;
				nd = bff[nd];
			}
			assert(!in_loop[nd]);
			int loop_len = 0;
			while (!in_loop[nd])
			{
				in_loop[nd] = true;
				loop_len++;
				nd = bff[nd];
			}
			if (loop_len > 2)
			{
				int max_hgt = 0;
				for (int l = 0; l < loop_len; l++)
				{
					int hgt = 0;
					for (int j = 0; j < adjlst[nd].size(); j++)
						if (!in_loop[adjlst[nd][j]])
							hgt = max(hgt, dfs(adjlst[nd][j]));
					max_hgt += hgt;
					nd = bff[nd];
				}
				tans = max(tans, loop_len);
			}
			else
			{
				assert(loop_len == 2);
				int max_hgt = 0;
				for (int l = 0; l < loop_len; l++)
				{
					int hgt = 0;
					for (int j = 0; j < adjlst[nd].size(); j++)
						if (!in_loop[adjlst[nd][j]])
							hgt = max(hgt, dfs(adjlst[nd][j]));
					max_hgt += hgt;
					nd = bff[nd];
				}
				ans += (loop_len + max_hgt);
			}
		}
		
		printf("Case #%d: %d\n", t, max(ans, tans));
	}
	
	return 0;
}