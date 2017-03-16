#include <iostream>
#include <string>
#include <assert.h>

// Premature optimization is the root of all evil

using namespace std;

int solveacase() {
	int D;
	cin >> D;

	int cakes[1001];
	int MAX_CAKES = 0;
	for ( int i = 0; i < 1001; ++i ) {
		cakes[i] = 0;
	}

	for ( int i = 0; i < D; ++i ) {
		int c;
		cin >> c;
		cakes[c]++;

		if ( c > MAX_CAKES ) MAX_CAKES = c;
	}

	// Let's be really stupid and brute force about this.
	// Of course, the most efficient thing to do is to pick
	// some target size and cut every pile until its made of
	// pieces at most that size.
	int best = MAX_CAKES;
	for ( int TARGET = MAX_CAKES - 1; TARGET > 1; --TARGET ) {
		int cost = TARGET;
		for ( int i = MAX_CAKES; i > TARGET; --i ) {
			// It takes (i-1)/TARGET cuts to divide a stack
			// into stacks of size at most TARGET.
			int stack_cost = (i - 1) / TARGET;
			cost += stack_cost * cakes[i];

			if ( cost > best ) break;
		}

		if ( cost < best ) best = cost;
	}

	return best;
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
