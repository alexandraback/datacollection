#include<cstdio>
#include<vector>
#include<stack>

using namespace std;

int t, n, m, x;
vector<int> g[1001], pairs[1001];
stack<int> dfs;
bool used1[1001], used2[1001];
int ans;

int main()
{
	scanf("%d", &t);
	for(int c = 1; c <= t; ++c)
	{
		ans = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
		{
			g[i].clear();
			pairs[i].clear();
		}
		for(int i = 1; i <= n; ++i)
		{
			scanf("%d", &m);
			for(int j = 0; j < m; ++j)
			{
				scanf("%d", &x);
				g[i].push_back(x);
				pairs[i].push_back(x);
			}
		}
		for(int i = 1; i <= n; ++i)
		{
			for(int p = 0; p < pairs[i].size(); ++p)
			{
				for(int q = 0; q < pairs[i].size(); ++q)
					if(p != q)
					{
						dfs.push(pairs[i][p]);
						while(dfs.size()!=0)
						{
							int akt = dfs.top();
							dfs.pop();
							used1[akt]=1;
							for(int k = 0; k < g[akt].size(); ++k)
								if(used1[g[akt][k]]==0)
									dfs.push(g[akt][k]);
						}
						dfs.push(pairs[i][q]);
						while(dfs.size()!=0)
						{
							int akt = dfs.top();
							dfs.pop();
							used2[akt]=1;
							for(int k = 0; k < g[akt].size(); ++k)
								if(used2[g[akt][k]]==0)
									dfs.push(g[akt][k]);
						}
						for(int j = 1; j <= n; ++j)
						{
							if(used1[j] == 1 && used2[j] == 1)
								ans = 1;
							used1[j] = 0;
							used2[j] = 0;
						}
						if(ans == 1) break;
					}
				if(ans == 1) break;
			}
		if(ans == 1) break;
		}
		if(ans == 1)
			printf("Case #%d: Yes\n", c);
		else
			printf("Case #%d: No\n", c);
	}
}