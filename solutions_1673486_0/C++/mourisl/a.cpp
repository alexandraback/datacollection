#include <stdio.h>

double s[101000] ;
double p[101000] ;
bool right[101000] ;
int a, b ; 

void solve( int depth )
{
	if ( depth == a )
	{
		double prob = 1 ;
		int i, k ;
		
		for ( i = 0 ; i < a ; ++i )
			if ( right[i] ) 
				prob *= p[i] ;
			else
				prob *= ( 1 - p[i] ) ;
		// s[0]
		for ( i = 0 ; i < a ; ++i )
			if ( !right[i] )
				break ;
		if ( i >= a )
			s[0] = s[0] + ( b - a + 1 ) * prob ;	
		else
			s[0] = s[0] + ( b - a + 1 + b + 1 ) * prob ;
			
		s[1] = b + 2 ;
		
		for ( k = 0 ; k < a ; ++k )
		{
			for ( i = 0 ; i < a - k - 1 ; ++i )
				if ( !right[i] )
					break ;
					
			if ( i >= a - k - 1 )
				s[k + 2] = s[k + 2] + ( k + 1 + ( b - ( a - k - 1 ) + 1 ) ) * prob ;
			else
				s[k + 2] = s[k + 2] + ( k + 1 + ( b - ( a - k - 1 ) + 1 ) + b + 1 ) * prob ;
		}	
		return ;
	}
	
	right[depth] = true ;
	solve( depth + 1 ) ;
	right[depth] = false ;
	solve( depth + 1 ) ;
}

int main()
{
	int tt, t ;
	int i ;
	double result ;
	scanf( "%d", &tt ) ;
	for ( t = 1 ; t <= tt ;++t )
	{
		scanf( "%d %d", &a, &b ) ;
		for ( i = 0 ; i < a ; ++i )
			scanf( "%lf", &p[i] ) ;
		for ( i = 0 ; i < a + 2 ; ++i )
			s[i] = 0 ;
		result = b + 10 ;			
		solve( 0 ) ;
		
		for ( i = 0 ; i < a + 2 ; ++i )
		{
			if ( s[i] < result )
				result = s[i] ;
		}
		printf( "Case #%d: %.6lf\n", t, result ) ;
	}
	return 0 ;
}
