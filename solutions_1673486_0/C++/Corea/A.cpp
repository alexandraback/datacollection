#include <stdio.h>


int A, B;

double data[ 100003 ];
double prob[ 100003 ];
double count[ 100003 ];

int main ( )
{
        int T;

        scanf( "%d", &T );

        double full_count;

        for( int tt = 1; tt <= T; tt ++ )
        {
                scanf( "%d %d", &A, &B );
                prob[ 0 ] = 1.0;
                for( int i = 1; i <= A; i ++ )
                {
                        scanf( "%lf", &data[ i ] );
                        prob[ i ] = prob[ i - 1 ] * data[ i ];
                }

                count[ A ] = 1.0;
                full_count = 1.0;
                for( int i = A - 1; i >= 0; i -- )
                {
                        full_count *= 2.0;
                        count[ i ] = count[ i + 1 ] * 2.0;
                }


                double res = (B + 2);
                for( int i = A; i >= 0; i -- )
                {
                        double temp;
                        temp = prob[ i ] * (double) ( B - i + 1 + ( A - i ));
                        temp += (1.0 - prob[ i ] ) * (double) ( B + B - i + 2 + ( A - i ) );
                        if( res > temp ) res = temp;
                }
                printf("Case #%d: %.6lf\n", tt, res );
        }
        return 0;
}
