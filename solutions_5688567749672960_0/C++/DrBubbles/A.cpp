#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

// Premature optimization is the root of all evil

using namespace std;

unsigned long long flip( unsigned long long N ) {
	int M = 0;
	while ( N > 0 ) {
		M *= 10;
		M += N % 10;
		N /= 10;
	}
	return M;
}

unsigned long long cost( unsigned long long N ) {
	unsigned long long t = 0;

	if ( N < 21 ) { return N; }

	if ( (N % 10) == 0 ) {
		N --;
		t ++;
	}

	int d = 1;
	int b = 0;
	int M = N;
	while ( M > 0 ) {
		d *= 10;
		M /= 10;
		++b;
	}
	d /= 10;

	// cost to get 1000 is cost to get 999 + 1.
	t += cost ( d - 1 ) + 1;


	int halften = 10;
	for ( int i = 1; i < b/2; ++i ) {
		halften *= 10;
	}

	if ( (b % 2) == 1 ) { halften *= 10; }

	int m = flip( N / halften );
	int n = N % halften;

	t += n + m;

	if ( m == 1 ) { t--; }









	return t;
}

unsigned long long solveacase() {

	unsigned long long N;
	cin >> N;

	return cost(N);

}

int main ( int, char** ) {

	int T;
	cin >> T;

	assert( flip(12345) == 54321 );

	for ( int i = 1; i <= T; ++i ) {
		cout << "Case #" << i << ": ";
		cout << solveacase() << endl;
	}


	return 0;
}
