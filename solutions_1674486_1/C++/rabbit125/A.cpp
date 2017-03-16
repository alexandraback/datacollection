#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#define MAX 1200
using namespace std ;
int n ;
vector <int> e[ MAX ] ;
int u[ MAX ] ;
bool f ;
void DFS( int now )
{
    if( f == 1 )
    {
        u[ now ]++ ;
        if( u[ now ] >= 2 )
            f = 0 ;
        for( int i = 0 ; i < e[ now ].size( ) ; i++ )
        {
            DFS( e[ now ][ i ] ) ;
        }
    }
}
int main( )
{
    freopen( "A-large.in" , "r" , stdin ) ;
    freopen( "A_Bout.out" , "w" , stdout ) ;
    int t , T = 1 , t1 , t2 ;
    scanf( "%d" , &t ) ;
    while( t-- )
    {
        for( int i = 0 ; i < MAX ; i++ )
            e[ i ].clear( ) ;
        scanf( "%d" , &n ) ;
        for( int i = 1 ; i <= n ; i++ )
        {
            scanf( "%d" , &t1 ) ;
            for( int j = 0 ; j < t1 ; j++ )
            {
                scanf( "%d" , &t2 ) ;
                e[ i ].push_back( t2 ) ;
            }
        }
        f = 1 ;
        for( int i = 1 ; i <= n ; i++ )
        {
            if( f )
            {
                memset( u , 0 , sizeof( u ) ) ;
                DFS( i ) ;
            }
        }
        if( f == 0 )
            printf( "Case #%d: Yes\n" , T++ ) ;
        else
            printf( "Case #%d: No\n" , T++ ) ;
    }
    return 0 ;
}
