#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int map[1005][1005];
int vis[100];
bool check(int n)
{
	int i,j,k;
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i!=j&&map[i][j]) map[i][j]++;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(i!=j&&i!=k&&j!=k&&map[i][k]&&map[k][j]) 
				{
					map[i][j]++;
					if(map[i][j]>=2) return true;
				}
//	for(i=1;i<=n;i++)
	return false;
}

int main()
{

	int t,k=1;
	freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
	scanf("%d",&t);
	while(t--)
	{
		int n;
		int i,j;
		int m,x;
		scanf("%d",&n);
		memset(map,0,sizeof(map));
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&x);
				map[i][x]=1;
			}
		}
		printf("Case #%d: ",k++);
		if(check(n)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}