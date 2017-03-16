#include <iostream>
#include <string>
#include <assert.h>

// Premature optimization is the root of all evil

using namespace std;

int solveacase() {
	int N;
	cin >> N;

	if (N == 0) { return -1; }

	bool digits[10];
	int now = 0;
	for ( int i = 0; i < 10; ++i ) { digits[i] = false; }

	int count = 0;
	int numseen = 0;

	while ( numseen < 10 ) {
		count++;
		now += N;
		int T = now;
		while ( T > 0 ) {
			if ( !digits[T%10] ) { ++numseen; }
			digits[T%10] = true;
			T /= 10;
		}
	}

	return now;
}

int main ( int, char** ) {

	int T;
	cin >> T;

	for ( int i = 1; i <= T; ++i ) {
		int r = solveacase();

		cout << "Case #" << i << ": ";
		if ( r == -1 ) { cout << "INSOMNIA"; }
		else { cout << r; }
		cout << endl;
	}


	return 0;
}
