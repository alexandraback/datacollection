#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, N, val;
vector <int> inherits[1000];
int order[1000], tsort[1000], dp[1000][1000];
bool seen[1000];

void dfs(int v)
{
	for(int w=0; w<inherits[v].size(); w++)
		if(order[inherits[v][w]]==-1)
			dfs(inherits[v][w]);
	order[v]=val++;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for(int t=1; t<=T; t++)
	{
		scanf("%d", &N);
		for(int n=0; n<N; n++)
		{
			inherits[n].clear();
			int Mi;
			scanf("%d", &Mi);
			for(int m=0; m<Mi; m++)
			{
				int inherit_from;
				scanf("%d", &inherit_from);
				inherits[n].push_back(inherit_from-1);
			}
		}
		fill(order, order+N, -1);
		val = 0;
		for(int v=0; v<N; v++)
			if(order[v]==-1)
				dfs(v);
		for(int v=0; v<N; v++)
			tsort[order[v]] = v;
		fill(seen, seen+N, false);
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				dp[i][j] = 0;
		bool diamond = false;
		for(int v=N-1; v>=0; v--)
			for(int w=0; w<inherits[tsort[v]].size(); w++)
			{
				dp[tsort[v]][inherits[tsort[v]][w]]++;
				for(int prev=N-1; prev>v; prev--)
					if(dp[tsort[prev]][tsort[v]])
					{
						dp[tsort[prev]][inherits[tsort[v]][w]]++;
						if(dp[tsort[prev]][inherits[tsort[v]][w]]>1)
							diamond = true;
					}
			}
		printf("Case #%d: %s\n", t, diamond ? "Yes" : "No");
	}
	return 0;
}