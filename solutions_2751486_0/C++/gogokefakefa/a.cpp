#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char a[1 << 20];
int N, n;
int cnt[1 << 20];

long long solve(){
    scanf ( "%s%d", a, &n );
    N = strlen ( a );
    memset ( cnt, 0, sizeof ( cnt ) );

    for ( int i = N - 1; i >= 0; --i )
        if ( a[i] == 'a' || a[i] == 'e' || a[i] == 'o' || a[i] == 'i' || a[i] == 'u' )
            cnt[i] = 0;
        else
            cnt[i] = cnt[i + 1] + 1;

    long long res = 0;
    int x = N - 1;

    for ( int i = N - 1; i >= 0; --i ){
        if ( x > i - n + 1 )
            x = i - n + 1;
        while ( cnt[x] < n ){
            --x;
            if ( x < 0 )
                break;
        }
        if ( x < 0 )
            break;
        res = res + x + 1;
    }

    return res;
}

int main(){
    int tests;

    scanf ( "%d", &tests );

    for ( int i = 1; i <= tests; ++i )
        printf ( "Case #%d: %lld\n", i, solve() );
}
