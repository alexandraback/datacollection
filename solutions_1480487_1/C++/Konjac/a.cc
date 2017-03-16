#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
const int N = 220;
const double eps = 1e-8;
int rec[N];
void solve() {
    int n;
    scanf ( "%d", &n );
    int sum = 0;
    for ( int i = 0;i < n;++i ) {
        scanf ( "%d", &rec[i] );
        sum += rec[i];
    }
    for ( int i = 0;i < n;++i ) {
        double L = 0.0, R = sum;
        while ( L + eps < R ) {
            //printf ( "%f %f\n", L, R );
            double M = ( L + R ) / 2.0;
            double v = rec[i] + M;
            double rem = sum - M;
            for ( int j = 0;j < n;++j ) {
                if ( j == i ) continue;
                if ( rec[j] + eps < v )
                    rem -= v - rec[j];
            }
            //printf ( "%f %f %s\n", rem, M, rem + eps < 0 ? "True" : "False" );
            //getchar();
            if ( rem + eps < 0 ) R = M;
            else L = M;
        }
        printf ( " %.12f", R / sum * 100 );
    }
    printf ( "\n" );
    return;
}

int main() {
    int T;
    scanf ( "%d", &T );
    for ( int t = 1;t <= T;++t ) {
        printf ( "Case #%d:", t );
        solve();
    }
    return 0;
}