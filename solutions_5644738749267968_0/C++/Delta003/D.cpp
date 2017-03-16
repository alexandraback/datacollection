#include <cstdio>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;

const int maxn = 1000 + 5;

int cases, n;
double naomi[ maxn ], ken[ maxn ];
set < double > S;
deque < double > DQ;

int play_war()
{
    S.clear();
    for ( int i = 0; i < n; i++ ) S.insert( ken[ i ] );
    for ( int i = 0; i < n; i++ )
    {
        set < double > :: iterator it = S.upper_bound( naomi[ i ] );
        if ( it == S.end() ) return n - i;
        S.erase( it );
    }
    return 0;
}

int play_new()
{
    DQ.clear();
    for ( int i = 0; i < n; i++ ) DQ.push_back( naomi[ i ] );
    int currKen = n - 1, ret = 0;
    while ( ! DQ.empty() )
    {
        if ( DQ.back() > ken[ currKen ] )
        {
            ret++;
            currKen--;
            DQ.pop_back();
        }
        else
        {
            DQ.pop_front();
            currKen--;
        }
    }
    return ret;
}

int main()
{
    freopen( "D.in", "r", stdin );
    freopen( "D.out", "w", stdout );
    scanf( "%d", &cases );
    for ( int k = 1; k <= cases; k++ )
    {
        scanf( "%d", &n );
        for ( int i = 0; i < n; i++ ) scanf( "%lf", &naomi[ i ] );
        for ( int i = 0; i < n; i++ ) scanf( "%lf", &ken[ i ] );
        sort( naomi, naomi + n );
        sort( ken, ken + n );
        printf( "Case #%d: ", k );
        printf( "%d ", play_new() );
        printf( "%d\n", play_war() );
    }
    return 0;
}
