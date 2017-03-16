/*
 * CODEJAM
 * Problem D: Ominous Omino
 * By: maved091 - mavd09
 */

#include <bits/stdc++.h>

#define FILE 	1
#define INPUT 	"DLarge.in"
#define OUTPUT 	"DLarge.out"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int(1e7+10)
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int nTest, x, r, c;
string ans[] = { "RICHARD\n", "GABRIEL\n" };

int main( ) {

    if( FILE ) {
        freopen( INPUT , "r", stdin  );
        freopen( OUTPUT, "w", stdout );
    }

    cin >> nTest;

    for( int t = 1; t <= nTest; t++ ) {
        cout << "Case #" << t << ": ";
        cin >> x >> r >> c;
        if( x == 1 ) cout << ans[1];
        else if( r*c == 1 || (r*c)%x != 0 ) cout << ans[0];
        else if( x == 2 ) cout << ans[1];
        else if( x == 3 ) {
            if( min(r, c) > 1 ) cout << ans[1];
            else cout << ans[0];
        }
        else if( x == 4 ) {
            if( min(r, c) > 2 ) cout << ans[1];
            else cout << ans[0];
        }
        else if( x == 5 ) {
            if( min(r, c) > 3 ) cout << ans[1];
            else cout << ans[0];
        }
        else if( x == 6 ) {
            if( min(r, c) > 4 ) cout << ans[1];
            else cout << ans[0];
        }
        else cout << ans[0];
    }

    return 0;
}
