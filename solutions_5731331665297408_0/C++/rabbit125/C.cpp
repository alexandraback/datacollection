// Google Code Jam Template by rabbit125 @2014/02/13
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
#define LLI  long long
#define BIT         17
#define INF 1000000000
#define MOD 1000000007
#define MAX        120
vector <string> vs ;
int n , m ;
int edge[ MAX ][ MAX ] ;
string zip[ MAX ] , Z ;
char z[ 7 ] ;
int main( )
{
    freopen( "C-small-attempt0.in" , "r" , stdin ) ;
    freopen( "C-s0.out" , "w" , stdout ) ;
    int t , T = 1 ;
    scanf( "%d" , &t ) ;
    while( t-- )
    {
        memset( edge , 0 , sizeof( edge ) ) ;
        vs.clear() ;
        scanf( "%d%d" , &n , &m ) ;
        string now ;
        int num[ MAX ] = { 0 } ;
        for( int i = 1 ; i <= n ; i++ )
        {
            scanf( "%s" , z ) ;
            zip[i].assign( z ) ;
            num[ i-1 ] = i ;
            //printf( "xxy\n" ) ;
        }
        for( int i = 1 ; i <= m ; i++ )
        {
            int a , b ;
            scanf( "%d%d" , &a , &b ) ;
            edge[ a ][ b ] = 1 ;
            edge[ b ][ a ] = 1 ;
            //printf( "xx\n" ) ;
        }
        if( n > 1 )
        {
            do{
                //cout << num[0] << " " << num[1] << " " << num[2] << endl;
                Z = zip[ num[0] ] ;
                vector<int> vis ;
                bool ok = 0 ;
                for( int i = 0 ; i < n-1 ; i++ )
                {
                    ok = 0 ;
                    for( int j = i ; j >= 0 && ( j == i || edge[ num[j+1] ][ num[j] ] == 3 ) ; j-- )
                    {
                        if( edge[ num[j] ][ num[i+1] ] == 1 )
                        {
                            Z += zip[ num[i+1] ] ;
                            edge[ num[i+1] ][ num[j] ] = 3 ;
                            edge[ num[j] ][ num[i+1] ] = 2 ;
                            vis.push_back( num[j] ) ;
                            ok = 1 ;
                            break ;
                        }
                    }
                    if( !ok )
                        break ;
                }
                //printf( "%d\n" , ok ) ;
                if( ok )
                {
                    vs.push_back( Z ) ;
                    //printf( "xxx %s\n" , Z.c_str() ) ;
                }
                for( int i = 0 ; i <= n ; i++ )
                    for( int j = 0 ; j <= n ; j++ )
                        if( edge[i][j] > 0 )
                            edge[i][j] = 1 ;

            }while( next_permutation( num , num + n ) ) ;
            sort( vs.begin() , vs.end() ) ;
            printf( "Case #%d: %s\n" , T++ , vs[0].c_str() ) ;
        }
        else
            printf( "Case #%d: %s\n" , T++ , zip[1].c_str() ) ;
    }
    return 0 ;
}
/*
4
3 2
10001
20000
10000
1 2
2 3
5 4
36642
28444
50012
29651
10953
1 4
2 3
2 5
4 5
5 5
36642
28444
50012
29651
10953
1 2
1 4
2 3
2 5
4 5
6 6
10001
10002
10003
10004
10005
10006
1 2
1 6
2 3
2 4
3 5
4 5
*/
/*
Case #1: 100002000010001
Case #2: 1095328444500122965136642
Case #3: 1095328444366422965150012
Case #4: 100011000210003100041000510006
*/
