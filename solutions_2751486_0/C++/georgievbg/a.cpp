#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int MAXN = 128;

int n, sz;
char s[MAXN];

void read() {
    scanf ( "%s", s );
    scanf ( "%d", &n );

}

bool is_const ( char c ) {
    if ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ) return 0;
    return 1;

}

int solve() {
    int i, j, k, cnt = 0, sz = ( int ) strlen ( s );

    for ( i = 0; i < sz; ++ i ) {
        for ( j = i; j < sz; ++ j ) {
            int br = 0;
            for ( k = i; k <= j; ++ k ) {
                if ( is_const ( s[k] ) ) br ++;
                else br = 0;

                if ( br == n ) {
                    cnt ++;
                    break;
                }

            }
        }
    }

    return cnt;

}

int main() {
    int i, tests;

    scanf ( "%d", &tests );

    for ( i = 0; i < tests; ++ i ) {
        read();
        printf ( "Case #%d: %d\n", i + 1, solve() );
    }

    return 0;

}