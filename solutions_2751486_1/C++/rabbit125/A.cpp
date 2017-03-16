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
#define MAX  12000000
using namespace std ;
char A[ 5 ] = { 'a' , 'e' , 'i' , 'o' , 'u' } ;
char w[ MAX ] ;
int  n , m ;
int  N[ MAX ] ;
int  c[ MAX ] ;
vector <long long> v ;
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
		v.clear( ) ;
		c[ 0 ] = N[ 0 ] == 0 ? 1 : 0 ;
		//printf( "%c" , w[ j ] ) ;
		for( int k = 1 ; k < m ; k++ )
		{
			if( N[ k ] == 0 )
				c[ k ] = c[ k-1 ] + 1 ;
			else
				c[ k ] = 0 ;
			//printf( "%c" , w[ k ] ) ;
		} 
		for( int k = 0 ; k < m ; k++ )
		{
			//printf( "%d%c" , c[ k ] , k == m-1 ? '\n' : ' ' ) ;
			if( c[ k ] >= n && k-n+1 >= 0 )
			{
				v.push_back( k-n+1 ) ;
				//printf( "x%dx\n" , k-n ) ;
			}
		}
		
		/*
		for( int i = n ; i <= n ; i++ )
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
							//printf( "===%d %d %d ==\n" , i , j , n ) ;
							v.push_back( j ) ;
							//ans++ ;
							break ;
						}
				}
			}
		}
		*/
		long long int b = -1 , ta , tb ;
		for( int i = 0 ; i < v.size( ) ; i++ )
		{
			ta = ( v[ i ] - b ) ;
			tb = ( m-(v[ i ]+n)+1 ) ;
			//printf( "%lld %lld\n" , ta , tb ) ;
			ans += ta * tb ;
			b = v[ i ] ;
		}
		printf( "Case #%d: %lld\n" , T++ , ans ) ;
	}
	return 0 ;
}

