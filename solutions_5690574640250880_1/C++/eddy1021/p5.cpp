#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
#define N 60
int min( int x , int y ){ return x<y?x:y; }
int t , r , c , a[ N ][ N ] , x , cs;
void build(){
    memset( a , 0 , sizeof( a ) );
    int ridx = 1 , cidx = 1 , rl = r , cl = c , lft = x;
    while( lft >= min( rl , cl ) ){
        if( !( lft % rl ) && lft / rl < cl - 1 ){
            while( lft ){
                for( int i = 0 ; i < rl ; i ++ )
                    a[ ridx + i ][ cidx ] = 1;
                cl --; cidx ++; lft -= rl;
            }
            break;
        }
        if( !( lft % cl ) && lft / cl < rl - 1 ){
            while( lft ){
                for( int i = 0 ; i < cl ; i ++ )
                    a[ ridx ][ cidx + i ] = 1;
                rl --; ridx ++; lft -= cl;
            }
            break;
        }
        if( rl < cl ){
            for( int i = 0 ; i < rl ; i ++ )
                a[ ridx + i ][ cidx ] = 1;
            cl --; cidx ++; lft -= rl;
        }else{
            for( int i = 0 ; i < cl ; i ++ )
                a[ ridx ][ cidx + i ] = 1;
            rl --; ridx ++; lft -= cl;
        }
    }
    if( rl > cl ){
        for( int i = 0 ; i < lft ; i ++ )
            a[ ridx + i ][ cidx ] = 1;
    }else{
        if( lft == cl - 1 ) a[ ridx + 1 ][ cidx ] = 1 , lft --;
        for( int i = 0 ; i < lft ; i ++ )
            a[ ridx ][ cidx + i ] = 1;
    }
}
bool in( int tr , int tc ){
    if( tr < 1 || tc < 1 || tr > r || tc > c )
        return false;
    return true;
}
bool got[ N ][ N ];
int dr[]={-1,-1,-1,0,1,1,1,0};
int dc[]={-1,0,1,1,1,0,-1,-1};
int count( int tr , int tc ){
    int tcnt = 0;
    for( int i = 0 ; i < 8 ; i ++ )
        if( in( tr + dr[ i ] , tc + dc[ i ] ) &&
                a[ tr + dr[ i ] ][ tc + dc[ i ] ] == 1 )
            tcnt ++;
    return tcnt;
}
queue< pair<int,int> > Q;
bool check( int tr , int tc ){
    memset( got , 0 , sizeof( got ) );
    got[ tr ][ tc ] = true;
    Q.push( make_pair( tr , tc ) );
    while( Q.size() ){
        pair<int,int> pr = Q.front(); Q.pop();
        int nr = pr.first , nc = pr.second;
        for( int i = 0 ; i < 8 ; i ++ )
            if( in( nr + dr[ i ] , nc + dc[ i ] ) ){
                if( count( nr + dr[ i ] , nc + dc[ i ] ) == 0 &&
                        !got[ nr + dr[ i ] ][ nc + dc[ i ] ] )
                    Q.push( make_pair( nr + dr[ i ] , nc + dc[ i ] ) );
                got[ nr + dr[ i ] ][ nc + dc[ i ] ] = true;
            }
    }
    for( int i = 1 ; i <= r ; i ++ )
        for( int j = 1 ; j <= c ; j ++ )
            if( !a[ i ][ j ] && !got[ i ][ j ] )
                return false;
    for( int i = 1 ; i <= r ; i ++ , puts( "" ) )
        for( int j = 1 ; j <= c ; j ++ )
            if( a[ i ][ j ] ) putchar( '*' );
            else if( i == tr && j == tc ) putchar( 'c' );
            else putchar( '.' );
    return true;
}
bool solve(){
    if( r * c == x + 1 ){
        for( int i = 1 ; i <= r ; i ++ , puts( "" ) )
            for( int j = 1 ; j <= c ; j ++ )
                if( i == r && j == c ) putchar( 'c' );
                else putchar( '*' );
        return true;
    }
    for( int i = 1 ; i <= r ; i ++ )
        for( int j = 1 ; j <= c ; j ++ )
            if( !a[ i ][ j ] && count( i , j ) == 0 )
                return check( i , j );
    return false;
}
int main(){

    freopen( "C-large.in" , "r" , stdin );
    freopen( "C-large.out" , "w" , stdout );

    scanf( "%d" , &t ); while( t -- ){
        scanf( "%d%d%d" , &r , &c , &x );
        printf( "Case #%d:\n" , ++ cs );
        build();
        if( !solve() ) puts( "Impossible" );
    }

    fclose( stdin ); fclose( stdout );
}
