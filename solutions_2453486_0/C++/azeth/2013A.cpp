// 2013A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>

using namespace std;

char test(char board[4][4]);
char check(char line[4]);

int _tmain(int argc, _TCHAR* argv[])
{
	ios_base::sync_with_stdio(false);

	ifstream in("A.in");
	ofstream out("A.out");

	int t;
	in >> t;

	for (int c = 1; c <= t; c++) {
		char board[4][4];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				in >> board[i][j];
			}
		}

		char res = test(board);
		out << "Case #" << c << ": ";
		if (res == 'X' || res == 'O') {
			out << res << " won";
		} else if (res == 'D') {
			out << "Draw";
		} else {
			out << "Game has not completed";
		}

		out << endl;
	}

	return 0;
}

char test(char board[4][4])
{
	// rows
	for (int i = 0; i < 4; i++) {
		char row[4];
		for (int j = 0; j < 4; j++) {
			row[j] = board[i][j];
		}

		char res = check(row);
		if (res == 'X') {
			return 'X';
		} else if (res == 'O') {
			return 'O';
		} else {
			continue;
		}
	}

	// cols
	for (int i = 0; i < 4; i++) {
		char col[4];
		for (int j = 0; j < 4; j++) {
			col[j] = board[j][i];
		}

		char res = check(col);
		if (res == 'X') {
			return 'X';
		} else if (res == 'O') {
			return 'O';
		} else {
			continue;
		}
	}

	// diags
	char diag[4];
	for (int i = 0; i < 4; i++) {
		diag[i] = board[i][i];
	}

	char res = check(diag);
	if (res == 'X') {
		return 'X';
	} else if (res == 'O') {
		return 'O';
	}

	for (int i = 0; i < 4; i++) {
		diag[i] = board[i][3-i];
	}

	res = check(diag);
	if (res == 'X') {
		return 'X';
	} else if (res == 'O') {
		return 'O';
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == '.') {
				return 'N';
			}
		}
	}

	return 'D';
}

char check(char line[4])
{
	int t = 0;
	int x = 0;
	int o = 0;

	for (int i = 0; i < 4; i++) {
		switch (line[i]) {
			case 'X':
				x++;
				break;
			case 'O':
				o++;
				break;
			case 'T':
				t++;
				break;
		}
	}

	if (x == 4) {
		return 'X';
	} else if (o == 4) {
		return 'O';
	} else if (t == 1 && x == 3) {
		return 'X';
	} else if (t == 1 && o == 3) {
		return 'O';
	} else {
		return 0;
	}
}