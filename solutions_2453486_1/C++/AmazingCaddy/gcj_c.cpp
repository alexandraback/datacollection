#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

char g[10][10];

int _solve (char ch) {
	int flag = 0;
	for (int i = 0; i < 4; i ++) {
		flag = 0;
		for (int j = 0; j < 4; j ++) {
			if (g[i][j] != ch && g[i][j] != 'T') {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			return ch == 'X' ? 1 : 2;
		}
	}
	for (int i = 0; i < 4; i ++) {
		flag = 0;
		for (int j = 0; j < 4; j ++) {
			if (g[j][i] != ch && g[j][i] != 'T') {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			return ch == 'X' ? 1 : 2;
		}
	}
	flag = 0;
	for (int i = 0; i < 4; i ++) {
		if (g[i][i] != ch && g[i][i] != 'T') {
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		return ch == 'X' ? 1 : 2;
	}
	flag = 0;
	for (int i = 0; i < 4; i ++) {
		if (g[i][3 - i] != ch && g[i][3 - i] != 'T') {
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		return ch == 'X' ? 1 : 2;
	}
	return 0;
}

void solve (int t, int cnt) {
	printf ("Case #%d: ", t);
	if (_solve ('X') == 1) {
		printf ("X won\n");
	} else if (_solve ('O') == 2) {
		printf ("O won\n");
	} else if (cnt > 0) {
		printf ("Game has not completed\n");
	} else {
		printf ("Draw\n");
	}
}

int main(int argc, char *argv[]) {
	freopen ("A-large.in", "r", stdin);
	freopen ("out.txt", "w", stdout);
	int cas;
	scanf ("%d", &cas);
	for (int t = 1; t <= cas; t ++) {
		int cnt = 0;
		for (int i = 0; i < 4; i ++) {
			scanf ("%s", g[i]);
			for (int j = 0; j < 4; j ++) {
				if (g[i][j] == '.') {
					cnt ++;
				}
			}
		}
		solve (t, cnt);
	}
	return 0;
}
