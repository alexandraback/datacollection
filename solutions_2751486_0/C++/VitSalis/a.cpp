#include <cstdio>
#include <cstring>

using namespace std;

bool check( char* s, int beg, int end, int n ) {
    int i, count = 0;
    for ( i = beg; i <= end; ++i ) {
        if ( s[ i ] == 'a' || s[ i ] == 'u' || s[ i ] == 'e' || s[ i ] == 'i' || s[ i ] == 'o' ) {
            count = 0;
        }
        else {
            ++count;
        }
        if ( count >= n ) {
            return true;
        }
    }
    return false;
}

int main() {
    freopen( "a.in", "r", stdin );
    freopen( "a.out", "w", stdout );
    int T, t, i, j, count, n, len = 0;
    char s[ 200 ];
    scanf( "%d", &T );
    for ( t = 1; t <= T; ++t ) {
        printf( "Case #%d: ", t );
        scanf( "%s%d", s, &n );
        len = strlen( s );
        count = 0;
        for ( i = 0; i < len; ++i ) {
            for ( j = i; j < len; ++j ) {
                if ( check( s, i, j, n ) ) {
                    ++count;
                }
            }
        }
        printf( "%d\n", count );
    }
    return 0;
}
