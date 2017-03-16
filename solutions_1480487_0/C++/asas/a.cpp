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
int main ()
{
	int t = in() , Case = 1 ;
	while ( t -- )
	{
		int n = in() ;
		int s[ 200 ] , m[ 200 ] = {} , c[ 200 ] ;
		int x = 0 ;
		for ( int i = 0 ; i < n ; i ++ )
		{
			x += ( c[ i ] = s[ i ] = in() ) ;
		}
		int tx = x ;
		sort( c , c + n ) ;
		for ( int i = 0 ; tx ; i ++ )
		{
			int sum = 0 ;
			for ( int j = 0 ; j < n ; j ++ )
			{
				if ( c[ j ] == i )
				{
					sum ++ ;
				}
			}
			if ( sum > tx )
			{
				break ;
			}
			for ( int j = 0 ; j < n ; j ++ )
			{
				if ( c[ j ] == i )
				{
					c[ j ] ++ ;
				}
			}
			tx -= sum ;
		}
		double v = 0 ;
		for ( int i = 0 ; i < n ; i ++ )
		{
			if ( c[ i ] == c[ 0 ] )
			{
				v ++ ;
			}
		}
		v = 1.0 * tx / v + c[ 0 ] ;
		printf( "Case #%d:" , Case ++ ) ;
		for ( int i = 0 ; i < n ; i ++ )
		{
			if ( s[ i ] >= v )
			{
				printf( " 0.0" ) ;
			}
			else
			{
				printf( " %.6lf" , ( v - s[ i ] ) / x * 100.0 ) ;
			}
		}
		puts( "" ) ;
	}
}
