#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 100000;
double p[maxn];
int main()
{
	int cas,a,b;
	int ca = 0;
	scanf( "%d", &cas );
	while ( cas-- )
	{
		scanf( "%d%d", &a, &b );
		for ( int i = 1; i <= a; i++ )
		{
			scanf( "%lf", &p[i] );
		}
		double ans = 1;
		double anss = -1;
		for ( int i = 1; i <= a; i++ )
		{
			ans = ans * p[i];
			if ( i == a )
			{
				double t = ans * ( b - a + 1 ) + ( 1 - ans ) * ( b - a + 1 + b + 1 );
				if ( anss == -1 || t < anss ) 
					anss = t;
				t = 1 + b + 1;
				if ( anss == -1 || t < anss ) 
					anss = t;
			}
			else
			{
				double t = ans * ( a - i + b - i + 1) + ( 1 - ans ) * ( a - i + b - i + 1 + b + 1 );
				if ( anss == -1 || t < anss ) 
					anss = t;
	//			printf( "%.6lf\n",anss);
			}
		}
		ca++;
		printf( "Case #%d: %.6lf\n", ca,anss );
	}

	return 0;
}