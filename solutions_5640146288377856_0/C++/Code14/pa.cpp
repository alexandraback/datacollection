/**
 * Tittle:	2015 Google Code Jam Round1C - PA
 * Author:	Cheng-Shih, Wong
 * Date:	2015/05/10
 */

// include files
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

// definitions
#define FOR(i,a,b) for( int i=(a),_n=(b); i<=_n; ++i )
#define clr(x,v) memset( x, v, sizeof(x) )

// declarations
int t;
int r, c, w;
int ans;

// functions

// main function
int main( void )
{

	// input
	scanf( "%d", &t );

	FOR( ti, 1, t ) {
		scanf( "%d%d%d", &r, &c, &w );
		ans = 0;

		// solve
		if( r > 1 ) ans += (r-1)*(c/w);
		
		ans += (c/w-1);

		if( c-w*(c/w-1) > w ) ans += w+1;
		else ans += w;

		printf( "Case #%d: %d\n", ti, ans );
	}
	
	return 0;
}
