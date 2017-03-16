#include <iostream>
#include <string>
#include <assert.h>

// Premature optimization is the root of all evil

using namespace std;

int solveacase() {
	int N;
	cin >> N;
	string levels;
	cin >> levels;

	int people = 0;
	int invites = 0;

	for ( int i = 0; i <= N; ++i ) {
		if ( people < i ) {
			int diff = i - people;
			invites += diff;
			people += diff;
		}

		int clappers = (int)(levels[i] - '0');
		assert( 0 <= clappers && clappers < 10 );

		people += clappers;
	}

	return invites;
}

int main ( int, char** ) {

	int T;
	cin >> T;

	for ( int i = 1; i <= T; ++i ) {
		int r = solveacase();

		cout << "Case #" << i << ": " << r << endl;
	}


	return 0;
}
