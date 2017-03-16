#include <iostream>
using namespace std;

char field[4][4];

bool checkRow(int i, char& winner) {
	char p = field[i][0] == 'T' ? field[i][1] : field[i][0];
	if(p == '.') return false;
	for (int j = 0; j < 4; j++)
		if (field[i][j] != p && field[i][j] != 'T')
			return false;
	winner = p;
	return true;
}

bool checkColumn(int j, char& winner) {
	char p = field[0][j] == 'T' ? field[1][j] : field[0][j];
	if(p == '.') return false;
	for (int i = 0; i < 4; i++)
		if (field[i][j] != p && field[i][j] != 'T')
			return false;
	winner = p;
	return true;
}

bool checkMainDiagonal(char& winner) {
	char p = field[0][0] == 'T' ? field[1][1] : field[0][0];
	if(p == '.') return false;
	for (int i = 0; i < 4; i++)
		if (field[i][i] != p && field[i][i] != 'T')
			return false;
	winner = p;
	return true;
}

bool checkSideDiagonal(char& winner) {
	char p = field[0][3] == 'T' ? field[1][2] : field[0][3];
	if(p == '.') return false;
	for (int i = 0; i < 4; i++)
		if (field[i][3 - i] != p && field[i][3 - i] != 'T')
			return false;
	winner = p;
	return true;
}

void test(int i) {
	cout << "Case #" << i << ": ";
	bool dots = false;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			cin >> field[i][j];
			dots = dots || field[i][j] == '.';
		}
	char winner;
	for (int i = 0; i < 4; i++)
		if (checkRow(i, winner) || checkColumn(i, winner)) {
			cout << winner << " won\n";
			return;
		}
	if (checkSideDiagonal(winner) || checkMainDiagonal(winner)) {
		cout << winner << " won\n";
		return;
	}
	if (dots)
		cout << "Game has not completed\n";
	else
		cout << "Draw\n";
}

int main() {
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
		test(i);
	return 0;
}
