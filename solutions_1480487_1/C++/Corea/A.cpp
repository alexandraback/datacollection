#include <stdio.h>

int N, S;


int data[ 203 ];


void process( )
{
        double st, en, mid;
        int aa, i, j ;

        for( i = 1; i <= N; i ++ )
        {
                st = 0.0;
                en = 1.0;

                for( aa = 0; aa < 50; aa ++ )
                {
                        mid = ( st + en ) / 2.0;


                        double score = data[ i ] + S * mid;
                        double rest = 1.0 - mid;
                        for( j = 1; j <= N; j ++ )
                        {
                                if( i == j ) continue;
                                if( (double) data[ j ] >= score ) continue;
                                double temp = score - data[ j ];
                                temp /= S;
                                rest -= temp;

                        }
                        if( rest <= 0.0 )
                                en = mid;
                        else
                                st = mid;
                }
                printf( "%lf ", mid * 100.0 );
        }
        printf("\n");

}

int main( )
{
        int T;
        scanf( "%d", &T );

        for( int tt = 1; tt <= T; tt ++ )
        {
                scanf( "%d", &N );
                S = 0;
                for( int i = 1; i <= N; i ++ )
                {
                        scanf( "%d", &data[ i ] );
                        S += data[ i ];
                }

                printf( "Case #%d: ", tt );
                process() ;

        }
        return 0;
}
