#include<stdio.h>
#include<stdlib.h>

int g[1010][1010];
int p[1010][1010];

void clear(int n)
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			g[i][j] = 0;
			p[i][j] = 0;
		}
	for(i=1;i<=n;i++)
	{
		g[i][i] = 1;
		p[i][i] = 1;
	}
}

int main()
{
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("A-small-attempt0.out","wt",stdout);
	int t,n,m,i,j,k,l,x,check,count;
	scanf("%d",&t);
	for(l=1;l<=t;l++)
	{
		scanf("%d",&n);
		clear(n);
		check = 0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(j=1;j<=m;j++)
			{
				scanf("%d",&x);
				p[i][x] = 1;
				g[i][x] = 1;
			}
		}
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					p[i][j] = p[i][j]|(p[i][k]&p[k][j]);
		for(i=1;i<=n && check==0;i++)
			for(j=1;j<=n && check==0;j++)
			{
				count = 0;
				for(k=1;k<=n;k++)
					if(i!=k && g[i][k]==1)
						count += p[k][j];
				if(count > 1)
					check = 1;
			}
		printf("Case #%d: ",l);
		if(check==0)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}
