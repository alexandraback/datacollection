// Google Code Jam Template by rabbit125 @2015/04/18
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
LLI J, S, P, K ;
int cnt = 0 ;
void PrintA( int a , int b , int c )
{
    for( int i = 0 ; i < a ; i++ )
    for( int j = 0 ; j < b ; j++ )
    for( int k = 0 ; k < c ; k++ )
    {
        printf( "%d %d %d\n" , i+1, j+1, k+1 ) ;
        cnt++ ;
    }
}
int main( )
{
    freopen( "C-small-attempt5.in" , "r" , stdin ) ;
    freopen( "C-small-attempt5.out" , "w" , stdout ) ;
    //freopen( "A-large.in" , "r" , stdin ) ;
    //freopen( "A-large.out" , "w" , stdout ) ;
    int t , T = 1 ;
    scanf( "%d" , &t ) ;
    while( t-- )
    {
        scanf( "%lld%lld%lld%lld", &J, &P, &S, &K ) ;
        LLI kinds[4] = {0} ;
        kinds[0] = J * P ;
        kinds[1] = J * S ;
        kinds[2] = P * S ;
        kinds[3] = J * P * S ;
        LLI k2min = min( min( kinds[0], kinds[1]), kinds[2] ) ;
        LLI all_min = min( k2min, kinds[3] ) ;
        LLI ans = K * k2min ;
        ans = min( ans, kinds[3] ) ;
        printf( "Case #%d: %lld\n" , T++ , ans ) ;
        cnt = 0 ;
        /*
        map<string, int> mp[4] ;
        char tp1[ 100 ] ;
        char tp2[ 100 ] ;
        char tp3[ 100 ] ;
        char tp4[ 100 ] ;
        mp[0].clear() ; // JS
        mp[1].clear() ; // JP
        mp[2].clear() ; // PS
        mp[3].clear() ; // JPS
        int last = 0 ;
        for( int i = 0 ; i < J ; i++ )
        for( int j = 0 ; j < P ; j++ )
        for( int k = 0 ; k < S ; L++ )
        {
            for( int ck = 1, k = last ; ck < S ; ck++, k += 1, k %= S )
            {
                sprintf( tp1 , "%d-%d" , i , j ) ;
                sprintf( tp2 , "%d-%d" , i , k ) ;
                sprintf( tp3 , "%d-%d" , j , k ) ;
                sprintf( tp4 , "%d-%d-%d", i , j , k ) ;
                if( mp[0][tp1] <= K && mp[1][tp2] <= K && mp[0][tp3] <= K && mp[1][tp4] == 0 )
                {
                    mp[0][tp1]++ ;
                    mp[1][tp2]++ ;
                    printf( "%d %d %d\n", i+1, j+1, k+1 ) ;
                    last = last + 1 ;
                    last %= S ;
                    cnt++ ;
                    break ;
                }
            }
        }*/

        if( ans == kinds[3] )
        {
            PrintA( J, P, S ) ;
        }
        else
        {
            if( k2min == kinds[0] )
            {
                map<string, int> mp[2] ;
                char tp1[ 100 ] ;
                char tp2[ 100 ] ;
                mp[0].clear() ; // JS
                mp[1].clear() ; // PS
                int last = 0 ;
                for( int i = 0 ; i < J ; i++ )
                for( int j = 0 ; j < P ; j++ )
                for( int L = 0 ; L < K ; L++ )
                {
                    for( int ck = 1, k = last ; ck < S ; ck++, k += 1, k %= S )
                    {
                        sprintf( tp1 , "%d-%d" , i , k ) ;
                        sprintf( tp2 , "%d-%d" , j , k ) ;
                        if( mp[0][tp1] < K && mp[1][tp2] < K )
                        {
                            mp[0][tp1]++ ;
                            mp[1][tp2]++ ;
                            printf( "%d %d %d\n", i+1, j+1, k+1 ) ;
                            last = last + 1 ;
                            last %= S ;
                            cnt++ ;
                            break ;
                        }
                    }
                }
            }
            else if( k2min == kinds[1] )
            {
                map<string, int> mp[2] ;
                char tp1[ 100 ] ;
                char tp2[ 100 ] ;
                mp[0].clear() ; // PS
                mp[1].clear() ; // JP
                int last = 0 ;
                for( int i = 0 ; i < J ; i++ )
                for( int L = 0 ; L < K ; L++ )
                for( int j = 0 ; j < S ; j++ )
                {
                    for( int ck = 1, k = last ; ck < P ; ck++, k += 1, k %= P )
                    {
                        sprintf( tp1 , "%d-%d" , k , j ) ;
                        sprintf( tp2 , "%d-%d" , i , k ) ;
                        if( mp[0][tp1] < K && mp[1][tp2] < K )
                        {
                            mp[0][tp1]++ ;
                            mp[1][tp2]++ ;
                            printf( "%d %d %d\n", i+1, k+1, j+1 ) ;
                            last = last + 1 ;
                            last %= P ;
                            cnt++ ;
                            break ;
                        }
                    }
                }
            }
            else if( k2min == kinds[2] )
            {
                map<string, int> mp[2] ;
                char tp1[ 100 ] ;
                char tp2[ 100 ] ;
                mp[0].clear() ; // JS
                mp[1].clear() ; // JP
                int last = 0 ;
                for( int L = 0 ; L < K ; L++ )
                for( int i = 0 ; i < P ; i++ )
                for( int j = 0 ; j < S ; j++ )
                {
                    for( int ck = 1, k = last ; ck < J ; ck++, k += 1, k %= J )
                    {
                        sprintf( tp1 , "%d-%d" , k , i ) ;
                        sprintf( tp2 , "%d-%d" , k , j ) ;
                        if( mp[0][tp1] < K && mp[1][tp2] < K )
                        {
                            mp[0][tp1]++ ;
                            mp[1][tp2]++ ;
                            printf( "%d %d %d\n", k+1, i+1, j+1 ) ;
                            last = last + 1 ;
                            last %= J ;
                            cnt++ ;
                            break ;
                        }
                    }
                }
            }
        }

    }
    return 0 ;
}
/*
4
1 1 1 10
1 2 3 2
1 1 3 2
1 2 3 1
*/
/*
Case #1: 1
1 1 1
Case #2: 4
1 1 2
1 2 3
1 2 1
1 1 1
Case #3: 2
1 1 2
1 1 1
Case #4: 2
1 1 3
1 2 1
*/
/*
1
3 4 5 2
*/
