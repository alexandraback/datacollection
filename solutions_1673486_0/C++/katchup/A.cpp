/*
	GOOGLE CODE JAM
	Contestant 			: Alex "katchup" AUVOLAT
	Contest reference	: Code Jam 2012 round 1A
	Problem				: A. Password problem
*/



#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void one_case() {
	int A, B;
	cin >> A;
	cin >> B;
	vector<float> P(A, 0);
	for (int i = 0; i < A; i++) {
		cin >> P[i];
	}

	// solve problem

	float expected;

	// first strategy : press enter immediately
	// we know A != B, A < B, so the first try can't have been right.
	expected = 1 + B + 1;		// enter, retype, enter

	// second strategy : keep typing (same as next, typing no backspaces)
	// third strategy : press backspace a number of times
	for (int bs = 0; bs <= A; bs++) {
		float prob_good = 1;
		for (int i = 0; i < A - bs; i++) {
			prob_good *= P[i];
		}
		float prob_bad = 1 - prob_good;
		int types = bs + (B - A + bs) + 1;

		float expect_this = prob_good * types + prob_bad * (types + B + 1);
		if (expect_this <= expected) expected = expect_this;
	}
	printf("%f", expected);
}

int main(int argc, char *argv[]) {

	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		cout << "Case #" << (i+1) << ": ";
		one_case();
		cout << endl;
	}

	return 0;
}

