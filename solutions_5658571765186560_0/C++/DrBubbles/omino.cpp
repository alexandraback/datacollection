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

	if ( X == 4 ) {
		// L and T can fill a 3x4 block.
		// As can L and Z. 
		if ( (R == 2) || (C == 2) ) return false;
		return true;
	}

	if ( X == 5 || X == 6 ) {
		// TODO
		return false;
	}

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
