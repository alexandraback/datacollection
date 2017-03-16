#include<stdio.h>
#include<string.h>
#define max(a,b) (a)=(a)>(b)?(a):(b)

int E,R,N;

int v[10020];

int f[16][16];

int c(int x)
{
	if ( x > E ) return E;
	else return x;
}

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int T;
	scanf("%d",&T);
	for ( int tt=1;tt<=T;tt++ )
	{
		scanf("%d%d%d",&E,&R,&N);
		for ( int i=1;i<=N;i++ )
			scanf("%d",&v[i]);
		for ( int i=0;i<=E;i++ )
			for ( int j=0;j<=N;j++ )
				f[j][i]=0x80000000;
		for (int i=0;i<=E;i++) f[0][i]=0;
		for ( int i=1;i<=N;i++ ){
			for ( int j=0;j<=E;j++ )
				max(f[i][j],f[i-1][j]);
			for ( int t=0;t<=E;t++ )
				for ( int j=0;j<=E;j++ ){
					if ( t <= j )
						max(f[i][c(j-t+R)],f[i-1][j]+v[i]*t);
				}
		}
		int ans=0;
		for ( int i=0;i<=E;i++ )
			max(ans,f[N][i]);
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}

