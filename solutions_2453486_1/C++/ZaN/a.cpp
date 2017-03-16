#include <iostream>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		char b[4][4];
		bool has_empty = false;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				cin >> b[i][j];
				if (b[i][j] == '.') {
					has_empty = true;
				}
			}
		}

		bool xwon = false, owon = false;
		for (int i = 0; i < 4; ++i) {
			char c = b[i][0];
			if (c == 'T') {
				c = b[i][1];
			}
			if (c == '.') {
				continue;
			}
			if ((b[i][0] == c || b[i][0] == 'T') &&
				(b[i][1] == c || b[i][1] == 'T') &&
				(b[i][2] == c || b[i][2] == 'T') &&
				(b[i][3] == c || b[i][3] == 'T'))
			{
				(c == 'X' ? xwon : owon) = true;
			}
		}

		for (int j = 0; j < 4; ++j) {
			char c = b[0][j];
			if (c == 'T') {
				c = b[1][j];
			}
			if (c == '.') {
				continue;
			}
			if ((b[0][j] == c || b[0][j] == 'T') &&
				(b[1][j] == c || b[1][j] == 'T') &&
				(b[2][j] == c || b[2][j] == 'T') &&
				(b[3][j] == c || b[3][j] == 'T'))
			{
				(c == 'X' ? xwon : owon) = true;
			}
		}

		{
			char c = b[0][0];
			if (c == 'T') {
				c = b[1][1];
			}
			if (c != '.' &&
				(b[0][0] == c || b[0][0] == 'T') &&
				(b[1][1] == c || b[1][1] == 'T') &&
				(b[2][2] == c || b[2][2] == 'T') &&
				(b[3][3] == c || b[3][3] == 'T'))
			{
				(c == 'X' ? xwon : owon) = true;
			}
		}

		{
			char c = b[3][0];
			if (c == 'T') {
				c = b[2][1];
			}
			if (c != '.' &&
				(b[3][0] == c || b[3][0] == 'T') &&
				(b[2][1] == c || b[2][1] == 'T') &&
				(b[1][2] == c || b[1][2] == 'T') &&
				(b[0][3] == c || b[0][3] == 'T'))
			{
				(c == 'X' ? xwon : owon) = true;
			}
		}

		if (xwon && owon || (!xwon && !owon && !has_empty)) {
			cout << "Case #" << test << ": Draw" << endl;
		} else if (xwon) {
			cout << "Case #" << test << ": X won" << endl;
		} else if (owon) {
			cout << "Case #" << test << ": O won" << endl;
		} else {
			cout << "Case #" << test << ": Game has not completed" << endl;
		}
	}
}