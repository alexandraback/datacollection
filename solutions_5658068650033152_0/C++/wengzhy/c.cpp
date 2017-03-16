#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int cas;
	scanf( "%d", &cas );
	int ans = -1;
	for ( int c = 0; c < cas; c++ )
	{
		int n,m,k;
		scanf( "%d%d%d", &n, &m, &k );
		ans = -1;
		int q = n;
		if ( q > m ) q = m;
		for ( int i = 1; i <= ( q - 1 ) /2; i++ )
		{
			int p = ( 1 + 2 * i - 1 ) * 2 * 2 / i + 2 * i + 1;
			if ( i == 1 ) p = 5;
			if ( k <= p ) 
				if ( ans == -1 || ans > i * 4 ) ans = i * 4;
		}
//		printf("Case #%d: %d\n",c+1,ans);
		for ( int i = 2; i <= m; i++ )
			for ( int j = 2; j <= n; j++ )
			{
				if ( k <= i * j )
					if ( ans == -1 || ans > ( i + j - 2 ) * 2) ans = ( i + j - 2 ) * 2;
				if ( i != 2 && j != 2 )
				if ( k <= i * j - 4 )
					if ( ans == -1 || ans > ( i + j - 2 ) * 2 - 4 ) ans = ( i + j - 2 ) * 2 - 4;
			}
		if ( k <= 4 ) ans = k;
		if ( n == 1 || m == 1 ) ans = k;
		if ( ans == -1 || ans > k ) ans = k;
		printf("Case #%d: %d\n",c+1,ans);
	}
	return 0;
}