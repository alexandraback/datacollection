//============================================================================
// Name        : google_b.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int score1[11];
int score2[11];
int nGooglers, surprising, standard;
int passes;

void genScore() {
	for (int i = 1; i < 11; i++) {
		score1[i] = max(i * 3 - 2, 1);
		score2[i] = max(i * 3 - 4, 1);
	}
}

int main() {
	genScore();
	int cases;
	cin >> cases;

	for (int cnt = 1; cnt <= cases; cnt++) {
		cin >> nGooglers >> surprising >> standard;
		passes = 0;

		while (nGooglers--) {
			int n;
			cin >> n;

			if (n >= score1[standard])
				passes++;
			else if (n >= score2[standard]) {
				if (surprising) {
					surprising--;
					passes++;
				}
			}
		}

		cout << "Case #" << cnt << ": " << passes << endl;
	}

	return 0;
}
