#include <stdio.h>

const int maxn=101;

int map[maxn][maxn];
int h[maxn],r[maxn];
int i,j,k,m,n,t,tt,x,y;

bool check()
{
	int i,j;

	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if ((h[i]>map[i][j])&&(r[j]>map[i][j]))
				return false;
	return true;
}
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d\n",&t);
	for (int tt=1;tt<=t;tt++)
	{
		scanf("%d%d",&n,&m);
		for (i=1;i<=n;i++)
			h[i]=0;
		for (i=1;i<=m;i++)
			r[i]=0;
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
			{
				scanf("%d",&map[i][j]);
				if (map[i][j]>h[i])
					h[i]=map[i][j];
				if (map[i][j]>r[j])
					r[j]=map[i][j];
			}
		printf("Case #%d: ",tt);
		if (check())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
