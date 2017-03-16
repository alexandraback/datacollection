#include<stdio.h>

int N;

int data[ 23 ];

bool visit [ 23 ];
bool visit2[ 23 ];

bool back2( int now, int sum, int bef )
{
        if( bef < sum ) return false;
        if( bef == sum )
        {
                for( int i = 1; i <= N; i ++ )
                {
                        if( visit[ i ] )
                                printf("%d ", data[ i ] );
                }
                printf("\n" );
                for( int i = 1; i <= N; i ++ )
                {
                        if( visit2[ i ] )
                                printf("%d ", data[ i ] );
                }
                printf("\n" );
                return true;

        }
        for( int i = now + 1; i <= N; i ++ )
        {
                if( visit[ i ] ) continue;
                visit2[ i ] = true;
                if( back2( i, sum + data[ i ], bef ) ) return true;
                visit2[ i ] = false;
        }
        return false;
}

bool back( int now, int sum )
{
        for( int i = now + 1; i <= N; i ++ )
        {
                if( visit[ i ] ) continue;
                visit[ i ] = true;
                if( back2( 0, 0, sum + data[ i ] ) ) return true;
                if( back( i, sum + data[ i ] ) ) return true;
                visit[ i ] = false;
        }
        return false;
}

int main( )
{
        int T;
        scanf( "%d", &T );

        for( int tt = 1; tt <= T; tt ++ )
        {

                scanf( "%d", &N );
                for( int i = 1; i <= N; i ++ )
                {
                        scanf("%d", &data[ i ] );
                        visit[ i ] = false;
                }

                printf( "Case #%d:\n", tt );
                back( 0, 0 );

        }
        return 0;
}
