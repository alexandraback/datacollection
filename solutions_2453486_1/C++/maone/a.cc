// Tic-Tac-Toe-Tomek

#include <iostream>
#include <vector>
using namespace std;

char bd[10][10];

int run() {
	int empty = 0;
	for (int i = 0; i < 4; ++i) {
		int x = 0, o = 0, t = 0;
		for (int j = 0; j < 4; ++j) {
			if (bd[i][j] == 'X') ++x;
			else if (bd[i][j] == 'O') ++o;
			else if (bd[i][j] == 'T') ++t;
			else ++empty;
		}
		if (x + t == 4) return 0;
		if (o + t == 4) return 1;
	}


	for (int i = 0; i < 4; ++i) {
		int x = 0, o = 0, t = 0;
		for (int j = 0; j < 4; ++j) {
			if (bd[j][i] == 'X') ++x;
			else if (bd[j][i] == 'O') ++o;
			else if (bd[j][i] == 'T') ++t;
			else ++empty;
		}
		if (x + t == 4) return 0;
		if (o + t == 4) return 1;
	}



	{
		int x = 0, o = 0, t = 0;
		for (int j = 0; j < 4; ++j) {
			if (bd[j][j] == 'X') ++x;
			else if (bd[j][j] == 'O') ++o;
			else if (bd[j][j] == 'T') ++t;
			else ++empty;
		}
		if (x + t == 4) return 0;
		if (o + t == 4) return 1;
	}



	{
		int x = 0, o = 0, t = 0;
		for (int j = 0; j < 4; ++j) {
			if (bd[j][3 - j] == 'X') ++x;
			else if (bd[j][3 - j] == 'O') ++o;
			else if (bd[j][3 - j] == 'T') ++t;
			else ++empty;
		}
		if (x + t == 4) return 0;
		if (o + t == 4) return 1;
	}


	return empty > 0 ? 3 : 2;
}

int main(int argc, const char* argv[]) {
	char results[4][64] = {"X won", "O won", "Draw", "Game has not completed"};
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		for (int i = 0; i < 4; ++i) {
			cin >> bd[i];
		}
		cout << "Case #" << t << ": " << results[run()] << endl;
	}

	return 0;
}
