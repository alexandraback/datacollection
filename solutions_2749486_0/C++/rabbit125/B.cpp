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
int x , y ;
int dir[ 4 ][ 2 ] = { { 0 , 1 } , { 0 , -1 } , { 1 , 0 } , { -1 , 0 } } ; 
char D[ 4 ][ 3 ] = { "EW" , "WE" , "NS" , "SN" } ;
int main( )
{
	int t , T = 1 ;
	int ans , a , b ; 
	scanf( "%d" , &t ) ;
	while( t-- )
	{
		scanf( "%d%d" , &x , &y ) ;
		printf( "Case #%d: " , T++ ) ;
		if( x >= 0 )
			a = 1 ;
		else
			a = 0 , x = -x ;
		if( y >= 0 )
			b = 3 ;
		else
			b = 2 , y = -y ;
		for( int i = 0 ; i < x ; i++ )
		{
			printf( "%s" , D[ a ] ) ;
		}
		for( int i = 0 ; i < y ; i++ )
		{
			printf( "%s" , D[ b ]  ) ;
		}
		printf( "\n" ) ;
	}
	return 0 ;
}

