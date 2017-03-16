#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool check(char a[16], int p, int d, char c, bool& draw) {
	int n = 0;
	for (int i = 0; i < 4; ++i, p += d) {
		if (a[p] == '.') draw = false;
		if (a[p] == 'T' || a[p] == c)
			++n;
	}

	return n == 4;
}

bool checkall(char a[16], char c, bool& draw) {
	draw = true;
	for (int i = 0; i < 4; ++i) {
		if (check(a, i * 4, 1, c, draw))
			return true;
	}

	for (int i = 0; i < 4; ++i) {
		if (check(a, i, 4, c, draw))
			return true;
	}

	return check(a, 0, 5, c, draw) || check(a, 3, 3, c, draw);
}

int main() {
	int T; cin >> T;

	for (int tc = 0; tc < T; ++tc) {
		char a[16];
		for (int r = 0; r < 4; ++r)
			for (int c = 0; c < 4; ++c)
				cin >> a[r * 4 + c];

		cout << "Case #"  << tc+1 << ": ";
		
		bool draw;
		if (checkall(a, 'X', draw))
			cout << "X won" << endl;
		else if (checkall(a, 'O', draw))
			cout << "O won" << endl;
		else if (draw)
			cout << "Draw" << endl;
		else
			cout << "Game has not completed" << endl;
	}
}