#include <stdio.h>
#include <algorithm>
using namespace std;
struct Node {
    int id;
    double s;
};
Node node[203];
double y[203];
bool cmp( const Node &a, const Node &b ) {
    return a.s < b.s;
}
int main( int argc, char *argv[] )
{
    //freopen( "A-large.in", "r", stdin );
    //freopen( "A-large.out", "w", stdout );
    int t, cas = 0, n, i, j, n1;
    double x, k, av;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d", &n );
        x = 0;
        for ( i = 0; i < n; ++i ) {
            node[i].id = i;
            scanf( "%lf", &node[i].s );
            x += node[i].s;
        }
        sort( node, node + n, cmp );
        k = 0;
        n1 = n - 1;
        for ( i = 0; i < n1; ++i ) {
            k += node[i].s;
            if ( (k + x) / ( i + 1 ) <= node[i+1].s ) break;
        }
        j = i;
        if ( j >= n1 ) k += node[n1].s;
        av = ( k + x ) / ( j + 1 );
        for ( i = 0; i < n; ++i ) {
            if ( i <= j ) y[node[i].id] = ( av - node[i].s ) / x;
            else y[node[i].id] = 0;
        }
        printf( "Case #%d:", ++cas );
        for ( i = 0; i < n; ++i ) printf( " %.8f", y[i] * 100 );
        putchar( '\n' );
    }
    return 0;
}
