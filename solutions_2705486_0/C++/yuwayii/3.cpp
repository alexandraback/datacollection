#include <cstdio>
#include <cstring>

const int N = 521196;

char dict[ N ][ 50 ];
int l2[ N ];

int main()
{
    char word[ 50 ];
    FILE *file = fopen( "dict.txt", "r" );
    for( int i = 0; i < N; ++i )
    {
        fscanf( file, "%s", word );
        strcpy( dict[ i ], word );
        l2[ i ] = strlen( word );
    }
    fclose( file );
    
    int t;
    scanf( "%d", &t );
    for( int tcase = 1; tcase <= t; ++tcase )
    {
        printf( "Case #%d: ", tcase );

        char sentence[ 50 ];
        scanf( "%s", sentence );
        int l = strlen( sentence );
        int dp[ 51 ][ 5 ] = { 0 };
        for( int i = 1; i <= l; ++i ) 
            for( int j = 0; j < 5; ++j )
                dp[ i ][ j ] = 0x7FFFFFFF;

        for( int i = 1; i <= l; ++i )
        {
            for( int j = 0; j < N; ++j )
                if( l2[ j ] <= i )
                {
                    int cnt = 0, begin = -1, end = -1;
                    for( int k = 0; k < l2[ j ] && cnt >= 0; ++k )
                        if( dict[ j ][ k ] != sentence[ i - l2[ j ] + k ] )
                        {
                            if( begin == -1 ) begin = k;
                            end = l2[ j ] - 1 - k;
                            ++cnt;
                        }
                    for( int k = 0; k < 4; ++k )
                        if( begin == -1 )
                        {
                            if( dp[ i - l2[ j ] ][ k ] != 0x7FFFFFFF )
                                dp[ i ][ k ] = dp[ i - l2[ j ] ][ k ];
                        }
                        else
                        {
                            if( k + 1 + begin >= 5 &&
                                dp[ i - l2[ j ] ][ k ] != 0x7FFFFFFF &&
                                dp[ i ][ end ] > dp[ i - l2[ j ] ][ k ] + cnt )
                                dp[ i ][ end ] = dp[ i - l2[ j ] ][ k ] + cnt;
                        }
                }
        }
        int res = 0x7FFFFFFF;
        for( int i = 0; i < 5; ++i )
            if( dp[ l ][ i ] < res ) res = dp[ l ][ i ];
        printf( "%d\n", res );
    }
}
