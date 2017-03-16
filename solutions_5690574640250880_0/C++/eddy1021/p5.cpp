#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
#define N 6
bool got;
int t , r , c , x , cs , a[ N ][ N ];
int dr[]={-1,-1,-1,0,1,1,1,0};
int dc[]={-1,0,1,1,1,0,-1,-1};
bool in( int tr , int tc ){
    if( tr < 1 || tc < 1 || tr > r || tc > c )
        return false;
    return true;
}
int count( int tr , int tc ){
    int tcnt = 0;
    for( int i = 0 ; i < 8 ; i ++ )
        if( in( tr + dr[ i ] , tc + dc[ i ] ) &&
                a[ tr + dr[ i ] ][ tc + dc[ i ] ] )
                    tcnt ++;
    return tcnt;
}
bool tag[ N ][ N ];
void check( int tr , int tc ){
    queue< pair<int,int> > Q;
    memset( tag , 0 , sizeof( tag ) );
    tag[ tr ][ tc ] = true;
    Q.push( make_pair( tr , tc ) );
    while( Q.size() ){
        pair<int,int> pr = Q.front(); Q.pop();
        int nr = pr.first , nc = pr.second;
        for( int i = 0 ; i < 8 ; i ++ )
            if( in( nr + dr[ i ] , nc + dc[ i ] ) ){
                if( count( nr + dr[ i ] , nc + dc[ i ] ) == 0 &&
                        !tag[ nr + dr[ i ] ][ nc + dc[ i ] ] )
                    Q.push( make_pair( nr + dr[ i ] , nc + dc[ i ] ) );
                tag[ nr + dr[ i ] ][ nc + dc[ i ] ] = true;
            }
    }
    for( int i = 1 ; i <= r ; i ++ )
        for( int j = 1 ; j <= c ; j ++ )
            if( !a[ i ][ j ] && !tag[ i ][ j ] )
                return;
    for( int i = 1 ; i <= r ; i ++ , puts( "" ) )
        for( int j = 1 ; j <= c ; j ++ )
            if( a[ i ][ j ] ) putchar( '*' );
            else if( i == tr && j == tc ) putchar( 'c' );
            else putchar( '.' );
    got = true;
}
void DFS( int nr , int nc , int lft ){
    if( got ) return;
    if( nc > c ) nr ++ , nc = 1;
    if( nr <= r && ( r - nr ) * c + c - nc + 1 < lft )
        return;
    if( nr > r || lft == 0 ){
        if( lft > 0 ) return;
        for( int i = 1 ; i <= r ; i ++ )
            for( int j = 1 ; j <= c ; j ++ )
                if( a[ i ][ j ] == 0 && count( i , j ) == 0 ){
                    check( i , j ); return;
                }
        return;
    }
    DFS( nr , nc + 1 , lft );
    a[ nr ][ nc ] = 1;
    DFS( nr , nc + 1 , lft - 1 );
    a[ nr ][ nc ] = 0;
}
bool solve(){
    if( r * c == x + 1 ){
        for( int i = 1 ; i <= r ; i ++ , puts( "" ) )
            for( int j = 1 ; j <= c ; j ++ )
                if( i == r && j == c ) putchar( 'c' );
                else putchar( '*' );
        return true;
    }
    got = false;
    memset( a , 0 , sizeof( a ) );
    DFS( 1 , 1 , x );
    return got;
}
int main(){

    freopen( "C-small-attempt1.in" , "r" , stdin );
    freopen( "C-small-attempt1.out" , "w" , stdout );

    scanf( "%d" , &t ); while( t -- ){
        scanf( "%d%d%d" , &r , &c , &x );
        printf( "Case #%d:\n" , ++ cs );
        if( !solve() ) puts( "Impossible" );
    }

    fclose( stdin ); fclose( stdout );
}
