#include <cstdio>
#include <cstdlib>

int a[1001], b[1001];
bool f[1001];

void qsort( int l, int r )
{
	int i = l, j = r, x = b[ ( l + r ) >> 1 ], t;
	
	while( i <= j )
	{
		while( b[i] < x ) ++i;
		while( x < b[j] ) --j;
		if( i <= j )
		{
			t = a[i]; a[i] = a[j]; a[j] = t;
			t = b[i]; b[i] = b[j]; b[j] = t;
			++i; --j;
		}
	}
	if( l < j ) qsort( l, j );
	if( i < r ) qsort( i, r );
}

int main( )
{
	freopen( "B-large.in", "r", stdin );
	freopen( "output.txt", "w", stdout );
	
	int i, j, k, s, t, n, T, o;
	double ans, p, x;
	
	scanf( "%d", &T );
	for( o = 1; o <= T; ++o )
	{
		printf( "Case #%d: ", o );
		
		scanf( "%d", &n );
		for( i = 1; i <= n; f[i] = 0, ++i )
			scanf( "%d%d", &a[i], &b[i] );
		
		qsort( 1, n );
//		printf( "\n" );
//		for( i = 1; i <= n; f[i] = 0, ++i )
//			printf( "%d %d\n", a[i], b[i] );
		
		k = 0; s = 0;
		for( i = 1; i <= n; ++i )
		{
			while( k < b[i] )
			{
				for( j = n; j >= i; --j )
					if( !f[j] && a[j] <= k )
					{
						f[j] = 1;
						++k; ++s;
						break;
					}
				if( j < i || k >= b[i] ) break;
			}
			if( k < b[i] ) break;
			++s;
			if( f[i] ) ++k;
			else k += 2;
		}
		if( i <= n ) printf( "Too Bad\n" );
		else printf( "%d\n", s );
	}
	return 0;
}
