/*
 * CODEJAM
 * Problem B: Infinite House of Pancakes
 * By: maved091 - mavd09
 */

#include <bits/stdc++.h>

#define FILE 	1
#define INPUT 	"BLarge.in"
#define OUTPUT 	"BLarge.out"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int(5*1e4+100)
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int nTest, D, p;
int bestEver;
bool visited[ 1100 ][ 1100 ];

int solve( int* P, int cur ) {

    if( cur > bestEver ) return 8000000;

    int i, ret, cant;
    for( i = 1000; i >= 0; i-- )
        if( P[i] ) break;

    if( i <= 3 ) return cur+i;
    ret = cur+i;
    cant = P[ i ];

    if( visited[ i ][ cant ] ) return 8000000;
    visited[ i ][ cant ] = true;

    if( cur+cant < ret ) {
        P[ i/2-1 ] += cant; P[ (i+1)/2+1 ] += cant; P[ i ] = 0;
        ret = min( ret, solve( P, cur+cant ) );
        P[ i/2-1 ] -= cant; P[ (i+1)/2+1 ] -= cant; P[ i ] = cant;

        P[ i/2 ] += cant; P[ (i+1)/2 ] += cant; P[ i ] = 0;
        ret = min( ret, solve( P, cur+cant ) );
        P[ i/2 ] -= cant; P[ (i+1)/2 ] -= cant; P[ i ] = cant;
    }

    return ret;
}

int main( ) {

    if( FILE ) {
        freopen( INPUT , "r", stdin  );
        freopen( OUTPUT, "w", stdout );
    }

    cin >> nTest;

    for( int t = 1; t <= nTest; t++ ) {
        cin >> D;
        int P[ MAX ];
        memset( P, 0, sizeof( P ) );
        memset( visited, false, sizeof( visited ) );
        bestEver = 0;
        for( int i = 0; i < D; i++ ) cin >> p, P[p]++, bestEver = max( bestEver, p );
        cout << "Case #" << t << ": " << solve( P, 0 ) << "\n";
    }

    return 0;
}
