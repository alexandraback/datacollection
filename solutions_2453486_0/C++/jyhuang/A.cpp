#include <iostream>

using namespace std;

bool check(char a[][8], char p)
{
	for (int i = 0; i < 4; i++) {
		bool won = true;
		for (int j = 0; j < 4; j++)
			won = won && (a[i][j] == p || a[i][j] == 'T');
		if (won) return true;
		won = true;
		for (int j = 0; j < 4; j++)
			won = won && (a[j][i] == p || a[j][i] == 'T');
		if (won) return true;
	}

	bool won = true;
	for (int i = 0, j = 0; i < 4; i++, j++)
		won = won && (a[i][j] == p || a[i][j] == 'T');
	if (won) return true;

	won = true;
	for (int i = 0, j = 3; i < 4; i++, j--)
		won = won && (a[i][j] == p || a[i][j] == 'T');
	if (won) return true;

	return false;
}

bool gameover(char a[][8])
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) if (a[i][j] == '.') return false;
	return true;
}

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	char a[8][8];
	for (int ti = 0; ti < T; ti++) {
		for (int i = 0; i < 4; i++) cin >> a[i];
		cout << "Case #" << (ti + 1) << ": ";
		if (check(a, 'X'))
			cout << "X won" << endl;
		else if (check(a, 'O'))
			cout << "O won" << endl;
		else if (gameover(a))
			cout << "Draw" << endl;
		else
			cout << "Game has not completed" << endl;
	}

	return 0;
}
