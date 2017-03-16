// Google Code Jam Template by rabbit125 @2014/05/04
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
#include <utility>
#include <climits>
#include <bits/stdc++.h>
using namespace std ;
/* Define Useful Vars. */
#define ULL  unsigned long long
#define LLI           long long
#define BIT            17
#define INF    1000000000 // 1e9
#define MOD    1000000007 // prime 1e9+7
#define STRMAX      12000
#define MAX            41
LLI P , Q ;
LLI Bt[ MAX ] ;
LLI gcd( LLI a , LLI b )
{
	if( b == 0 )
		return a ;
	return gcd( b , a%b ) ;
}
int main( )
{
    //freopen( "A-small-attempt0.in" , "r" , stdin ) ;
    //freopen( "A-s0.out" , "w" , stdout ) ;
    Bt[ 0 ] = 1 ;
    for( int i = 1 ; i < MAX ; i++ )
        Bt[ i ] = Bt[ i-1 ] * 2 ;
    int t , T = 1 ;
    scanf( "%d" , &t ) ;
    while( t-- )
    {
        scanf( "%lld/%lld" , &P , &Q ) ;
        LLI GCD = gcd( P , Q ) ;
        P /= GCD ;
        Q /= GCD ;
        int Gen = -1 ;
        for( int i = 0 ; i < MAX ; i++ )
            if( Q == Bt[i] )
            {
                Gen = i ;
                break ;
            }
        if( Gen == -1 )
            printf( "Case #%d: impossible\n" , T++ ) ;
        else
        {
            int X = 63 - __builtin_clzll( P ) ;
            printf( "Case #%d: %d\n" , T++ , Gen-X ) ;
        }
    }
    return 0 ;
}
/*
5
1/2
3/4
1/4
2/23
123/31488
*/
/*
Case #1: 1
Case #2: 1
Case #3: 2
Case #4: impossible
Case #5: 8
*/
