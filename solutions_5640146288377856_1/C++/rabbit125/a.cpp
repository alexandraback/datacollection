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
#define MAX    1200000
/* Time Evaluation */
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
/* EPS */
const double eps = 1e-7 ;
using namespace std ;
/* Start Code Here */
int R , C , W ;
int ans[ 20 ][ 20 ] ;
int main( )
{
    //freopen( "A-small-attempt1.in" , "r" , stdin ) ;
    //freopen( "A-small-attempt1.out" , "w" , stdout ) ;
    freopen( "A-large.in" , "r" , stdin ) ;
    freopen( "A-large.out" , "w" , stdout ) ;
    ans[ 1 ][ 1 ] = 1 ;
    ans[ 2 ][ 1 ] = 2 ;
    ans[ 2 ][ 2 ] = 2 ;
    for( int i = 3 ; i <= 10 ; i++ )
    {
        int cnt = (i-1) / 2 + (i-1) % 2 ;
        for( int j = 1 ; j <= i ; j++ )
        {
            if( i % 2 == 1 )
            {
                if( j <= cnt )
                    ans[ i ][ j ] = ans[ i-1 ][ j ] + 1 ;
                else if( j == cnt+1 )
                    ans[ i ][ j ] = ans[ i ][ j-1 ] ;
                else
                    ans[ i ][ j ] = ans[ i-1 ][ j-1 ] + 1 ;
            }
            else
            {

                if( j < cnt )
                    ans[ i ][ j ] = ans[ i-1 ][ j ] + 1 ;
                else if( j == cnt )
                    ans[ i ][ j ] = ans[ i-1 ][ j ] ;
                else if( j == cnt+1 )
                    ans[ i ][ j ] = ans[ i ][ j-1 ] + 1 ;
                else
                    ans[ i ][ j ] = ans[ i-1 ][ j-1 ] + 1 ;
            }
            R = 1 , C = i , W = j ;
            int a = R * C / W - ! (C % W) +W ;
            //printf( "%d %d %d %d\n" , i , j , ans[i][j] , a ) ;
        }
    }
    /*
    for( int i = 2 ; i <= 10 ; i++ )
        for( int j = 1 ; j <= i ; j++ )
            printf( "%d%c" , ans[ i ][ j ] , " \n"[j==i] ) ;
    */

    int t , T = 1 ;
    scanf( "%d" , &t ) ;
    while( t-- )
    {
        scanf( "%d%d%d" , &R , &C , &W ) ;
        {
            int a = R * C / W - ! (C % W) +W ;
            //printf( "Case #%d: %d\n" , T++ , ans[ C ][ W ] ) ;
            printf( "Case #%d: %d\n" , T++ , a ) ;
        }
    }
    return 0 ;
}
/*
2
1 4 2
1 7 7
*/
/*
output
*/

