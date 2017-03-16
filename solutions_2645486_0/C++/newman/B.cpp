#include <stdio.h>

int E,R,n;
int f[20][20];
int v[20];

void work()
{
	int i,j,k,nj,tmp;
	for (i=0; i<=E; ++i)
		f[n][i]=i*v[n];
	for (i=n-1; i>=1; --i)
	{
		for (j=0; j<=E; ++j)
		{
			f[i][j]=0;
			for (k=0; k<=j; ++k)
			{
				tmp=k*v[i];
				nj=j-k+R;
				if (nj>E)
					nj=E;
				tmp+=f[i+1][nj];
				if (tmp>f[i][j])
					f[i][j]=tmp;
			}
		}
	}
}

int main()
{
	int w,i,tot;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&tot);
	for (w=1; w<=tot; ++w)
	{
		printf("Case #%d: ",w);
		scanf("%d%d%d",&E,&R,&n);
		for (i=1; i<=n; ++i)
			scanf("%d",&v[i]);
		work();
		printf("%d\n",f[1][E]);
	}
	return 0;
}