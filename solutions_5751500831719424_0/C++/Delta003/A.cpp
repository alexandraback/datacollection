#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 100 + 5;

int t, n;
char S[ maxn ];
vector < pair < char, int > > order[ maxn ];
vector < int > temp;

int main()
{
    freopen( "A-small-attempt0.in", "r", stdin );
    freopen( "A.out", "w", stdout );
    scanf( "%d", &t );
    for ( int curr_t = 1; curr_t <= t; curr_t++ )
    {
        scanf( "%d", &n );
        for ( int i = 0; i < n; i++ )
        {
            scanf( "%s", S );
            int len = strlen( S );
            order[ i ].clear();
            order[ i ].push_back( make_pair( S[ 0 ], 1 ) );
            for ( int j = 1; j < len; j++ )
                if ( S[ j ] == order[ i ].back().first ) order[ i ].back().second++;
                else order[ i ].push_back( make_pair( S[ j ], 1 ) );
        }
        bool ok_order = true;
        for ( int i = 1; i < n; i++ )
        {
            if ( order[ i ].size() != order[ 0 ].size() )
            {
                ok_order = false;
                break;
            }
            for ( int j = 0; j < order[ 0 ].size(); j++ )
                if ( order[ i ][ j ].first != order[ 0 ][ j ].first )
                {
                    ok_order = false;
                    break;
                }
            if ( ! ok_order ) break;
        }
        if ( ! ok_order )
        {
            printf( "Case #%d: Fegla Won\n", curr_t );
            continue;
        }
        int sol = 0;
        for ( int i = 0; i < order[ 0 ].size(); i++ )
        {
            temp.clear();
            for ( int j = 0; j < n; j++ ) temp.push_back( order[ j ][ i ].second );
            sort( temp.begin(), temp.end() );
            int val = temp[ n / 2 ];
            for ( int j = 0; j < n; j++ ) sol += abs( temp[ j ] - val );
        }
        printf( "Case #%d: %d\n", curr_t, sol );
    }
    return 0;
}
