#include<cstdio>
#include<cstring>
using namespace std;
int ans[2005];
int an[2005];
int Abs( int x )
{
	return x < 0 ? -x : x;
}
int zuhe( int x, int y )
{
	int z = 1;
	for ( int i = 1; i <= x; i++ )
	{
		z = z * ( y - i + 1 ) / i;
	}
	return z;
}
int main()
{
	int cas;
	int ca = 0;
	int j = -3;
	ans[0] = 0;
	for ( int i = 1; i <= 1005; i++ )
	{
		j += 4;
		an[i] = j;
		ans[i] = ans[i-1]+j;
	}
	scanf( "%d", &cas );
	while ( cas-- )
	{
		int n,x,y;
		scanf("%d%d%d", &n, &x, &y );
		x = Abs(x);
		y = Abs(y);
		int i = 1;
		while ( n >= ans[i] ) i++;
		i--;
		if (( x + y ) / 2 < i ) printf( "Case #%d: %.6lf\n", ++ca, 1.0 );
		else if (( x + y ) / 2 > i ) printf( "Case #%d: %.6lf\n", ++ca, 0.0 );
		else
		{
			int l = n - ans[i];
			if ( l == 0 ) printf( "Case #%d: %.6lf\n", ++ca, 0 );
			else
			{
				int t = ( an[i+1] + 1 ) / 2;
/*				if ( l < t )
				{
					int q = l - y + ;
					if ( q < 0 ) q = 0;
					printf( "Case #%d: %.6lf\n", ++ca, (double)(q)/(l*2) );
				}
				else
				{
					l = l - t + 1;
					int q = l - y;
					if ( q < 0 ) q = 0;
					printf( "Case #%d: %.6lf\n", ++ca, (double)(q)/(l*2) );
				}*/
				if ( l < t )
				{
					int sum = 1 << l;
					int q = 0;
					for ( int i = y + 1; i <= l; i++ )
						q += zuhe( i, l );
//					printf("%d %d\n",y,l);
					printf( "Case #%d: %.6lf\n", ++ca, (double)(q)/(sum) );
				}
				else
				{
					int sum = 0;
					for ( int i = l - t + 1; i < t; i++ )
						sum += zuhe( i, l );
					int q = 0;
					int qq = y + 1;
					if ( qq < l - t + 1 ) qq = l - t + 1;
					for ( int i = qq; i < t; i++ )
						q += zuhe( i, l );
					printf( "Case #%d: %.6lf\n", ++ca, (double)(q)/(sum) );
				}
			}
		}
	}
	return 0;
}