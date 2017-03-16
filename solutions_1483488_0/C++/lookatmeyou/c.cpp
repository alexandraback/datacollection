#include <stdio.h>
#include <set>
using namespace std;
int n10[12];
inline int digits( int x ) {
    int r = 0;
    while ( x > 0 ) {
        ++r;
        x /= 10;
    }
    return r;
}
int judge( int a, int b, int n, int d ) {
    int i, m;
    set<int> s;
    for ( i = 1; i < d; ++i ) {
        m = n / n10[i] + ( n % n10[i] ) * n10[d - i];
        if ( n < m && a <= m && m <= b ) s.insert( m );
    }
    return s.size();
}
int main( int argc, char *argv[] )
{
    //freopen( "C-small-attempt0.in", "r", stdin );
    //freopen( "C-small-attempt0.out", "w", stdout );
    int t, i, a, b, r, cas = 0, d;
    n10[0] = 1;
    for ( i = 1; i < 9; ++i ) n10[i] = n10[i-1] * 10;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d%d", &a, &b );
        r = 0;
        d = digits( a );
        for ( i = a; i <= b; ++i ) {
            r += judge( a, b, i, d );
        }
        printf( "Case #%d: %d\n", ++cas, r );
    }
    return 0;
}
