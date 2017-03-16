#include <cstdio>
#include <queue>
#include <unordered_map>

using namespace std;

int rev( int a )
{
    int res = 0;
    while( a > 0 )
    {
        res *= 10;
        res += a % 10;
        a /= 10;
    }
    return res;
}

int bfs( int t )
{
    unordered_map< int, int > M;
    queue< pair< int, int > > Q;
    
    Q.push( make_pair( 1, 1 ) );

    while( !Q.empty() )
    {
        int v = Q.front().first;
        int d = Q.front().second;
        //printf( "%d %d\n", v, d );
        Q.pop();

        if( M.count( v ) == 0 )
        {
            M[ v ] = d;
            Q.push( make_pair( v + 1, d + 1 ) );
            Q.push( make_pair( rev( v ), d + 1 ) );

            if( v == t )
                return d;
        }
    }
}

int main()
{
    int t;
    scanf( "%d", &t );

    for( int z = 1; z <= t; z++ )
    {
        int n;
        scanf( "%d", &n );

        printf( "Case #%d: %d\n", z, bfs( n ) );
    }
}
