#include<cstdio>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int x, y;
int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
string ss[4] = { "SN", "NS", "WE", "EW" };

int mod ( int t ) {
    if ( t >= 0 ) return t;
    return -t;

}

void solve() {
    int i;

    if ( y > 0 ) {
        for ( i = 0; i < y; ++ i ) {
            cout << ss[0];
        }
    }
    if ( y < 0 ) {
        for ( i = 0; i < mod ( y ); ++ i ) {
            cout << ss[1];
        }
    }

    if ( x > 0 ) {
        for ( i = 0; i < x; ++ i ) {
            cout << ss[2];
        }
    }
    if ( x < 0 ) {
        for ( i = 0; i < mod ( x ); ++ i ) {
            cout << ss[3];
        }
    }

    cout << endl;

}

int main() {
    int i, tests;
    vector < char > v;

    scanf ( "%d", &tests );

    for ( i = 1; i <= tests; ++ i ) {
        scanf ( "%d %d", &x, &y );
        printf ( "Case #%d: ", i );
        solve();
    }

    return 0;

}