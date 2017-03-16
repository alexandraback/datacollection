#include <cstdio>
#include <cstring>

int t,q,i,j,k,l,n;
int f[1001][1001];

bool floyd()
{
	int i,j,k;
	for(k=1;k<=n;k++)
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		f[i][j]+=f[i][k]*f[k][j];
		if(f[i][j]>1)return 1;
	}
	return 0;
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&t);
	for(q=1;q<=t;q++)
	{
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&k);
			for(j=1;j<=k;j++)
			{
				scanf("%d",&l);
				f[i][l]=1;
			}
		}
		printf("Case #%d: ",q);
		if(floyd())printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}

