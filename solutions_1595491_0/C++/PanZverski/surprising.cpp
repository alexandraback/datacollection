#include <stdio.h>

int main()
{
    int tests;
    scanf( "%d", &tests );
    for( int test = 1; test <= tests; ++ test )
    {
        int n, s, p;
        scanf( "%d %d %d", &n, &s, &p );
        
        int ans = 0;
        for( int i = 0; i < n; ++ i )
        {
            int t;
            scanf( "%d", &t );
            int max = t/3;
            if( t%3 > 0 )
                ++ max;

            if( max >= p )
            {
                ++ ans;
            }
            else if( s > 0 && max + 1 >= p && t >= 2 && t%3 != 1 )
            {
                ++ ans;
                -- s;
            }
        }

        printf( "Case #%d: %d\n", test, ans );
    }

    return 0;
}
