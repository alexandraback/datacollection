#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
//#include <pair>
#include <algorithm>

using namespace std;
typedef unsigned long long LL;
int fk, e, r, n, v, res;
int val[ 15 ];
void dfs( int now, int id, int get )
{
    if ( now == 0 )
    {
        res = max( res, get );
        return;
    }
    if ( id == n )
    {
        res = max( res, get );
        return;
    }
    for ( int i = 0; i <= now; i++ )
    {
        int tt = now - i + r;
        if ( tt > e )
        tt = e;
        dfs( tt, id + 1, get + val[ id ] * i  );
    }
}
int main()
{
    //LL t, r;

    freopen( "B-small-attempt1.in", "r", stdin );
    freopen( "B-small-attempt1.out", "w", stdout );
    int cas;
    scanf( "%d", &cas );
    while ( cas-- )
    {
        cin >> e >> r >> n;
        res = 0;
        for ( int i = 0; i < n; i++ )
        {
            cin >> val[ i ];
        }
        dfs( e, 0, 0 );
        printf( "Case #%d: %d\n", ++fk, res );
    }
    return 0;
}
