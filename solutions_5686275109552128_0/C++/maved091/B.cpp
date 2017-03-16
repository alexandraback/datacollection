/*
 * CODEJAM
 * Problem A: Infinite House of Pancakes
 * By: maved091 - mavd09
 */

#include <bits/stdc++.h>

#define FILE 	1
#define INPUT 	"BSmall.in"
#define OUTPUT 	"BSmall.out"

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
//bool visited[ MAX ][ MAX ];

int solve( int* P ) {

    int i, ret, cant;
    for( i = 1000; i >= 0; i-- )
        if( P[i] ) break;

    /*if( visited[i][ P[i] ] ) return 800000;
    visited[i][ P[i] ] = true;*/

    if( i <= 3 ) return i;
    ret = i;
    cant = P[ i ];

    /// First option
    if( cant < i ) {
        P[ i/2-1 ] += cant; P[ (i+1)/2+1 ] += cant; P[ i ] = 0;
        ret = min( ret, cant+solve( P ) );
        P[ i/2-1 ] -= cant; P[ (i+1)/2+1 ] -= cant; P[ i ] = cant;

        P[ i/2 ] += cant; P[ (i+1)/2 ] += cant; P[ i ] = 0;
        ret = min( ret, cant+solve( P ) );
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
        //memset( visited, false, sizeof(visited) );
        for( int i = 0; i < D; i++ ) cin >> p, P[p]++;
        cout << "Case #" << t << ": " << solve( P ) << "\n";
    }

    return 0;
}
