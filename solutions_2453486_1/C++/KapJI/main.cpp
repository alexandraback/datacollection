#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};

char field[4][4];

void solve() {
	int empty = 0;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			scanf("%c", &field[i][j]);
			if (field[i][j] == '.') {
				empty++;
			}
		}
		scanf("\n");
	}
	scanf("\n");
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (field[i][j] == 'X' || field[i][j] == 'O') {
				for (int k = 0; k < 8; ++k) {
					int cnt = 1;
					for (int d = 1; d < 4; ++d) {		
						int nx = i + dx[k] * d;
						int ny = j + dy[k] * d;
						if (0 <= nx && nx < 4 && 0 <= ny && ny < 4 && (field[nx][ny] == field[i][j] || field[nx][ny] == 'T')) {
							cnt++;
						}
					}
					if (cnt == 4) {
						if (field[i][j] == 'X') {
							printf("X won");
							return;
						}
						if (field[i][j] == 'O') {
							printf("O won");
							return;
						}
					}
				}
			}
		}
	}
	if (empty > 0) {
		printf("Game has not completed");
	} else {
		printf("Draw");
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int i = 0; i < t; ++i) {
		printf("Case #%d: ", i + 1);
		solve();
		printf("\n");
	}
	return 0;
}