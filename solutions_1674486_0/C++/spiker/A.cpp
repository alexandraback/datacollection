#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
vector<vector<int> > gr;
int used[1005];
int Q[20000];
int kl, kq;
int dfs(int v)
{
	kl = 0;
	kq = 1;
	Q[0] = v;
	used[v] = 1;
	while (kl != kq)
	{
		int u = Q[kl++];
		for (int i = 0 ; i < gr[u].size(); i++)
		{
			if (used[gr[u][i]])
				return 1; else
			{
				Q[kq++] = gr[u][i];
				used[gr[u][i]] = 1;
			}
		}
	}
	return 0;
}
int main(void)
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for (int q = 1 ; q<= t; q++)
	{
		int n;
		scanf("%d",&n);
		gr.clear();
		gr.resize(n);
		for (int i = 0 ; i < n; i++)
		{
			int x;
			scanf("%d",&x);
			for (int j = 0 ; j < x; j++)
			{
				int a;
				scanf("%d",&a);
				a--;
				gr[i].push_back(a);
			}
		}
		int res = 0;
		printf("Case #%d: ",q);
		for (int i = 0 ; i < n; i++)
		{
			memset(used,0,sizeof(used));

			res |= dfs(i);
			if (res)
				break;
		}
		if (res)
			printf("Yes\n"); else
			printf("No\n");
	}
	return 0;
}