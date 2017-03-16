#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int b[1000005];
int c[1000005];
int main()
{
	int cas;
	int ca = 0;
	scanf( "%d", &cas );
	while ( cas-- )
	{
		int a,n;
		scanf( "%d%d", &a, &n );
		for ( int i = 1; i <= n; i++ )
			scanf( "%d", &b[i] );
		sort( b + 1, b + n + 1 );
		c[0] = 0;
		for ( int i = 1; i <= n; i++ )
		{
			c[i] = c[i-1];
			while ( a <= b[i] && c[i] <= n )
			{
				a = a + a - 1;
				c[i]++;
			}
			a += b[i];
		}
		int ans = n;
		for ( int i = 1; i <= n; i++ )
		{
			if ( ans > c[i] + n - i )
				 ans = c[i] + n - i;
		}
		printf("Case #%d: %d\n",++ca,ans);
	}
	return 0;
}