#include <stdio.h>

int main() {
    int T;
    scanf( "%d", &T );

    for( int tt = 1; tt <= T; tt ++ ) {
        double C, F, X;
        scanf( "%lf %lf %lf", &C, &F, &X );

        double time = 0;
        double result = 100000;
        for( int i = 0; i <= 100000; i ++ ) {
            double cps = 2 + F * i;
            if( result > X / cps + time ) {
                result = X / cps + time;
            }
            time += ( C / cps );
        }
        printf( "Case #%d: %.10f\n", tt, result );
    }
    return 0;
}
