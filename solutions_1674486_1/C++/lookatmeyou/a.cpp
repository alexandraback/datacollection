#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;
struct EDGE {
    int nxt, e;
};
EDGE edge[10005];
int head[1003], idx, n;
bool vi[1003];
inline void addedge( int s, int e ) {
    edge[idx].e = e;
    edge[idx].nxt = head[s];
    head[s] = idx++;
}
bool bfs( int x ) {
    memset( vi, 0, n + 1 );
    queue<int> q;
    vi[x] = 1;
    q.push( x );
    int p, nxt;
    while ( !q.empty() ) {
        nxt = q.front();
        q.pop();
        for ( p = head[nxt]; p != -1; p = edge[p].nxt ) {
            if ( vi[edge[p].e] ) return 0;
            q.push( edge[p].e );
            vi[edge[p].e] = 1;
        }
    }
    return 1;
}
/*
bool bfs( int x ) {
    memset( vi, 0, n + 1 );
    queue<int> q;
    int p, nxt;
    for ( p = head[x]; p != -1; p = edge[p].nxt ) q.push( edge[p].e );
    while ( !q.empty() ) {
        nxt = q.front();
        q.pop();
        for ( p = head[nxt]; p != -1; p = edge[p].nxt ) {
            if ( vi[edge[p].e] ) return 0;
            vi[edge[p].e] = 1;
        }
    }
    return 1;
}
*/
int main( int argc, char *argv[] )
{
    freopen( "A-large.in", "r", stdin );
    freopen( "A-large.out", "w", stdout );
    int t, cas = 0, m, i, x;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d", &n );
        memset( head, -1, ( n + 1 ) << 2 );
        idx = 0;
        for ( i = 1; i <= n; ++i ) {
            scanf( "%d", &m );
            while ( m-- ) {
                scanf( "%d", &x );
                addedge( i, x );
            }
        }
        for ( i = 1; i <= n; ++i ) {
            if ( !bfs( i ) ) break;
        }
        printf( "Case #%d: ", ++cas );
        if ( i <= n ) puts( "Yes" );
        else puts( "No" );
    }
    return 0;
}
