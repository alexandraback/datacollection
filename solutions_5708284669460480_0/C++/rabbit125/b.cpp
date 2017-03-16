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
#define MAX      12000
/* Time Evaluation */
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
/* EPS */
const double eps = 1e-7 ;
using namespace std ;
/* Start Code Here */
int K , L , S ;
char Key[ MAX ] , tar[ MAX ] ;
int P[ MAX ] , u[ MAX ] , N[ MAX ] ;
double ans , cnt , TCount , Ans ;
void BK( int Count )
{
    if( Count == S )
    {
        /*
        for( int i = 0 ; i < S ; i++ )
            printf( "%d " , P[ i ] ) ;
        */
        double cc = 0 ;
        for( int i = 0 ; i+L <= S ; i++ )
        {
            int ok = 1 ;
            for( int j = 0 ; j < L ; j++ )
                if( Key[ P[i+j] ] != tar[ j ] )
                    ok = 0 ;
            if( ok )
                cnt++ , cc++ ;
        }
        Ans = max( Ans , cc ) ;
        //printf( "%lf\n" , cnt ) ;
        TCount++ ;
        return ;
    }
    for( int i = 0 ; i < K ; i++ )
    {
        //if( u[ i ] == 0 )
        {
            u[ i ] = 1 ;
            P[ Count ] = N[ i ] ;
            BK( Count+1 ) ;
            // 注意
            u[ i ] = 0 ;
        }
    }
}
int main( )
{
    freopen( "B-small-attempt0.in" , "r" , stdin ) ;
    freopen( "B-small-attempt0.out" , "w" , stdout ) ;
    //freopen( "B-large.in" , "r" , stdin ) ;
    //freopen( "B-large.out" , "w" , stdout ) ;
    int t , T = 1 ;
    scanf( "%d" , &t ) ;
    for( int i = 0 ; i < MAX ; i++ )
        N[i] = i ;
    while( t-- )
    {
        scanf( "%d%d%d" , &K , &L , &S ) ;
        scanf( "%s%s" , Key , tar ) ;
        ans = 0.0 , cnt = 0.0 , TCount = 0.0 , Ans = 0.0 ;
        MS0( u ) ;
        BK( 0 ) ;
        ans = cnt / TCount ;
        double tmp = (double)((int)ans) ;
        if( ans - (double)((int)ans) > 0 )
            tmp = (double)((int)ans) + 1 ;
        //ans = tmp - ans ;

        //printf( "%lf %lf\n" , cnt , TCount ) ;
        printf( "Case #%d: %.8lf\n" , T++ , Ans - ans ) ;
    }
    return 0 ;
}
/*
5
7 6 6
BANANAS
MONKEY
2 3 4
AA
AAA
2 1 2
AB
B
6 2 2
GOOGLE
GO
*/
/*
output
*/

