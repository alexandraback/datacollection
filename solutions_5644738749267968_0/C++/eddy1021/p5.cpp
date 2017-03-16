#include <stdio.h>
#include <algorithm>
#define N 1010
#define d double
struct XD{
    d val; int p;
}c[ N * 2 ];
bool cmp( XD x , XD y ){
    return x.val < y.val;
}
int t , n , cs;
d a[ N ] , b[ N ];
void init(){
    scanf( "%d" , &n );
    for( int i = 0 ; i < n ; i ++ ){
        scanf( "%lf" , &a[ i ] );
        c[ i ].val = a[ i ];
        c[ i ].p = 0;
    }
    for( int i = 0 ; i < n ; i ++ ){
        scanf( "%lf" , &b[ i ] );
        c[ i + n ].val = b[ i ];
        c[ i + n ].p = 1;
    }
    std::sort( a , a + n );
    std::sort( b , b + n );
    std::sort( c , c + 2 * n , cmp );
}
void solve(){
    int ans1 = 0 , ans2 = n;
    int cnta = 0 , cntb = 0;
    for( int i = 0 ; i < 2 * n ; i ++ )
        if( c[ i ].p == 1 ) cntb ++;
        else if( cntb ) cntb -- , ans1 ++;
    for( int i = 0 ; i < 2 * n ; i ++ )
        if( c[ i ].p == 0 ) cnta ++;
        else if( cnta ) cnta -- , ans2 --;
    printf( "%d %d\n" , ans1 , ans2 );
}
int main(){

    freopen( "D-small-attempt0.in" , "r" , stdin );
    freopen( "D-small-attempt0.out" , "w" , stdout );

    scanf( "%d" , &t ); while( t -- ){
        init();
        printf( "Case #%d: " , ++ cs );
        solve();
    }

    fclose( stdin ); fclose( stdout );
}
