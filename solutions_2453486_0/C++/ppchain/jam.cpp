#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

char board[4][5];

bool check(char ch)
{
	//printf("ch = %c\n", ch);
	int cnt;
	for (int i = 0; i < 4; ++i) {
		cnt = 0;
		for (int j = 0; j < 4; ++j) {
			if (board[i][j] == ch) ++cnt;
			else if (board[i][j] == 'T') ++cnt;
		}
		if (cnt == 4) return true;
	}
	for (int j = 0; j < 4; ++j) {
		cnt = 0;
		for (int i = 0; i < 4; ++i) {
			if (board[i][j] == ch) ++cnt;
			else if (board[i][j] == 'T') ++cnt;
		}
		if (cnt == 4) return true;
	}
	cnt = 0;
	for (int i = 0; i < 4; ++i) {
		if (board[i][i] == ch) ++cnt;
		else if (board[i][i] == 'T') ++cnt;
	}
	if (cnt == 4) return true;
	cnt = 0;
	for (int i = 0; i < 4; ++i) {
		if (board[i][3 - i] == ch) ++cnt;
		else if (board[i][3 - i] == 'T') ++cnt;
	}
	if (cnt == 4) return true;
	else return false;
}

int main() 
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("jam.out", "w", stdout);
	int ncas;
	scanf("%d", &ncas);
	for (int cas = 1; cas <= ncas; ++cas) {
		int dot_cnt = 0;
		for (int i = 0; i < 4; ++i) {
			scanf("%s", board[i]);
			for (int j = 0; j < 4; ++j) {
				if (board[i][j] == '.') ++dot_cnt;
			}
		}
		//printf("input end.\n");
		printf("Case #%d: ", cas);
		if (check('X')) {
			puts("X won");
			continue;
		}
		if (check('O')) {
			puts("O won");
			continue;
		}
		if (dot_cnt) puts("Game has not completed");
		else puts("Draw");
	}
	//system("pause");
	return 0;
}
