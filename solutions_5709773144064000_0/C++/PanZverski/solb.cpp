#include <stdio.h>

int main()
{
    int tc;
    scanf("%d", &tc );
    for( int test = 1; test <= tc; ++ test )
    {
        double C, F, X;
        scanf( "%lf %lf %lf", &C, &F, &X );

        double best = X / 2.0;
        double speed = 2.0;
        double t = 0;
        while( true )
        {
            t -= - C / speed;
            speed += F;
            double new_res =  t + X / speed;
            if ( new_res >= best )
                break;

            best = new_res;
        }
        
        printf( "Case #%d: %.7lf\n", test,  best );
    }

    return 0;
}

