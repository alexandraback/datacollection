#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std ;
char Board[ 4 ][ 4 ] ;
int  Count[ 3 ] ;
char Who[ 3 ] = { 'X' , 'O' , 'T' } ;
void F( int x , int y , int w )
{
	if( Board[ x ][ y ] == Who[ w ] )
		Count[ w ]++ ;
	if( Board[ x ][ y ] == Who[ 2 ] )
		Count[ 2 ]++ ;
}
int main( )
{
	int  t , T = 1 ;
	bool Finish ;
	int  Win ;
	scanf( "%d" , &t ) ;
	while( t-- )
	{
		Finish = 1 ;
		Win    = 2 ;
		for( int i = 0 ; i < 4 ; i++ )
		{
			scanf( "%s" , Board[ i ] ) ;
			if( Board[ i ][ 0 ] == '.' || Board[ i ][ 1 ] == '.' || Board[ i ][ 2 ] == '.' || Board[ i ][ 3 ] == '.' )
				Finish = 0 ;
		}
		for( int k = 0 ; k < 2 ; k++ )
			for( int i = 0 ; i < 4 ; i++ )
			{
				Count[ 0 ] = Count[ 1 ] = Count[ 2 ] = 0 ;
				for( int j = 0 ; j < 4 ; j++ )
					F( i , j , k ) ;
				if( ( Count[ k ] == 4 ) || ( Count[ k ] == 3 && Count[ 2 ] == 1 ) )
					Win = k ;
				
				Count[ 0 ] = Count[ 1 ] = Count[ 2 ] = 0 ;
				for( int j = 0 ; j < 4 ; j++ )
					F( j , i , k ) ;	
				if( ( Count[ k ] == 4 ) || ( Count[ k ] == 3 && Count[ 2 ] == 1 ) )
					Win = k ;
				
				Count[ 0 ] = Count[ 1 ] = Count[ 2 ] = 0 ;
				for( int j = 0 ; j < 4 ; j++ )
					F( j , j , k ) ;	
				if( ( Count[ k ] == 4 ) || ( Count[ k ] == 3 && Count[ 2 ] == 1 ) )
					Win = k ;
				
				Count[ 0 ] = Count[ 1 ] = Count[ 2 ] = 0 ;
				for( int j = 0 ; j < 4 ; j++ )
					F( j , 3-j , k ) ;	
				if( ( Count[ k ] == 4 ) || ( Count[ k ] == 3 && Count[ 2 ] == 1 ) )
					Win = k ;
			}
		if( Win != 2 )
			printf( "Case #%d: %c won\n" , T++ , Who[ Win ] ) ;
		else
		{
			if( Finish )
				printf( "Case #%d: Draw\n" , T++ ) ;
			else
				printf( "Case #%d: Game has not completed\n" , T++ ) ;
		}
	}
	return 0 ;
}
