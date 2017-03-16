#include <stdio.h>
#include <memory.h>
int bag[2000003];
int s[21];
int main( int argc, char *argv[] )
{
    //freopen( "C-small-attempt0.in", "r", stdin );
    //freopen( "C-small-attempt0.out", "w", stdout );
    int t, cas = 0, n, sum, i, j, k;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d", &n );
        sum = 0;
        for ( i = 0; i < n; ++i ) {
            scanf( "%d", s + i );
            sum += s[i];
        }
        memset( bag, 0, ( sum + 1 ) << 2 );
        bag[0] = 1;
        for ( i = 0; i < n; ++i ) {
            for ( j = sum; j >= s[i]; --j ) {
                if ( !bag[j-s[i]] ) continue;
                if ( bag[j] ) break;
                bag[j] = s[i];
            }
            if ( j >= s[i] ) break;
        }
        printf( "Case #%d:\n", ++cas );
        if ( i < n ) {
            k = j;
            printf( "%d", bag[k] );
            while ( k -= bag[k], k ) printf( " %d", bag[k] );
            putchar( '\n' );
            k = j;
            printf( "%d", s[i] );
            k -= s[i];
            while ( k ) {
                printf( " %d", bag[k] );
                k -= bag[k];
            }
            putchar( '\n' );
        }
        else {
            puts( "Impossible" );
        }
    }
    return 0;
}
