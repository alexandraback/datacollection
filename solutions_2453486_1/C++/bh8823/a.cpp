#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define MAXL 4
using namespace std;
const int INF = 987654321;
const int MOD = 1000000007;

char board[4][5];

bool checkrow(char c) {
	for (int i = 0; i < 4; i++) {
		bool success = true;
		for (int j = 0; j < 4; j++) {
			if (board[i][j] != c && board[i][j] != 'T') {
				success = false;
							//	printf("%d %d %c\n", i, j , board[j][i]);
				break;
			}
		}
		if (success) return true;
	}
	return false;
}

bool checkcol( char c){
	for (int i = 0; i < 4; i++) {
		bool success = true;
		for (int j = 0; j < 4; j++) {
			if (board[j][i] != c && board[j][i] != 'T') {
				success = false;
				break;

			}
		}
		if (success) return true;
	}
	return false;
}
bool checkdiag(char c) {
	bool success = true;
	for (int j = 0; j < 4; j++) {
		if (board[j][j] != c && board[j][j] != 'T') {
			success = false;
			break;
		}
	}
	if (success) return true;
	success = true;
	for (int j = 0; j < 4; j++) {
		if (board[3 - j][j] != c && board[3 - j][j] != 'T'){
			success = false;
			break;
		}
	}
	if (success) return true;
	return false;
}
bool checkfull() {
	for (int i = 0; i < 4; i++) 
		for (int j = 0; j < 4; j++) if (board[i][j] == '.') return false;
	return true;
}

int check(){
	bool xwon = false;
	bool owon = false;
	bool draw = false;
	bool notcomp = false;
	
	xwon = (checkrow('X') || checkcol('X') || checkdiag('X'));
	if (xwon) return 1;
	owon = (checkrow('O') || checkcol('O') || checkdiag('O'));
	if (owon) return 2;
	if (checkfull()) return 3;
	return 4;
}

int main() {
	int T;
	scanf("%d", &T);
	string s;
	getline(cin, s);
	int loop = 1;
	while (loop <= T) {
		for (int i = 0; i < 4; i++)
			scanf("%s",board[i]);
		int ret = check();
		printf("Case #%d: ", loop);
		switch (ret) {
			case 1:
				puts("X won");
				break;
			case 2:
				puts("O won");
				break;
			case 3:
				puts("Draw");
				break;
			case 4:
				puts("Game has not completed");
				break;
		}
		loop++;
	}

	return 0;
}