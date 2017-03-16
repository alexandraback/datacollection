#include <iostream>
#include <string>
#include <assert.h>

// Premature optimization is the root of all evil

using namespace std;

void solveacase() {
	int K;
	int C;
	int S;
	cin >> K >> C >> S;

	if ( K > C * S ) { cout << "IMPOSSIBLE\n"; return; }

	long long test = 0;
	int gen = 0;
	for ( int i = 0; i < K; ++i ) {
		test *= K;
		test += i;
		gen++;

		if ( gen == C ) {
			cout << test + 1 << " ";
			gen = 0;
			test = 0;
		}
	}
	if ( gen > 0 ) {
		cout << test + 1;
	}

	cout << endl;

	return;
}

int main ( int, char** ) {

	int T;
	cin >> T;

	for ( int i = 1; i <= T; ++i ) {
		cout << "Case #" << i << ": ";

		solveacase();
	}


	return 0;
}
