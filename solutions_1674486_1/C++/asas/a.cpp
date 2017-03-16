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
int dp[ 1001 ] ;
vector<int> M[ 1001 ] ;
int dfs( int k )
{
	if ( dp[ k ] != -1 )
	{
		return dp[ k ] ;
	}
	dp[ k ] = 0 ;
	for ( int i = 0 ; i < M[ k ] . size() ; i ++ )
	{
		dp[ k ] += dfs( M[ k ][ i ] ) ;
	}
	return dp[ k ] ;
}
int main ()
{
	int t = in() , Case = 1 ;
	while ( t -- )
	{
		int n = in() ;
		bool ck[ 1001 ] = {} ;
		for ( int i = 1 , q ; i <= n ; i ++ )
		{
			q = in() ;
			if ( q ) ck[ i ] = true ;
			while ( q -- ) M[ i ] . phb( in() ) ;
		}
		bool res = false ;
		for ( int i = 1 ; i <= n ; i ++ )
		{
			if ( !ck[ i ] )
			{
				memset( dp , 255 , sizeof( dp ) ) ;
				dp[ i ] = 1 ;
				for ( int j = 1 ; j <= n ; j ++ )
				{
					if ( dp[ j ] == -1 )
					{
						dfs( j ) ;
					}
					if ( dp[ j ] > 1 )
					{
						res = true ;
						break ;
					}
				}
				if ( res == true )
				{
					break ;
				}
			}
		}
		printf( "Case #%d: " , Case ++ ) ;
		puts( res ? "Yes" : "No" ) ;
		for ( int i = 1 ; i <= n ; i ++ )
		{
			M[ i ] . clear() ;
		}
	}
}
