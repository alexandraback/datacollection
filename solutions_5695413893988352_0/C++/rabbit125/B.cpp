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
#define MAX       1200
/* Time Evaluation */
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
/* EPS */
const double eps = 1e-7 ;
using namespace std ;
/* Start Code Here */
char sc[ 2 ][ MAX ] ;
int len ;
LLI gap ;
struct ANS
{
    LLI a, b, c ;
    char aa[20], bb[20] ;
};
vector <ANS> pos_ans;
bool cmp( ANS a, ANS b )
{
    if( a.c < b.c )
        return 1 ;
    if( a.c == b.c && a.a < b.a )
        return 1 ;
    if( a.c == b.c && a.a == b.a && a.b < b.b )
        return 1 ;
    return 0 ;
}
void DFS( int dep )
{
    LLI tmp_gap = 0 ;
    //printf("dd %d\n" , dep ) ;
    if( dep == len )
    {
        ANS pos ;
        //printf( "%s %s\n" , sc[0], sc[1] ) ;
        pos.a = pos.b = pos.c = 0 ;
        for( int i = 0 ; i < len ; i++ )
        {
            if( i )
                pos.a *= 10 ;
            pos.a += sc[0][i] - '0' ;
        }
        for( int i = 0 ; i < len ; i++ )
        {
            if( i )
                pos.b *= 10 ;
            pos.b += sc[1][i] - '0' ;
        }
        pos.c = abs( pos.a - pos.b ) ;
        strcpy(pos.aa, sc[0] );
        strcpy(pos.bb, sc[1] );
        gap = min( gap, pos.c ) ;
        pos_ans.push_back( pos ) ;
        //printf( "xxx %lld %lld %lld\n" , pos.a, pos.b, pos.c ) ;
        return ;
    }
    if( sc[0][dep] == '?' && sc[1][dep] == '?' )
    {
        for( int i = 0 ; i <= 9 ; i++ )
            for( int j = 0 ; j <= 9 ; j++ )
            {
                sc[0][dep] = '0' + i ;
                sc[1][dep] = '0' + j ;
                tmp_gap = abs((sc[0][dep]-'0') - (sc[1][dep]-'0')) ;
                for( int k = 0 ; k < len-1-dep ; k++ )
                    tmp_gap *= 10 ;
                //if( tmp_gap < gap )
                    DFS( dep+1 ) ;
            }
        sc[0][dep] = '?' ;
        sc[1][dep] = '?' ;
    }
    else if( sc[0][dep] == '?' )
    {
        for( int i = 0 ; i <= 9 ; i++ )
        {
            sc[0][dep] = '0' + i ;
            tmp_gap = abs((sc[0][dep]-'0') - (sc[1][dep]-'0')) ;
            for( int k = 0 ; k < len-1-dep ; k++ )
                tmp_gap *= 10 ;
            //if( tmp_gap < gap )
                DFS( dep+1 ) ;
        }
        sc[0][dep] = '?' ;
    }
    else if( sc[1][dep] == '?' )
    {
        for( int i = 0 ; i <= 9 ; i++ )
        {
            sc[1][dep] = '0' + i ;
            tmp_gap = abs((sc[0][dep]-'0') - (sc[1][dep]-'0')) ;
            for( int k = 0 ; k < len-1-dep ; k++ )
                tmp_gap *= 10 ;
            //if( tmp_gap < gap )
                DFS( dep+1 ) ;
        }
        sc[1][dep] = '?' ;
    }
    else
        DFS( dep+1 ) ;
}
int main( )
{
    freopen( "B-small-attempt1.in" , "r" , stdin ) ;
    freopen( "B-small-attempt1.out" , "w" , stdout ) ;
    //freopen( "A-large.in" , "r" , stdin ) ;
    //freopen( "A-large.out" , "w" , stdout ) ;
    int t , T = 1 ;
    scanf( "%d" , &t ) ;
    while( t-- )
    {
        pos_ans.clear() ;
        scanf( "%s %s" , &sc[0] , &sc[1] ) ;
        len = strlen( sc[0] ) ;
        gap = LLONG_MAX ;
        DFS(0) ;
        //printf( "%d\n" , pos_ans.size() ) ;
        sort( pos_ans.begin(), pos_ans.end(), cmp ) ;
        printf( "Case #%d: %s %s\n" , T++, pos_ans[0].aa, pos_ans[0].bb ) ;
    }
    return 0 ;
}
/*
4
1? 2?
?2? ??3
? ?
?5 ?0
*/
/*
Case #1: 19 20
Case #2: 023 023
Case #3: 0 0
Case #4: 05 00
*/
