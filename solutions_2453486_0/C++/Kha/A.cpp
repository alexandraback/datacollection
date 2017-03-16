#include <iostream>

using namespace std;

char map[4][4];

bool streak(char p, int x, int y, int dx, int dy) {
	for (int i = 0; i < 4; i++) {
		char c = map[x + i*dx][y + i*dy];
		if (c != p && c != 'T')
			return false;
	}
	return true;
}

bool won(char p) {
	for (int i = 0; i < 4; i++)
		if (streak(p, 0, i, 1, 0) || streak(p, i, 0, 0, 1))
			return true;
	return streak(p, 0, 0, 1, 1) || streak(p, 0, 3, 1, -1);
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		bool empty = false;
		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 4; x++) {
				cin >> map[x][y];
				if (map[x][y] == '.')
					empty = true;
			}

		cout << "Case #" << (i+1) << ": ";
		if (won('X'))
			cout << "X won\n";
		else if (won('O'))
			cout << "O won\n";
		else if (empty)
			cout << "Game has not completed\n";
		else
			cout << "Draw\n";
	}
	return 0;
}
