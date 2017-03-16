#include <cstdio>
#include <algorithm>

using namespace std;

int a, b, k, t;

int main()
{
    freopen( "B.in", "r", stdin );
    freopen( "B.out", "w", stdout );
    scanf( "%d", &t );
    for ( int curr_t = 1; curr_t <= t; curr_t++ )
    {
        scanf( "%d %d %d", &a, &b, &k );
        int sol = 0;
        for ( int i = 0; i < a; i++ )
            for ( int j = 0; j < b; j++ )
                if ( ( i & j ) < k ) sol++;
        printf( "Case #%d: %d\n", curr_t, sol );
    }
    return 0;
}
