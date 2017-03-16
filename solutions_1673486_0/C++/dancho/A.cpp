#include <cstdio>

inline double min( const double &a, const double &b )
{
	if ( a < b ) return a;
	return b;
}

int a, b;
double p[100020];
double pp[100020];

int main()
{
	int t, T;
	int i, j;
	
	double be, pr;
	
	scanf( "%d", &T );
	for ( t = 1; t <= T; t++ )
	{
		scanf( "%d %d", &a, &b );
		pr = 1;
		pp[0] = 1;
		for ( i = 1; i <= a; i++ )
		{
			scanf( "%lf", &p[i] );
			pp[i] = pp[i-1]*p[i];
			pr = pr * p[i];
		}
		
		be = min( b+1, pr*(b-a) + (1.0-pr)*(b-a+1+b) );
		
		for ( i = a, j = 0; i >= 0; i--, j++ )
		{
			be = min( be, pr*(b-a+j+j) + (1.0-pr)*(b-a+j+j+1+b) );
//			printf( "%d %lf %lf\n", i, pr*(b-a+j+j) + (1.0-pr)*(b-a+j+j+1+b), be );
			pr = pp[i-1];
		}
		
		be = be + 1;
		printf( "Case #%d: %.8lf\n", t, be );
	}
	return 0;
}
