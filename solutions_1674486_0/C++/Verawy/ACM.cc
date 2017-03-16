#include <stdio.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int map[100][100];

int main()
{
	int T,tt,n,i,j,k,m,x;
	bool flag;
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	for (int tt=1;tt<=T;tt++)
	{
		scanf("%d",&n);
		memset(map,0,sizeof(map));
		for (i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for (j=1;j<=m;j++)
			{
				scanf("%d",&x);
				map[i][x]=1;
			}
		}
		for (k=1;k<=n;k++)
			for (i=1;i<=n;i++)
				for (j=1;j<=n;j++)
				{
					map[i][j]+=map[i][k]*map[k][j];
				}
		flag=false;
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				if (map[i][j]>1)
				{
					flag=true;
				}
		printf("Case #%d: ",tt);
		if (!flag) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
