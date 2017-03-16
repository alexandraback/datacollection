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
long long a[ 100 ][ 2 ] , b[ 100 ][ 2 ] ;
long long dp[ 100 ][ 100 ] ;
int Mn , Mm ;
long long dfs( int n , int m )
{
	if ( n < 0 || m < 0 )
	{
		return 0 ;
	}
	if ( dp[ n ][ m ] != -1 )
	{
		return dp[ n ][ m ] ;
	}
	if ( a[ n ][ 1 ] == b[ m ][ 1 ] )
	{
//		printf( "dfs:(%d, %d)" , n , m ) ;
		long long q = min( a[ n ][ 0 ] , b[ m ][ 0 ] ) , r ;
//		printf( " q=%lld" , q ) ;
//		printf( " (%lld, %lld)" , a[ n ][ 0 ] , a[ n ][ 1 ] ) ;
//		printf( " (%lld, %lld)" , b[ m ][ 0 ] , b[ m ][ 1 ] ) ;
//		puts( "" ) ;
		a[ n ][ 0 ] -= q ;
		b[ m ][ 0 ] -= q ;
		if ( !a[ n ][ 0 ] && !b[ m ][ 0 ] )
		{
			r = dfs( n - 1 , m - 1 ) ;
		}else
		if ( a[ n ][ 0 ] )
		{
			r = dfs( n , m - 1 ) ;
		}else
		if ( b[ m ][ 0 ] )
		{
			r = dfs( n - 1 , m ) ;
		}
		a[ n ][ 0 ] += q ;
		b[ m ][ 0 ] += q ;
		dp[ n ][ m ] = max( dp[ n ][ m ] , r + q ) ;
		return dp[ n ][ m ] ;
	}
	return dp[ n ][ m ] = max( dfs( n - 1 , m ) , dfs( n , m - 1 ) ) ;
}
int main ()
{
	int t = in() , Case = 1 ;
	while ( t -- )
	{
		int n = in() , m = in() ;
		for ( int i = 0 ; i < n ; i ++ )
		{
			scanf( "%lld%lld" , &a[ i ][ 0 ] , &a[ i ][ 1 ] ) ;
		}
		for ( int i = 0 , j ; i < m ; i ++ )
		{
			scanf( "%lld%lld" , &b[ i ][ 0 ] , &b[ i ][ 1 ] ) ;
		}
//		printf( "A:%d\n" , n ) ;
//		for ( int i = 0 ; i < n ; i ++ )
//		{
//			printf( " (%lld, %lld)" , a[ i ][ 0 ] , a[ i ][ 1 ] ) ;
//		}
//		puts( "" ) ;
//		printf( "B:%d\n" , m ) ;
//		for ( int i = 0 ; i < m ; i ++ )
//		{
//			printf( " (%lld, %lld)" , b[ i ][ 0 ] , b[ i ][ 1 ] ) ;
//		}
//		puts( "" ) ;
		for ( int i = 0 ; i < n ; i ++ )
		{
			for ( int j = 0 ; j < m ; j ++ )
			{
				dp[ i ][ j ] = -1 ;
			}
		}
		printf( "Case #%d: %lld\n" , Case ++ , dfs( n - 1 , m - 1 ) ) ;
	}
}
