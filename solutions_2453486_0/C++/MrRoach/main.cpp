#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

char m[4][4];
int t;

int main() {
	cin >> t;
	for (int caseNum = 0; caseNum < t; ++caseNum) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				cin >> m[i][j];
			}
		}
		//1->X 2->O
		unsigned int win = 0;
		int numD = 0;
		for (int i = 0; i < 4; ++i) {
			int numX = 0, numO = 0, numT = 0;
			for (int j = 0; j < 4; ++j) {
				if (m[i][j] == 'X') ++ numX;
				else if (m[i][j] == 'O') ++ numO;
				else if (m[i][j] == 'T') ++ numT;
				else if (m[i][j] == '.') ++ numD;
			}
			if (numX == 4 || (numX == 3 && numT == 1)) {
				win |= 1;
			} else if (numO == 4 || (numO == 3 && numT == 1)) {
				win |= 2;
			}
		}
		for (int i = 0; i < 4; ++i) {
			int numX = 0, numO = 0, numT = 0;
			for (int j = 0; j < 4; ++j) {
				if (m[j][i] == 'X') ++ numX;
				else if (m[j][i] == 'O') ++ numO;
				else if (m[j][i] == 'T') ++ numT;
			}
			if (numX == 4 || (numX == 3 && numT == 1)) {
				win |= 1;
			} else if (numO == 4 || (numO == 3 && numT == 1)) {
				win |= 2;
			}
		}
		int numX = 0, numO = 0, numT = 0;
		for (int i = 0; i < 4; ++i) {
			if (m[i][i] == 'X') ++ numX;
			else if (m[i][i] == 'O') ++ numO;
			else if (m[i][i] == 'T') ++ numT;
		}
		if (numX == 4 || (numX == 3 && numT == 1)) {
			win |= 1;
		} else if (numO == 4 || (numO == 3 && numT == 1)) {
			win |= 2;
		}
		numX = 0;
		numO = 0;
		numT = 0;
		for (int i = 0; i < 4; ++i) {
			if (m[i][3 - i] == 'X') ++ numX;
			else if (m[i][3 - i] == 'O') ++ numO;
			else if (m[i][3 - i] == 'T') ++ numT;
		}
		if (numX == 4 || (numX == 3 && numT == 1)) {
			win |= 1;
		} else if (numO == 4 || (numO == 3 && numT == 1)) {
			win |= 2;
		}

		cout << "Case #" << caseNum + 1 << ": ";
		if (win == 1) {
			cout << "X won";
		} else if (win == 2) {
			cout << "O won";
		} else if (win == 0) {
			if (numD == 0) {
				cout << "Draw";
			} else {
				cout << "Game has not completed";
			}
		}
		cout << endl;
	}
	return 0;
}