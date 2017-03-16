#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

char BOARD[4][4];
bool complete = true;
void input()
{
	complete = true;
	for (int i = 0 ; i < 4 ; i++) {
		for (int j = 0 ; j < 4 ; j++) {
			scanf("%c\n", &BOARD[i][j]);
			if (BOARD[i][j] == '.') {
				complete = false;
			}
		}
	}
}

char solve()
{
	// check row
	for (int i = 0 ; i < 4 ; i++) {
		char color = 'N';
		bool result = true;
		for (int j = 0 ; j < 4 ; j++) {
			if (BOARD[i][j] == 'T') {
				continue;
			} else if (BOARD[i][j] == '.') {
				result = false;
				break;
			} else if (color == 'N') {
				color = BOARD[i][j];
			} else if (BOARD[i][j] == color) {
				continue;
			} else {
				result = false;
				break;
			}
		}

		if (result) {
			return color;
		}
	}

	// check column
	for (int i = 0 ; i < 4 ; i++) {
		char color = 'N';
		bool result = true;
		for (int j = 0 ; j < 4 ; j++) {
			if (BOARD[j][i] == 'T') {
				continue;
			} else if (BOARD[j][i] == '.') {
				result = false;
				break;
			} else if (color == 'N') {
				color = BOARD[j][i];
			} else if (BOARD[j][i] == color) {
				continue;
			} else {
				result = false;
				break;
			}
		}

		if (result) {
			return color;
		}
	}

	//  check diagonal
	// check column

	char color = 'N';
	bool result = true;
	for (int j = 0 ; j < 4 ; j++) {
		if (BOARD[j][j] == 'T') {
			continue;
		} else if (BOARD[j][j]  == '.') {
			result = false;
			break;
		} else if (color == 'N') {
			color = BOARD[j][j] ;
		} else if (BOARD[j][j]  == color) {
			continue;
		} else {
			result = false;
			break;
		}
	}

	if (result) {
		return color;
	}

	color = 'N';
	result = true;
	for (int j = 3 ; j >= 0 ; j--) {
		if (BOARD[j][3 - j] == 'T') {
			continue;
		} else if (BOARD[j][3 - j]  == '.') {
			result = false;
			break;
		} else if (color == 'N') {
			color = BOARD[j][3 - j] ;
		} else if (BOARD[j][3 - j]  == color) {
			continue;
		} else {
			result = false;
			break;
		}
	}

	if (result) {
		return color;
	}

	return 'N';
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d\n", &n);
	for (int i = 0 ; i < n ; i++) {
		input();
		char result = solve();
		if (result == 'O') {
			printf("Case #%d: O won\n", i + 1);
		} else if (result == 'X') {
			printf("Case #%d: X won\n", i + 1);
		} else {
			printf("Case #%d: %s\n", i + 1, complete ? "Draw" : "Game has not completed");
		}
	}

	return 0 ;
}