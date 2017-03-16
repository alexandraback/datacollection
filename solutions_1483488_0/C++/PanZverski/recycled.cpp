#include <stdio.h>
#include <vector>
#include <algorithm>

typedef std::vector< int > CIntVec;

int main()
{
    int tests;
    scanf( "%d", &tests );
    for( int test = 1; test <= tests; ++test )
    {
        int a, b;
        scanf( "%d %d", &a, &b );
        int ans = 0;
        for( int x = a; x <= b; ++ x )
        {
            int p = 1, n = 0;
            for( int i = x; i > 0; i /= 10 )
            {
                p *= 10;
                ++ n;
            }
            p /= 10;

            CIntVec r;

            int y = x;
            for( int i = 1; i < n; ++ i )
            {
                y = y/10 + p * (y % 10 );
                if( y >= p && a <= y && y <= b && y > x && std::find( r.begin(), r.end(), y ) == r.end() )
                {
                    r.push_back( y );
                    ++ ans;
                }
            }
        }

        printf( "Case #%d: %d\n", test, ans ); 
    }

    return 0;
}

