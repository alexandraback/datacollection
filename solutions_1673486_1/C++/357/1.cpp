#include <cstdio>
#include <cstdlib>

int main( )
{
	freopen( "A-large.in", "r", stdin );
	freopen( "output.txt", "w", stdout );
	
	int i, n, l, T, o;
	double ans, p, x;
	
	scanf( "%d", &T );
	for( o = 1; o <= T; ++o )
	{
		printf( "Case #%d: ", o );
		
		scanf( "%d%d", &l, &n );
		ans = n + 2.0; p = 1.0;
		if( l + n + 1 < ans ) ans = l + n + 1;
		for( i = 1; i <= l; ++i )
		{
			scanf( "%lf", &x );
			p *= x;
			x = p * ( l - i + n - i + 1 ) + ( 1.0 - p ) * ( l - i + n - i + 1 + n + 1 );
			if( x < ans ) ans = x;
		}
		printf( "%.6lf\n", ans );
	}
	return 0;
}
