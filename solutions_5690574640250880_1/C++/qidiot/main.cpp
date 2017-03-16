#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
int ans[60] , now[60];
bool check( int r , int c , int b )
{
    memset( ans , 0 , sizeof(ans) );
    if( b == 1 || r == 1 )
    {
        ans[1] = b; return true;
    }
    for( int i=r ; i>1 ; i-- )
    {
        int left = b % i;
        //cout << i << " " << b / i << " " << left << endl;
        if( b / i + ( left > 0 ? 1 : 0 ) > c ) break;
        if( b / i <= 1 ) continue;
        if( b / i > 1 )
        {
            if( left != 1 )
            {
                int zk = left;
                for( int j=1 ; j<=i ; j++ )
                {
                    ans[j] = b / i + ( zk > 0 ? 1 : 0 );
                    zk--;
                }
                return true;
            }
            else if( left == 1 )
            {
                if( b / i > 2 && i != 2 )
                {
                    int zk = left + 1;
                    for( int j=1 ; j<=i ; j++ )
                    {
                        ans[j] = b / i + ( zk > 0 ? 1 : 0 );
                        zk--;
                    }
                    ans[i]--;
                    return true;
                }
            }
        }
    }
    return false;
}
void f( int r , int c )
{
    memset( now , 0 , sizeof( now ) );
    for( int i=1 ; i<=c ; i++ )
    {
        for( int j=1 ; j<=ans[i] ; j++ ) now[j]++;
    }
    for( int i=1 ; i<=r ; i++ ) ans[i] = now[i];
    return ;
}
void print( int r , int c )
{
    for( int i=1 ; i<=r ; i++ )
    {
        int p = ans[i];
        for( int j=1 ; j<=c ; j++ )
        {
            if( i == 1 && j == 1 ) printf( "c" );
            else if( p > 0 ) printf( "." );
            else printf( "*" );
            p--;
        }
        puts( "" );
    }
}
int main()
{
    freopen("C-large.in" , "r", stdin);
    freopen("out.txt", "w", stdout);
    int t , r , c , m;
    scanf( "%d" , &t );
    for( int cas=1 ; cas<=t ; cas++ )
    {
        scanf( "%d %d %d" , &r , &c , &m );
        printf( "Case #%d:\n" , cas );
        int row = min( r , c ) , col = max( r , c );
        if( check( row , col , r*c-m ) )
        {
            if( r != row ) f( r , c );
            print( r , c );
        }
        else puts( "Impossible" );
    }
    return 0;
}
