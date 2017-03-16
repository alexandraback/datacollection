#include <cstring>
#include <cstdio>

char str[ 1000001 ];

int main()
{
    int t;
    scanf( "%d", &t );
    for( int tcase = 1; tcase <= t; ++tcase )
    {
        printf( "Case #%d: ", tcase );

        int n;
        scanf( " %s %d", str, &n );
        int l = strlen( str );
        for( int i = 0; i < l; ++i )
            if( str[ i ] == 'a' || str[ i ] == 'e' ||
                str[ i ] == 'i' || str[ i ] == 'o' ||
                str[ i ] == 'u' ) str[ i ] = '1';
            else str[ i ] = '0';

        long long res = 0;
        int last = -1, cnt = 0;
        for( int i = 0; i < l; ++i )
        {
            if( str[ i ] == '0' ) ++cnt;
            else cnt = 0;
            if( cnt == n )
            {
                res += ( long long )( l - i ) * ( i - cnt - last + 1 );
                last = i - n + 1;
            }
            else if( cnt > n )
            {
                res += ( l - i );
                last = i - n + 1;
            }
        }
        printf( "%lld\n", res );
    }
}
