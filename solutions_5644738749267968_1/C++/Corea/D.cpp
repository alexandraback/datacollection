#include <stdio.h>
#include <algorithm>

using namespace std;

int N;

double A[ 1003 ];
double B[ 1003 ];

int DeceitfulWar() {
    for( int rr = 0; rr <= N; rr ++ ) {
        bool status = true;
        for( int i = N; i >= 1 + rr; i -- ) {
            if( A[ i ] < B[ i - rr ] ) {
                status = false;
                break;
            }
        }
        if( status ) {
            return N - rr;
        }
    }
    return 0;
}
int War() {
    int ret = 0;
    double tmp[ 1003 ];
    for( int i = 1; i <= N; i ++ ) {
        tmp[ i ] = B[ i ];
    }
    tmp[ 0 ] = 10000;

    for( int i = 1; i <= N; i ++ ) {
        int k = 0;
        for( int j = 1; j <= N; j ++ ) {
            if( tmp[ j ] == -1 ) {
                continue;
            }
            if( A[ i ] < tmp[ j ] && tmp[ k ] > tmp[ j ] ) {
                k = j;
            }
        }
        if( k == 0 ) {
            for( int j = 1; j <= N; j ++ ) {
                if( tmp[ j ] != -1 ) {
                    tmp[ j ] = -1;
                    break;
                }
            }
            ret ++;
        } else {
            tmp[ k ] = -1;
        }
    }
    return ret;
}

int main() {
    int T;
    scanf( "%d", &T );

    for( int tt = 1; tt <= T; tt ++ ) {
        scanf( "%d", &N );
        for( int i = 1; i <= N; i ++ ) {
            scanf( "%lf", &A[ i ] );
        }
        for( int i = 1; i <= N; i ++ ) {
            scanf( "%lf", &B[ i ] );
        }

        sort( A + 1, A + N + 1 );
        sort( B + 1, B + N + 1 );

        printf( "Case #%d: %d %d\n", tt, DeceitfulWar(), War() );
    }

    return 0;
}
