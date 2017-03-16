#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define LIM 100
int graph[LIM][LIM], cnt[LIM], path[LIM];
int vis[LIM];
int main()
{
	int t, i, n, m, x, flag;
	scanf("%d",&t);
	for(int tc=1; tc<=t; tc++)
	{
		scanf("%d",&n);
		flag=0;
		memset(graph,0,sizeof(graph));
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		for(i=0; i<n; i++)
		{
			scanf("%d",&m);
			for(int j=0; j<m; j++)
			{
				scanf("%d",&x);
				graph[i][x-1]=1;
				cnt[i]++;
			}
		}
		for(i=0; i<n; i++)
		{
			memset(path,0,sizeof(path));
			memset(vis,0,sizeof(vis));
			path[1]=1;
			vis[i]=1;
			queue<int> Q;
			Q.push(i);
			while(!Q.empty())
			{
				int cur=Q.front();
				Q.pop();
				for(int j=0; j<n; j++)
				if(graph[j][cur]==1)
				{
					if(vis[j]==1)	flag=1;
					else {
					vis[j]=1;
					Q.push(j);
					path[j]+=path[cur];
					}
				}
			}
		}
		printf("Case #%d: ",tc);
		if(flag==1)
		printf("Yes\n");
		else
		printf("No\n");
	}
	return 0;
}
