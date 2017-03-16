/*
 * 2014-04-12  Token  <token@token-HP-ENVY-14-SPECTRE-Notebook-PC>

 * 
 */
#include <iostream>
#include <fstream>

using namespace std;

bool Able;
char Map[55][55];

void Solve(int R, int C, int B) {
	Able = 0;
	if (R == 2) {
		if (B == 2)
			return;
		if (B > 1 && B % 2 == 1)
			return;
	}
	if (R >= 3) {
		if (B == 2 || B == 3 || B == 5 || B == 7)
			return;
	}
	Able = 1;
	for (int i = 0; i < R; ++ i)
		for (int j = 0; j < C; ++ j)
			Map[i][j] = '*';
	if (R == 1) {
		for (int j = 0; j < B; ++ j)
			Map[0][j] = '.';
	}
	if (R == 2) {
		for (int i = 0; i < R; ++ i)
			for (int j = 0; j < B / R; ++ j)
				Map[i][j] = '.';
	}
	if (R >= 3) {
		if (B >= 4) {
			for (int i = 0; i < 2; ++ i)
				for (int j = 0; j < 2; ++ j)
					Map[i][j] = '.';
		}
		if (B >= 6) {
			Map[2][0] = Map[2][1] = '.';
		}
		if (B >= 8) {
			Map[0][2] = Map[1][2] = '.';
		}
		if (B > 8) {
			int Rest = B - 8;
			for (int k = 3; k < R; ++ k)
				if (Rest >= 2) {
					Rest -= 2;
					Map[k][0] = Map[k][1] = '.';
				}
			for (int k = 3; k < C; ++ k)
				if (Rest >= 2) {
					Rest -= 2;
					Map[0][k] = Map[1][k] = '.';
				}
			//~ if (Rest == 1) {
				//~ -- Rest;
				//~ Map[2][2] = '.';
			//~ }
			for (int i = 2; i < R; ++ i)
				for (int j = 2; j < C; ++ j)
					if (Rest > 0 && Map[i][j] == '*') {
						-- Rest;
						Map[i][j] = '.';
					}
		}
	}
	Map[0][0] = 'c';
}

void Print(int R, int C) {
	if (!Able) {
		printf("Impossible\n");
		return;
	}
	for (int i = 0; i < R; ++ i) {
		for (int j = 0; j < C; ++ j)
			printf("%c", (R <= C) ? Map[i][j] : Map[j][i]);
		printf("\n");
	}
}

int main() {
	int TestCase = 0;
	cin >> TestCase;
	for (int T = 1; T <= TestCase; ++ T) {
		int R, C, M;
		cin >> R >> C >> M;
		Solve(min(R, C), max(R, C), R * C - M);
		printf("Case #%d:\n", T);
		Print(R, C);
	}
	return 0;
}
