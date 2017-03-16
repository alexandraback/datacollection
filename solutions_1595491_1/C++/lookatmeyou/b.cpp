#include <stdio.h>
inline int is_ok( int x, int p ) {
    int j = x - p * 3;
    if ( j >= -2 ) return 1;
    if ( j >= -4 ) {
        if ( p <= 1 ) return 0;
        return 2;
    }
    return 0;
}
int main( int argc, char *argv[] )
{
    //freopen( "B-large.in", "r", stdin );
    //freopen( "B-large.out", "w", stdout );
    int te, i, cas = 0, n, s, p, r;
    int t[104], j;
    scanf( "%d", &te );
    while ( te-- ) {
        scanf( "%d%d%d", &n, &s, &p );
        r = 0;
        for ( i = 0; i < n; ++i ) {
            scanf( "%d", t + i );
        }
        for ( i = 0; i < n; ++i ) {
            j = is_ok( t[i], p );
            if ( j == 0 ) continue;
            if ( j == 1 ) ++r;
            else {
                if ( s > 0 ) --s, ++r;
            }
        }
        printf( "Case #%d: %d\n", ++cas, r );
    }
    return 0;
}
