#include <iostream>
#include <string>
#include <assert.h>

// Premature optimization is the root of all evil

using namespace std;

bool solveacase() {
	int X, R, C;
	cin >> X >> R >> C;

	// With X >= 7, there is an X-omino which encapsulates a single square.
	if ( X >= 7 ) return false;

	// If the space isn't divisible by the number squares per X-omino,
	// it can't be done.
	if ( ((R * C) % X) != 0 ) return false;

	// This is the only obstruction in the small case.
	if ( X <= 2 ) return true;

	if ( (R == 1) || (C == 1) ) { return false; }

	if ( X == 3 ) return true;

	// With X > 4, we have an L that won't fit in 2 columns.
	// With X = 4, S gives us problems as everything which may
	// go above it preserves the relative parity of the two columns.
	if ( (R <= 2) || (C <= 2) ) return false;
	if ( X == 4 ) {
		// L and T can fill a 3x4 block.
		// As can L and Z. 
		return true;
	}

	if ( X == 5 ) {
		// We need either 4x5 or 10x3 to accomodate a W.
		// We have both R and C at least 3, and one is divisible
		// by 5. Thus the only way we can fail to have both 4x5
		// and 10x3 is if one is 3 and the other is 5.
		if ( R * C == 15 ) return false;
		return true;
	}

	if ( X == 6 ) {
		// Each dimension must be at least 4, or else the Y causes
		// grief. Once this is satisfied, there is a 4x6 sublock for
		// sure (since one side is divisible by 3 and at least 4, hence
		// at least 6, while the other side is at least 4). Anything fits
		// there and then there is enough freedom provided by the rest to
		// tile either with 1x6 blocks or 2x3 blocks.
		if ( R < 4 || C < 4 ) return false;
		return true;
	}

	return false;
}

int main ( int, char** ) {

	int T;
	cin >> T;

	for ( int i = 1; i <= T; ++i ) {
		cerr << i << endl;
		bool r = solveacase();

		cout << "Case #" << i << ": " << (r?"GABRIEL":"RICHARD") << endl;
	}


	return 0;
}
