#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#include <cassert>
#include <cmath>
#include <bitset>
#include <ctime>
#include <queue>
#include <fstream>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define pii pair< int, int >
#define GC getchar( )
#define PC putchar
#define x first
#define y second
typedef long long llint;
 
FILE *fin = fopen( "input.txt", "r" );
FILE *fout = fopen( "output.txt", "w" );

const int N = 1000005;
const int INF = 0x3f3f3f3f;
int n;
int dp[ N ];
int global;

int reverse( int x ) {
	int sol = 0;
	while( x ) {
		sol = sol * 10 + x % 10;
		x /= 10;
	}
	return sol;
}

void load( ) {
	fscanf( fin, "%d", &n );
}

void solve( ) {
	for( int i = 1; i <= n; i++ ) dp[ i ] = INF;
	dp[ 1 ] = 1;
	for( int i = 1; i <= n; i++ ) {
		dp[ i + 1 ] = min( dp[ i ] + 1, dp[ i + 1 ] );
		if( reverse( i ) <= n ) dp[ reverse( i ) ] = min( dp[ reverse( i ) ], dp[ i ] + 1 );
	}
		
	fprintf( fout, "Case #%d: %d\n", ++global, dp[ n ] );
}
		


int main( void ) {
	int t;
	fscanf( fin, "%d", &t );
	while( t-- ) {
		load( );
		solve( );
	}
    return 0;
}
