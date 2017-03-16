//Templete 2013/05/12
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#define INF 100000000
#define MAX     12000
using namespace std ;
char A[ 5 ] = { 'a' , 'e' , 'i' , 'o' , 'u' } ;
char w[ MAX ] ;
int  n , m ;
int  N[ MAX ] ;
int  c[ MAX ] ;
int main( )
{
	int t , T = 1 ;
	long long int ans ; 
	scanf( "%d" , &t ) ;
	while( t-- )
	{
		scanf( "%s%d" , w , &n ) ;
		m = strlen( w ) ;
		for( int i = 0 ; i < strlen( w ) ; i++ )
		{
			bool is = 0 ;
			for( int j = 0 ; j < 5 ; j++ )
				if( w[ i ] == A[ j ] )
					is = 1 ;
			if( is )
				N[ i ] = 1 ;
			else
				N[ i ] = 0 ;
		}
		ans = 0 ;
		for( int i = n ; i <= m ; i++ )
		{
			for( int j = 0 ; j < m ; j++ )
			{
				bool is = 0 ;
				if( j+i <= m )
				{
					c[ j ] = N[ j ] == 0 ? 1 : 0 ;
					//printf( "%c" , w[ j ] ) ;
					for( int k = j+1 ; k < j+i ; k++ )
					{
						if( N[ k ] == 0 )
							c[ k ] = c[ k-1 ] + 1 ;
						else
							c[ k ] = 0 ;
						//printf( "%c" , w[ k ] ) ;
					} 
					//printf( "\n" ) ;
					for( int k = j ; k < j+i ; k++ )
						if( c[ k ] >= n )
						{
							is = 1 ;
							//printf( "===%d %d %d ==\n" , i , j , k ) ;
							ans++ ;
							break ;
						}
				}
			}
		
		}
		printf( "Case #%d: %lld\n" , T++ , ans ) ;
	}
	return 0 ;
}

