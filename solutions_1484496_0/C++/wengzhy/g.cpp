#include<cstdio>
#include<cstring>
using namespace std;
int a[5000000];
int b[1000000];
int c[1000000];
int re;
void dfs( int x, int n, int y, int ans )
{
	if ( re == 2 ) return;
	if ( y > ans ) return;
	if ( y == ans )
	{
		for ( int i = 1; i < c[0]; i++ )
			printf( "%d ",b[c[i]] );
		printf( "%d\n",b[c[c[0]]]);
		re++;
		return;
	}
	if ( x == n ) return ;
	for ( int i = 0; i < 2; i++ )
	{
		if ( i == 1 )
		{
			c[++c[0]] = x;
		}
		dfs( x+1, n, y+b[x]*i, ans );
		if ( i == 1 )
		{
			c[0]--;
		}
	}
}
int main()
{
	int cas, ca = 0;
	int n,m;
	scanf( "%d", &cas );
	while ( cas-- )
	{
		ca++;
		scanf( "%d", &n );
		c[0] = 0;
		for ( int i = 0; i < n; i++ )
		{
			scanf( "%d", &b[i] );
		}
		memset( a, 0 ,sizeof( a ));
		a[0] = 1;
		m = 0;
		int m1 = m;
		for ( int i = 0; i < n; i++ )
		{
			m1 = m + b[i];
			for ( int j = m; j >= 0; j-- )
			if  ( a[j] != 0 )
			{
				a[j+b[i]]++;
			}
			m = m1;
//			printf( "%d\n",m);
		}
		int ans = -1;
//		printf( "%d\n",a[3117]);
//		printf( "%d\n",a[4210]);
//		printf( "%d\n",a[4943]);
//		printf( "%d\n",a[7327]);
//		printf( "%d\n",a[12270]);
		for ( int i = 0; i < m1; i++ )
		if ( a[i] > 1 )
		{
			ans = i;
			break;
		}
		printf( "Case #%d:\n",ca);
		if ( ans == -1 )
		{
			printf("Impossible\n");
		}
		else
		{
			re = 0;
			dfs(0,n,0,ans);
		}
	}
	return 0;
}