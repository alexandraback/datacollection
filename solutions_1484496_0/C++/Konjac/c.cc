#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;
const int N = 22;
int a[N], status[1<<N];
int q[1<<N];
int n;
void output ( int t ) {
    for ( int i = 0, tag = 0;i < n;++i ) {
        if ( t & ( 1 << i ) ) {
            if ( tag ) printf ( " " );
            printf ( "%d", a[i] );
            tag = 1;
        }
    }
    printf ( "\n" );
}
int hash[2000010];
void solve() {
    scanf ( "%d", &n );
    for ( int i = 0;i < n;++i )
        scanf ( "%d", a + i );
    int l = 0, r = 0;
    memset ( status, -1, sizeof ( status ) );
    memset ( hash, -1, sizeof ( hash ) );
    q[r++] = 0, status[0] = 0;
    while ( l < r ) {
        int s = q[l++];
        for ( int i = 0;i < n;++i ) {
            if ( s& ( 1 << i ) ) continue;
            int t = ( s | ( 1 << i ) );
            if ( status[t] != -1 ) continue;
            status[t] = status[s] + a[i];
            if ( hash[status[t]] != -1 ) {
                output ( t );
                output ( hash[status[t]] );
                return;
            }
            hash[status[t]] = t;
            q[r++] = t;
        }
    }
    printf ( "Impossible\n" );
    return;
}
int main() {
    int T;
    scanf ( "%d", &T );
    for ( int t = 1;t <= T;++t ) {
        printf ( "Case #%d:\n", t );
        solve();
    }
    return 0;
}