#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, x, y;
int lx, rx;
int d;

bool us[5020][5020];
double com[5020][5020];

double dp[5020][5020];

double getDP( int l, int k )
{
	if ( us[l][k] )
		return dp[l][k];
	if ( l == 0 && k == 0 )
		return 1.0;
	
	if ( l == d )
	{
		if ( k > 0 )
		{
			if ( k == d )
				dp[l][k] = getDP( l-1, k ) + getDP( l, k-1 );
			else
				dp[l][k] = getDP( l, k-1 ) + getDP( l-1, k )/2;
		}
		else dp[l][k] = getDP( l-1, k )/2;
	}
	else if ( k == d )
	{
		if ( l > 0 )
		{
			dp[l][k] = getDP( l-1, k ) + getDP( l, k-1 )/2;
		}
		else
			dp[l][k] = getDP( l, k-1 )/2;
	}
	else if ( l == 0 )
		dp[l][k] = getDP( l, k-1 )/2;
	else if ( k == 0 )
		dp[l][k] = getDP( l-1, k )/2;
	else
		dp[l][k] = getDP( l-1, k )/2 + getDP( l, k-1 )/2;
	us[l][k] = 1;
	return dp[l][k];
}

double gcom( int n, int k )
{
	if ( k == 0 ) return 1;
	if ( n == 0 ) return 0;
	if ( us[n][k] )
		return com[n][k];
	com[n][k] = gcom( n-1, k ) + gcom( n-1, k-1 );
	us[n][k] = 1;
	return com[n][k];
}

int main()
{
	int t, T;
	int i, k;
	memset( us, 0, sizeof( us ) );
	scanf( "%d", &T );
	double pr, all, good;
	for ( t = 1; t <= T; t++ )
	{
		scanf( "%d %d %d", &n, &x, &y );
		k = 1;
		n--;
		lx = rx = 0;
		while ( n >= 4*k+1 )
		{
			n -= (4*k+1);
			k++;
			lx -= 2;
			rx += 2;
		}
		
		if ( x < 0 ) x = -x;
		
		if ( x+y <= rx )
		{
			printf( "Case #%d: %.8lf\n", t, 1.0 );
			continue;
		}
		
		if ( x + y > rx+2 )
		{
			printf( "Case #%d: %.8lf\n", t, 0.0 );
			continue;
		}
		
		d = 2*k;
/*		while ( n > d )
		{
			n -= 2;
			d--;
			y--;
		}
		
		if ( y < 0 )
		{
			printf( "Case #%d: %.8lf\n", t, 1 );
			continue;
		}*/
		
		pr = 0;
		all = 0;
		good = 0;
		memset( us, 0, sizeof( us ) );
		for ( i = 0; i <= d; i++ )
		{
			if ( ( n-i <= d ) && ( n-i >= 0 ) )
			{
//				fprintf( stderr, "ALL += %d %d :: %lf\n", n, i, getDP( 0, i ) );
				all += getDP( n-i, i );
				if ( i > y )
					good += getDP( n-i, i );
			}
		}
		pr = good/all;
		printf( "Case #%d: %.8lf\n", t, pr );
	}
	return 0;
}
