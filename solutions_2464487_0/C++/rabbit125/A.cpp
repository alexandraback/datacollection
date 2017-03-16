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
#define MAX 12000
using namespace std ;
long long int R , K ;
long long int N[ MAX ][ 2 ] ;
long long F( long long ans )
{
	return (ans-1) * ans / 2 ;
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
		long long int ans = 0 ;
		while( (long long)( (2*R+1)*(ans+1) + 4*F(ans+1) ) <= K )
			ans++ ;	 
		printf( "Case #%d: %lld\n" , T++ , ans ) ;
	}
	return 0 ;
}

