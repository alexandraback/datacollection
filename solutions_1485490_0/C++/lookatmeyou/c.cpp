#include <stdio.h>
__int64 a[103], b[103];
int A[103], B[103], n, m;
__int64 cal( int p, int s, int e ) {
    __int64 t = a[p];
    int i;
    for ( i = s; i <= e; ++i ) {
        if ( A[p] == B[i] ) {
            if ( t >= b[i] ) {
                t -= b[i];
            }
            else return a[p];
        }
    }
    return a[p] - t;
}
int main( int argc, char *argv[] )
{
    freopen( "C-small-attempt0.in", "r", stdin );
    freopen( "C-small-attempt0.out", "w", stdout );
    int t, i, j, cas = 0, tA;
    __int64 ta, r, tm;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d%d", &n, &m );
        scanf( "%I64d%d", &a[1], &A[1] );
        for ( i = 2, j = 1; i <= n; ++i ) {
            scanf( "%I64d%d", &ta, &tA );
            if ( tA == A[j] ) a[j] += ta;
            else {
                ++j;
                a[j] = ta;
                A[j] = tA;
            }
        }
        n = j;
        scanf( "%I64d%d", &b[1], &B[1] );
        for ( i = 2, j = 1; i <= m; ++i ) {
            scanf( "%I64d%d", &ta, &tA );
            if ( tA == B[j] ) b[j] += ta;
            else {
                ++j;
                b[j] = ta;
                B[j] = tA;
            }
        }
        m = j;
        r = 0;
        if ( n == 1 ) r = cal( 1, 1, m );
        else if ( n == 2 ) {
            for ( i = 0; i <= m; ++i ) {
                tm = cal( 1, 1, i ) + cal( 2, i + 1, m );
                if ( tm > r ) r = tm;
            }
        }
        else if ( n == 3 ) {
            for ( i = 0; i <= m; ++i ) {
                for ( j = i; j <= m; ++j ) {
                    //printf( "####   %d  %d  %d  \n", i, j, m );
                    tm = cal( 1, 1, i ) + cal( 2, i + 1, j ) +
                        cal( 3, j + 1, m );
                    if ( tm > r ) r = tm;
                }
            }
            if ( A[1] == A[3] ) {
                a[1] += a[3];
                tm = cal( 1, 1, m );
                if ( tm > r ) r = tm;
            }
        }
        printf( "Case #%d: %I64d\n", ++cas, r );
    }
    return 0;
}
