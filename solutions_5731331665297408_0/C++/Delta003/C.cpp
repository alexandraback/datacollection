#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int t, n, m, a, b;
string zip[ 10 ];
vector < int > order, road, adj[ 10 ];

bool get( int goal )
{
    while ( ! road.empty() )
    {
        int curr = road.back();
        for ( vector < int > :: iterator it = adj[ curr ].begin(); it != adj[ curr ].end(); it++ )
            if ( *it == goal ) return true;
        road.pop_back();
    }
    return false;
}

bool possible()
{
    bool ret = true;
    road.clear();
    road.push_back( order[ 0 ] );
    for ( int i = 1; i < n; i++ )
    {
        if ( ! get( order[ i ] ) )
        {
            ret = false;
            break;
        }
        road.push_back( order[ i ] );
    }
    return ret;
}

int main()
{
    freopen( "C.in", "r", stdin );
    freopen( "C.out", "w", stdout );
    scanf( "%d", &t );
    for ( int curr_t = 1; curr_t <= t; curr_t++ )
    {
        scanf( "%d %d", &n, &m );
        for ( int i = 0; i < n; i++ )
        {
            cin >> zip[ i ];
            adj[ i ].clear();
        }
        for ( int i = 0; i < m; i++ )
        {
            scanf( "%d %d", &a, &b );
            adj[ a - 1 ].push_back( b - 1 );
            adj[ b - 1 ].push_back( a - 1 );
        }
        order.clear();
        for ( int i = 0; i < n; i++ ) order.push_back( i );
        string sol = "";
        for ( int i = 0; i < 5 * n; i++ ) sol += "9";
        do
        {
            string curr = "";
            for ( int i = 0; i < n; i++ ) curr += zip[ order[ i ] ];
            if ( curr < sol && possible() ) sol = curr;
        } while ( next_permutation( order.begin(), order.end() ) );
        printf( "Case #%d: ", curr_t );
        cout << sol << endl;
    }
    return 0;
}
