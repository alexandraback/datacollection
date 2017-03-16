#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <hash_set>
#include <algorithm>
#include <vector>
#include <hash_map>
#include <map>
#include <memory>
#include <random>

using namespace std;

const char* inname = "Bs2.in";
const char* outname = "Bs.out";

long long Binomial( int Tot, int Sel )
{
	long long ret = 1;
	for( int i=0; i<Sel; i++ ) {
		ret *= Tot-i;
	}
	for( int i=0; i<Sel; i++ ) {
		ret /= i+1;
	}
	return ret;
}

int main( int argc, char** argv )
{
	int T;
	freopen( inname, "r", stdin );
	freopen( outname, "w", stdout );

	struct pt {
		int x; int y;
		pt( int _x, int _y )
		{ x = _x; y = _y;}
	};

	int N, X, Y;

	scanf( "%d", &T );
	for( int iT=1; iT<=T; iT++ ) {
		printf( "Case #%d: ", iT );
		scanf( "%d %d %d", &N, &X, &Y );

		int l=0, r=1000, mid;
		while( r-l > 1 ) {
			mid = (l+r)/2;
			if( mid*(2*mid-1) > N ) r = mid;
			else l = mid;
		}
		int nLeft = N - l*(2*l-1);
		if( X+Y > 2*l ) { printf( "0.0\n" ); continue; }
		if( X+Y < 2*l ) { printf( "1.0\n" ); continue; }
		if( X == 0 ) { printf( "0.0\n" ); continue; }
		if( nLeft < Y+1 ) {printf( "0.0\n" ); continue; }
		double p = 0.f;
		if( nLeft - 2*l+1 >= Y+1 ) { printf( "1.0\n" ); continue; }

		for( int i=nLeft; i>= Y+1; i-- ) {
			p += Binomial( nLeft, i );
		}
		p /= ( 1 << nLeft );
		printf( "%f\n", p );
		continue;
	}
	return 0;
}
