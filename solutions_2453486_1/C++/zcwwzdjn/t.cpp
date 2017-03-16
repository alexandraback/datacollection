#include <cstdio>

char mat[4][5];

void Check() {
	bool wonX = false, wonO = false;
	int emp = 0;
	for (int i = 0; i < 4; ++ i)
		for (int j = 0; j < 4; ++ j) emp += mat[i][j] == '.';
	for (int i = 0; i < 4; ++ i) {
		int cntX = 0, cntO = 0, cntT = 0;
		for (int j = 0; j < 4; ++ j) {
			cntX += mat[i][j] == 'X';
			cntO += mat[i][j] == 'O';
			cntT += mat[i][j] == 'T';
		}
		if (cntX + cntT == 4) wonX = true;
		if (cntO + cntT == 4) wonO = true;
	}
	for (int i = 0; i < 4; ++ i) {
		int cntX = 0, cntO = 0, cntT = 0;
		for (int j = 0; j < 4; ++ j) {
			cntX += mat[j][i] == 'X';
			cntO += mat[j][i] == 'O';
			cntT += mat[j][i] == 'T';
		}
		if (cntX + cntT == 4) wonX = true;
		if (cntO + cntT == 4) wonO = true;
	}
	int cntX = 0, cntO = 0, cntT = 0;
	for (int i = 0; i < 4; ++ i) {
		cntX += mat[i][i] == 'X';
		cntO += mat[i][i] == 'O';
		cntT += mat[i][i] == 'T';
	}
	if (cntX + cntT == 4) wonX = true;
	if (cntO + cntT == 4) wonO = true;
	cntX = 0, cntO = 0, cntT = 0;
	for (int i = 0; i < 4; ++ i) {
		cntX += mat[i][3 - i] == 'X';
		cntO += mat[i][3 - i] == 'O';
		cntT += mat[i][3 - i] == 'T';
	}
	if (cntX + cntT == 4) wonX = true;
	if (cntO + cntT == 4) wonO = true;
	if (wonX) puts("X won");
	else if (wonO) puts("O won");
	else if (emp) puts("Game has not completed");
	else puts("Draw");
}

int main() {
	freopen("t.in", "r", stdin);
	freopen("t.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++ t) {
		for (int i = 0; i < 4; ++ i) scanf("%s", mat[i]);
		printf("Case #%d: ", t + 1);
		Check();
	}
	return 0;
}
