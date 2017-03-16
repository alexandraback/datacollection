#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <queue>
#include <map>
#include <vector>
#define phb push_back
#define ppb pop_back
using namespace std ;
inline int in(int d=0,char q=0,int c=1){while(q!='-'&&q!=EOF&&(q<48||q>57))q=getchar();if(q==EOF)return EOF;if(q=='-')c=-1,q=getchar();do d=d*10+(q^48),q=getchar();while(q<58&&q>47);return c*d;}
bool res ;
int his1[ 20 ] = {} , n ;
int his2[ 20 ] = {} ;
bool use[ 20 ] = {} ;
int a[ 20 ] ;
void dfs2( int k , int i , int mm , int m )
{
	if ( res || mm > m ) return ;
	if ( mm == m )
	{
		printf( "%d" , his2[ 0 ] ) ;
		for ( i = 1 ; i < k ; i ++ )
		{
			printf( " %d" , his2[ i ] ) ;
		}
		puts( "" ) ;
		res = true ;
		return ;
	}
	for (  ; i < n ; i ++ )
	{
		if ( !use[ i ] )
		{
			use[ i ] = true ;
			his2[ k ] = a[ i ] ;
			dfs2( k + 1 , i + 1 , mm + a[ i ] , m ) ;
			use[ i ] = false ;
		}
	}
}
void ck( int k , int m )
{
	for ( int i = 0 ; i < n ; i ++ )
	{
		if ( !use[ i ] )
		{
			use[ i ] = true ;
			his2[ 0 ] = a[ i ] ;
			dfs2( 1 , i + 1 , a[ i ] , m ) ;
			use[ i ] = false ;
			if ( res )
			{
				printf( "%d" , his1[ 0 ] ) ;
				for ( i = 1 ; i < k ; i ++ )
				{
					printf( " %d" , his1[ i ] ) ;
				}
				puts( "" ) ;
				return ;
			}
		}
	}
}
void dfs1( int k , int i , int m )
{
	if ( res ) return ;
	ck( k , m ) ;
	for (  ; i < n ; i ++ )
	{
		use[ i ] = true ;
		his1[ k ] = a[ i ] ;
		dfs1( k + 1 , i + 1 , m + a[ i ] ) ;
		use[ i ] = false ;
	}
}
int main ()
{
	int t = in() , Case = 1 ;
	while ( t -- )
	{
		memset( use , 0 , sizeof( use ) ) ;
		n = in() ;
		for ( int i = 0 ; i < n ; i ++ )
		{
			a[ i ] = in() ;
		}
		sort( a , a + n ) ;
		printf( "Case #%d:\n" , Case ++ ) ;
		res = false ;
		for ( int i = 0 ; i < n ; i ++ )
		{
			use[ i ] = true ;
			his1[ 0 ] = a[ i ] ;
			dfs1( 1 , i + 1 , a[ i ] ) ;
			use[ i ] = false ;
		}
		if ( !res )
		{
			puts( "Impossible" ) ;
		}
	}
}
