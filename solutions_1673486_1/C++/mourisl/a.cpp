#include <stdio.h>

double allright ;
double p[101000] ;
bool right[101000] ;
int a, b ; 

int main()
{
	int tt, t ;
	int i ;
	double result ;
	double tmp, prob ;
	scanf( "%d", &tt ) ;
	for ( t = 1 ; t <= tt ;++t )
	{
		scanf( "%d %d", &a, &b ) ;
		for ( i = 0 ; i < a ; ++i )
			scanf( "%lf", &p[i] ) ;
		allright = 0 ;
		
		result = b + 2 ;			
		prob = 1 ;
		for ( i = 0 ; i < a ; ++i )
		{
			tmp = ( a - i + ( b - i + 1 ) ) * prob + ( a - i + ( b - i + 1 ) + ( b + 1 )) * ( 1 - prob ) ;
			if ( tmp < result )
				result = tmp ; 
			prob *= p[i] ;
		}
		
		tmp = ( b - a + 1 ) * prob + ( b - a + 1 + b + 1 ) * ( 1 - prob ) ;
		if ( tmp < result )
			result = tmp ;
		printf( "Case #%d: %.6lf\n", t, result ) ;
	}
	return 0 ;
}
