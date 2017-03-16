/*
	GOOGLE CODE JAM
	Contestant 			: Alex "katchup" AUVOLAT
	Contest reference	: Google Code Jam 2012 - Qualification Round
	Problem				: C. Recycled Numbers
*/



#include <iostream>
#include <set>

using namespace std;

#define lint long long int

void one_case() {
	lint A, B;
	cin >> A;
	cin >> B;
	
	lint count = 0;
	for (lint i = A; i < B; i++) {
		lint digits = 0;
		for (lint v = i; v > 0; v /= 10) digits++;
		lint pow = 1;
		for (lint k = 0; k < digits; k++) pow *= 10;

		lint j = i;
		lint aru[digits];
		for (lint k = 0; k < digits; k++) aru[k] = -1;

		for (lint k = 1; k < digits; k++) {
			j = (j + ((j % 10) * pow)) / 10;
			aru[k] = j;
			bool has = false;
			for (lint l = 1; l < k - 1; l++) {
				if (aru[l] == j) {
					has = true;
					break;
				}
			}
			if (!has) {
				if (j > i && j <= B) {
					count++;
				}
			}
		}
	}
	cout << count;
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

