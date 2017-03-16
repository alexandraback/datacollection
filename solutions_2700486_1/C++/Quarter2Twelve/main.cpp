#include <stdio.h>
#include <math.h>

int T;
int N, X, Y;
int counter;
int accer;
double ans;
int r, b;
double lnchoose( int, int );
double choose( int, int );

int main()
{
	scanf( "%d", &T );
	for( int p = 0; p < T; ++p )
	{
		scanf( "%d %d %d", &N, &X, &Y );
		ans = 0.0;
		counter = 0;
		accer = 0;
		for( r = 1;; ++r )
		{
			accer += (counter<<1) + 1;
			counter += 2;
			if( accer > N )
				break;
		}
		--r;
		accer -= (counter<<1)-3;
		b = N - accer;
		if( (X+Y) <= 2*(r-1) && (Y-X) <= 2*(r-1) )
			ans = 1.0;
		if( (X+Y) > 2*(r-1) )
		{
			if( (X+Y) > 2*r )
				ans = 0.0;
			else if( b == 0 )
				ans = 0.0;
			else if( X == 0 )
				ans == 0.0;
			else
			{
				if( b <= 2*r+Y )
				{
					for( int j = 0; j < Y+1; ++j )
					{
						ans += choose( b, j );
					}
					ans = 1 - ans/pow( 2, (double)b );
				}
				else
					ans = 1.0;
			}
		}
		if( (Y-X) > 2*(r-1) )
		{
			if( (Y-X) > 2*r )
				ans = 0.0;
			else if( b == 0 )
				ans =0.0;
			else if ( X == 0 )
				ans = 0.0;
			else
			{
				if( b <= 2*r+Y )
				{
					for( int j = 0; j < Y+1; ++j )
					{
						ans += choose( b, j );
					}
					ans = 1 - ans/pow( 2, (double)b );
				}
				else
					ans = 1.0;
			}
		}
		printf( "Case #%d: %lf\n", p+1, ans );
	}
	return 0;
}

double lnchoose(int n, int m)
{
	if (m < n/2.0)
	{
	m = n-m;
	}
	double s1 = 0;
	for (int i=m+1; i<=n; i++)
	{
		s1 += log((double)i);
	}
	double s2 = 0;
	int ub = n-m;
	for (int i=2; i<=ub; i++)
	{
		s2 += log((double)i);
	}
	return s1-s2;
}

double choose(int n, int m)
{
	if (m > n)
		return 0;
	if( m == 0 )
		return 1;
	return exp(lnchoose(n, m));
}