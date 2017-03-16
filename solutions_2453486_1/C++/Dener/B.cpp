#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

string p[4];

void solve() {
	for (int i = 0; i < 4; i++)
		cin >> p[i];

	bool havepoint = false;
	for (int i = 0; i < 4; i++) {
		int xkol = 0, okol = 0, tkol = 0;
		for (int j = 0; j < 4; j++)
			if (p[i][j] == 'X')
				xkol++;
			else if (p[i][j] == 'O')
				okol++;
			else if (p[i][j] == 'T')
				tkol++;
			else if (p[i][j] == '.')
				havepoint = true;

		if (xkol == 4) {
			printf("X won\n");
			return;
		}
		if (okol == 4) {
			printf("O won\n");
			return;
		}
		if (xkol == 3 && tkol == 1) {
			printf("X won\n");
			return;
		}
		if (okol == 3 && tkol == 1) {
			printf("O won\n");
			return;
		}
	}

	for (int j = 0; j < 4; j++) {
		int xkol = 0, okol = 0, tkol = 0;
		for (int i = 0; i < 4; i++)
			if (p[i][j] == 'X')
				xkol++;
			else if (p[i][j] == 'O')
				okol++;
			else if (p[i][j] == 'T')
				tkol++;
			else if (p[i][j] == '.')
				havepoint = true;

		if (xkol == 4) {
			printf("X won\n");
			return;
		}
		if (okol == 4) {
			printf("O won\n");
			return;
		}
		if (xkol == 3 && tkol == 1) {
			printf("X won\n");
			return;
		}
		if (okol == 3 && tkol == 1) {
			printf("O won\n");
			return;
		}
	}

	for (int i = 0; i < 1; i++) {
		int xkol = 0, okol = 0, tkol = 0;
		for (int j = 0; j < 4; j++)
			if (p[j][j] == 'X')
				xkol++;
			else if (p[j][j] == 'O')
				okol++;
			else if (p[j][j] == 'T')
				tkol++;
			else if (p[j][j] == '.')
				havepoint = true;

		if (xkol == 4) {
			printf("X won\n");
			return;
		}
		if (okol == 4) {
			printf("O won\n");
			return;
		}
		if (xkol == 3 && tkol == 1) {
			printf("X won\n");
			return;
		}
		if (okol == 3 && tkol == 1) {
			printf("O won\n");
			return;
		}
	}

	for (int i = 0; i < 1; i++) {
		int xkol = 0, okol = 0, tkol = 0;
		for (int j = 0; j < 4; j++)
			if (p[j][3-j] == 'X')
				xkol++;
			else if (p[j][3-j] == 'O')
				okol++;
			else if (p[j][3-j] == 'T')
				tkol++;
			else if (p[j][3-j] == '.')
				havepoint = true;

		if (xkol == 4) {
			printf("X won\n");
			return;
		}
		if (okol == 4) {
			printf("O won\n");
			return;
		}
		if (xkol == 3 && tkol == 1) {
			printf("X won\n");
			return;
		}
		if (okol == 3 && tkol == 1) {
			printf("O won\n");
			return;
		}
	}

	if (havepoint)
		printf("Game has not completed\n");
	else
		printf("Draw\n");
	return;
}

int main() {
	freopen("A-large.in","r", stdin);
	freopen("B_output.txt","w", stdout);
	int T;
	scanf("%d\n", &T);
	for (int i = 0; i < T; i++) {
		printf("Case #%d: ", i + 1);
		solve();
	}
}
