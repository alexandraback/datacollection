//============================================================================
// Name        : cj1.cpp
// Author      : Carlos Ocampo
// Version     :
// Copyright   : All rights reserved
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

void discard(int n) {
	char a[5];
	for (int i = 0; i < n; i++) {
		cin >> a;
	}
}

int main() {
	char a[5];
	int n, i;

	cin >> n;
	for (int j = 0; j < n; j++) {
		int cX[4] = { 0, 0, 0, 0 };
		int cO[4] = { 0, 0, 0, 0 };
		int rX = 0;
		int rO = 0;
		int dX = 0;
		int dO = 0;
		int bX = 0;
		int bO = 0;
		int total = 16;

		cout << "Case #" << j + 1 << ": ";
		for (i = 0; i < 4; i++) {
			rX = 0;
			rO = 0;
			cin >> a;

			for (int t = 0; t < 4; t++) {
				if (a[t] != '.') {
					total--;

					if (a[t] == 'T') {
						cX[t]++;
						cO[t]++;
						rX++;
						rO++;
					} else if (a[t] == 'X') {
						cX[t]++;
						rX++;
					} else if (a[t] == 'O') {
						cO[t]++;
						rO++;
					}

					if (i == t) {
						if (a[t] == 'T') {
							dX++;
							dO++;
						} else if (a[t] == 'X') {
							dX++;
						} else if (a[t] == 'O') {
							dO++;
						}
					}

					if (i == 4 - t - 1) {
						if (a[t] == 'T') {
							bX++;
							bO++;
						} else if (a[t] == 'X') {
							bX++;
						} else if (a[t] == 'O') {
							bO++;
						}
					}
				}
			}

			if (rX == 4 || cX[0] == 4 || cX[1] == 4 || cX[2] == 4
					|| cX[3] == 4 || dX == 4 || bX == 4) {
				discard(4 - i - 1);

				cout << "X won\n";
				break;
			}

			if (rO == 4 || cO[0] == 4 || cO[1] == 4 || cO[2] == 4
					|| cO[3] == 4 || dO == 4 || bO == 4) {
				discard(4 - i - 1);

				cout << "O won\n";
				break;
			}
		}

		if (i == 4) {
			if (total == 0)
				cout << "Draw\n";
			else
				cout << "Game has not completed\n";
		}
	}

	return 0;
}
