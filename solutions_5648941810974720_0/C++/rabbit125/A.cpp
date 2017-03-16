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
#define MAX       2100
/* Time Evaluation */
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
/* EPS */
const double eps = 1e-7 ;
using namespace std ;
/* Start Code Here */
char s[ MAX ] ;
int tab[ 26 ] ;
int n_cnt[ 10 ] ;
char strN[ 10 ][ 100 ] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" } ;
vector <int> ans ;
void Exam( int x )
{
    int ok = 100000 ;
    for( int i = 0 ; i < strlen(strN[x]) ; i++ ){
        ok = min( ok, tab[ strN[x][i] - 'A' ] ) ;
        //printf( "%c %d\n" , strN[x][i] , ok ) ;
    }
    if( ok )
    {
        for( int i = 0 ; i < strlen(strN[x]) ; i++ )
            tab[ strN[x][i] - 'A' ] -= ok ;
        for( int i = 0 ; i < ok ; i++ )
            ans.push_back( x ) ;
    }
}
int main( )
{
    freopen( "A-small-attempt0.in" , "r" , stdin ) ;
    freopen( "A-small-attempt0.out" , "w" , stdout ) ;
    //freopen( "A-large.in" , "r" , stdin ) ;
    //freopen( "A-large.out" , "w" , stdout ) ;
    int t , T = 1 ;
    scanf( "%d" , &t ) ;
    while( t-- )
    {
        scanf( "%s" , s ) ;
        int len = strlen(s) ;
        MS0( tab ) ;
        MS0( n_cnt ) ;
        ans.clear() ;
        for( int i = 0 ; i < len ; i++ )
            tab[ s[i] - 'A' ]++ ;
        for( int i = 0 ; i <= 8 ; i += 2 )
            Exam(i) ;
        for( int i = 1 ; i <= 9 ; i += 2 )
            Exam(i) ;
        sort( ans.begin(), ans.end() ) ;
        printf( "Case #%d: " , T++  ) ;
        for( int i = 0 ; i < ans.size() ; i++ )
            printf( "%d" , ans[i] ) ;
        printf( "\n" ) ;
    }
    return 0 ;
}
/*
4
OZONETOWER
WEIGHFOXTOURIST
OURNEONFOE
ETHER
*/
/*
Case #1: 012
Case #2: 2468
Case #3: 114
Case #4: 3
*/
