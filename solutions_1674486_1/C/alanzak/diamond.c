#include <stdio.h>
#include <stdlib.h>
int a[1001][1001];
int c[1001][1001];
int n,flag,m[1002];


void solve(int parent,int ver)
{
	int i,tex;

	for(i=1;i<=m[ver];i++)
	{
		tex = a[ver][i];
		c[parent][tex]++;
		if(c[parent][tex]==2)
		{
			flag=1;
			return;
		}
		solve(parent,tex);
		if(flag==1)
			return;
	}
}

int main()
{
	int f,g=0;
	scanf("%d",&f);
	while(g<f)
	{
		flag = 0;
		int n,i,j;
		scanf("%d",&n);
		for(i=0;i<n+1;i++)
			for(j=0;j<n+1;j++)
				c[i][j]=0;
		for(i=1;i<n+1;i++)
		{
			scanf("%d",&m[i]);
			for(j=1;j<=m[i];j++)
			{
				int h;
				scanf("%d",&h);
				a[i][j]=h;
			}
		}
		for(i=1;i<=n;i++)
		{
			solve(i,i);
		}
		if(flag == 1)
			printf("Case #%d: Yes\n",g+1);
		else
			printf("Case #%d: No\n",g+1);
		g++;
	}
	return 0;
}
