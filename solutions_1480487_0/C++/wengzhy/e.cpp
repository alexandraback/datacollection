#include<cstdio>
#include<cstring>
using namespace std;
const double le = 1e-8;
int n;
int a[10000];
double Abs( double x )
{
	if ( x < 0 ) return -x;
	else return x;
}
int cmp( double x )
{
	if ( Abs(x) < le ) return 0;
	else if ( x > le ) return 1;
	else return -1;
}
double second( double l, double r, double sum )
{
	if ( cmp(l - r ) == 0 ) return l;
	double mid = ( l + r ) / 2;
	double ans = 0;
	bool u = true;
//	printf( "%.6lf\n", mid );
	for ( int i = 0; i < n; i++ )
	{
		if ( cmp( mid - a[i]) < 0 ) 
		{
			u = false;
		}
		else ans = ans + (mid - a[i]) / sum;
	}
	int t = cmp( ans - 1 );
	if (  t < 0 ) return second(  mid, r, sum );
	else if ( t > 0 ) return second( l, mid, sum );
	else return mid;
}
int main()
{
	int cas;
	int ca = 0;
	scanf( "%d", &cas );
	while ( cas-- )
	{
		scanf( "%d", &n );
		int sum = 0;
		for ( int i = 0; i < n; i++ )
		{
			scanf( "%d", &a[i] );
			sum += a[i];
		}
		double ans = second( 0, sum+sum, sum );
		ca++;
		printf( "Case #%d:", ca );
//		printf( "%.6lf\n", ans );
		for ( int i = 0; i < n; i++ )
		{
			double l = a[i];
			double s = sum;
			if ( cmp((ans - l)*100 / s) >= 0 ) 
			printf( " %.6lf", (ans - l)*100 / s );
			else printf( " 0");
		}
		printf( "\n");
	}

	return 0;
}