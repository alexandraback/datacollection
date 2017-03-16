//Templete 2013/04/14
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
#define INF 1000000000
#define MAX 12000
using namespace std ;
double Mini = (double)1000000000 * (double)10 ;
long long int R , K ;
long long int N[ MAX ][ 2 ] ;
long long F( long long ans )
{
	return (double)(ans-1) / Mini * (double)ans / 2 ;
}
long long f( long long ans )
{
	return (double)(ans-1) * (double)ans / 2 ;
}
int main( )
{
	int T = 1 , t ;
	N[ 1 ][ 0 ] = 0 ;
	N[ 1 ][ 1 ] = 1 ;
	for( int i = 2 ; i < MAX ; i++ )
	{
		N[ i ][ 1 ] = i ;
		N[ i ][ 0 ] = N[ i-1 ][ 0 ] + i-1 ;
	}
	scanf( "%d" , &t ) ;
	while( t-- )
	{
		scanf( "%lld%lld" , &R , &K ) ;
		
		long long Max = (long long)INF , Min = 1 ;
		long long Mid ;
		
		//printf( "Case #%d: %.0lf\n" , T++ , floor( ((double)1-2*(double)R+(double)sqrt( (double)4*(double)R*(double)R-(double)4*(double)R+(double)1+(double)8*(double)K ) )/(double)4 ) ) ;
		
		while( Max > Min )
		{
			Mid = ( Max+Min ) / 2 ;
			if( (double)( (double)(Mid+1)/Mini*(double)(2*R+1) + (double)4*(double)F(Mid+1) ) <= (double)K / Mini )
				Min = Mid+1 ;
			else
				Max = Mid ;
			//printf( "%lld %lld %lld\n" , Max , Min , Mid ) ;
		}
		long long int ans = Min-100000 ;
		if( ans < 0 )
			ans = 0 ;
		//printf( "%lld\n" , ans ) ;
		while( (long long)( (2*R+1)*(ans+1) + 4*f(ans+1) ) <= K )
			ans++ ;	 
		printf( "Case #%d: %lld\n" , T++ , ans ) ;
	}
	return 0 ;
}

