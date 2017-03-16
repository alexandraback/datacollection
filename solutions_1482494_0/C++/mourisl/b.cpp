#include <stdio.h>

int require[1023][2] ;
int cond[1023] ;

int main()
{
	int i, t, tt ;
	int n ;
	int star, count ;
	int flag ;
	int tag, max ;
	
	scanf( "%d", &tt ) ;
	for ( t = 1 ; t <= tt ; ++t )
	{
		scanf( "%d", &n ) ;
		for ( i = 0 ; i < n ; ++i )
		{	
			scanf( "%d %d", &require[i][0], &require[i][1] ) ;
			cond[i] = 0 ;
		}
		
		flag = 0 ;
		star = 0 ;
		count = 0 ;
		while ( !flag )
		{
			for ( i = 0 ; i < n ; ++i )
			{
				if ( cond[i] == 0 && star >= require[i][1] )
				{
					star += 2 ;
					++count ;
					cond[i] = 2 ;
					break ;
				}
			}
			if ( i < n )
				continue ;
			
			for ( i = 0 ; i < n ; ++i )
			{
				if ( cond[i] == 1 && star >= require[i][1] )
				{
					cond[i] = 2 ;
					++count ;
					++star ;
					break ;
				}
			}	
			
			if ( i < n )
				continue ;
			
			max = -10 ;	
			for ( i = 0 ; i < n ; ++i )
			{
				if ( cond[i] == 0 && star >= require[i][0] )
				{
					if ( require[i][1] - star > max )
					{
						max = require[i][1] - star ;
						tag = i ;
					}
				}
			}
			
			if ( max == -10 )
			{
				flag = 1 ;
				break ;
			}
			
			cond[tag] = 1 ;
			++count ;
			++star ;
		}
		
		for ( i = 0 ; i < n ; ++i )
		{
			if ( cond[i] < 2 )
				break ;
		}
		
		if ( i >= n )
			printf( "Case #%d: %d\n", t, count ) ;
		else
			printf( "Case #%d: Too Bad\n", t ) ;
	}
	return 0 ;
}
