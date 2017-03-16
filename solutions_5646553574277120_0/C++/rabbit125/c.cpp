// Google Code Jam Template by rabbit125 @2014/10/01
/* Libs. */
#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
/* ShortCut Vars. */
#if __WIN32__
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif // __WIN32__
#define BG   begin
#define CL   clear
#define ED   end
#define FR   first
#define MP   make_pair
#define SC   second
#define SZ   size
#define PB   push_back
#define PF   push_front
#define PPB  pop_back
#define PPF  pop_front
#define lg      std::__lg
#define __count __builtin_popcount
/* Type ShortCuts */
typedef unsigned int        UI;
typedef long long          LLI;
typedef unsigned long long ULL;
typedef long double         LD;
/* Function ShortCuts */
#define MS0(x) memset(x, 0, sizeof(x))
#define MS1(x) memset(x, -1, sizeof(x))
/* C++11 */
// __cplusplus is a int: 201103
#if __cplusplus > 201103L
    #include <tuple>
    #define MT make_tuple
    typedef tuple<int, int> TII;
#endif
/* Define Value Vars. */
#define BIT         17
#define INF 2000000000
#define MOD 1000000007
#define STRMAX    1000
#define MAX       1200
/* Time Evaluation */
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
/* EPS */
const double eps = 1e-7 ;
using namespace std ;
/* Start Code Here */
int C , D , V ;
int N[ MAX ] ;
int U[ MAX ] ;
int u[ MAX ] ;
void BK( int cnt )
{
    if( cnt == D )
    {
        int buy = 0 ;
        for( int i = 0 ; i < D ; i++ )
            if( u[ i ] == 1 )
                buy += N[i] ;
        if( buy <= V )
            U[ buy ] = 1 ;
        return ;
    }
    u[ cnt ] = 1 ;
    BK( cnt+1 ) ;
    u[ cnt ] = 0 ;
    BK( cnt+1 ) ;
}
int main( )
{
    freopen( "C-small-attempt0.in" , "r" , stdin ) ;
    freopen( "C-small-attempt0.out" , "w" , stdout ) ;
    //freopen( "C-large.in" , "r" , stdin ) ;
    //freopen( "C-large.out" , "w" , stdout ) ;
    int t , T = 1 ;
    scanf( "%d" , &t ) ;
    while( t-- )
    {
        scanf( "%d%d%d" , &C , &D , &V ) ;
        for( int i = 0 ; i < D ; i++ )
            scanf( "%d" , &N[i] ) ;
        MS0( U ) ;
        U[ 0 ] = 1 ;
        MS0( u ) ;
        BK( 0 ) ;
        int cnt = 0 ;
        for( int i = 1 ; i <= V ; i++ )
            if( U[ i ] == 0 )
            {
                cnt++ ;
                //printf( "xx %d\n" , i ) ;
            }
        printf( "Case #%d: %d\n" , T++ , cnt ) ;
    }
    return 0 ;
}
/*
4
1 2 3
1 2
1 3 6
1 2 5
2 1 3
*/
/*
output
*/

