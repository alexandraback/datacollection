#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#define MAX 250
using namespace std ;
int n ;
double p[ MAX ] ;
double a[ MAX ] ;
int main( )
{
    freopen( "A-small-attempt2.in" , "r" , stdin ) ;
    freopen( "out.txt" , "w" , stdout ) ;
    int t , T = 1 ;
    scanf( "%d" , &t ) ;
    while( t-- )
    {
        double sum = 0 , avg ;
        scanf( "%d" , &n ) ;
        for( int i = 0 ; i < n ; i++ )
        {
            scanf( "%lf" , &p[ i ] ) ;
            sum += p[ i ] ;
        }
        avg = ( sum + sum ) / n ;
        int N = n ;
        double sum2 = sum + sum ;
		for( int i = 0 ;i < n ; i++ )
		{
			if( p[i] > avg )
			{
				sum2 -= p[i] ;
                N-- ;
			}
		}
        avg = (sum2) / (double)( N );

		printf( "Case #%d: " , T++ ) ;
		for( int i = 0 ; i < n ; i++ )
		{
			double ansi = 100 * (avg - (p[i] ) ) / (double)sum ;
			printf(" %.8lf" , (ansi < 0) ? 0 : ansi ) ;
		}
        printf( "\n" ) ;

    }
    return 0 ;
}
