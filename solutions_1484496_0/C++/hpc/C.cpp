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
#define MAX 520
using namespace std ;
int n ;
int N[ MAX ] ;
bool u[ MAX ] ;
int tmp ;
bool f ;
char num[ 50 ] ;
map<int , string> map1 ;
void DFS( int now )
{
    if( f )
    {

        u[ now ] = 1 ;
        tmp += N[ now ] ;

        if( map1[ tmp ].compare( "" ) != 0 )
        {
            printf( "%s\n" , map1[ tmp ].c_str( ) ) ;
            int kk = 0 ;
            for( int i = 0 ; i < n ; i++ )
                if( u[ i ] == 1 )
                {
                    if( kk == 0 )
                        printf( "%d" , N[ i ] ) ;
                    else
                        printf( " %d" , N[ i ] ) ;
                    kk++ ;
                }
            printf( "\n" ) ;
            f = 0 ;
            return ;
        }
        else
        {
            //printf( "%dx%sx\n" , now , map1[ tmp ].c_str( ) ) ;
            string s = "" , b = " " , t1 ;
            int kk = 0 ;
            for( int i = 0 ; i < n ; i++ )
                if( u[ i ] == 1 )
                {
                    sprintf( num ,"%d" , N[ i ] ) ;
                    t1.assign( num ) ;
                    //printf( "%s\n" ,num ) ;
                    if( kk == 0 )
                        s += t1 ;
                    else
                        s += b + t1 ;
                    kk++ ;
                }
            map1[ tmp ] = s ;

            for( int i = now+1 ; i < n ; i++ )
            {
                if( u[ i ] == 0 )
                {
                    DFS( i ) ;
                    u[ i ] = 0 ;
                    tmp -= N[ i ] ;
                }
            }
        }
    }
    return ;
}
int main( )
{
    freopen( "C-small-attempt0.in" , "r" , stdin ) ;
    freopen( "C.out" , "w" , stdout ) ;
    int t , T = 1 ;
    scanf( "%d" , &t ) ;
    while( t-- )
    {
        scanf( "%d" , &n ) ;
        for( int i = 0 ; i < n ; i++ )
            scanf( "%d" , &N[ i ] ) ;
        sort( N , N+n ) ;
        memset( u , 0 , sizeof( u ) ) ;
        f = 1 ;
        map1.clear( ) ;
        tmp = 0 ;
        printf( "Case #%d:\n" , T++ ) ;
        DFS( 0 ) ;
    }
    return 0 ;
}
