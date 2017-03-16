#include <iostream>
#include <string>
#include <assert.h>

// Premature optimization is the root of all evil

using namespace std;

void solveacasedumb() {
	int K;
	int C;
	int S;
	cin >> K >> C >> S;

	long long skip = 1;
	for ( int i = 1; i < C; ++i ) {
		skip *= K;
	}

	for ( int i = 0; i < S; ++i ) {
		cout << 1 + skip * i << " ";
	}
	cout << endl;

	return;
}

int main ( int, char** ) {

	int T;
	cin >> T;

	for ( int i = 1; i <= T; ++i ) {
		cout << "Case #" << i << ": ";

		solveacasedumb();
	}


	return 0;
}
