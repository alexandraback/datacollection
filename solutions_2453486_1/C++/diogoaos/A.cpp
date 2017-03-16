#include <cstdio>
#include <cstring>

int lines[5][2], columns[5][2], diagonals[2][2];
char mat[5][5];
bool haspoint, xwin, owin;

void fill(int *arr, char c) {
	if (c == 'X') arr[0]++;
	if (c == 'O') arr[1]++;
	
	if (c == 'T') arr[0]++, arr[1]++;
	
	if (arr[0] == 4) xwin = true;
	if (arr[1] == 4) owin = true;
	
	if (c == '.') haspoint = true;
}

int main() {
	int ntests;
	
	scanf("%d", &ntests);
	for (int test = 0; test < ntests; test++) {
		for (int l = 0; l < 4; l++) {
			scanf("%s", mat[l]);
		}
		
		memset(lines, 0, sizeof(lines));
		memset(columns, 0, sizeof(columns));
		memset(diagonals, 0, sizeof(diagonals));
		haspoint = xwin = owin = false;
		
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i == j) fill(diagonals[0], mat[i][j]);
				if (i + j == 3) fill(diagonals[1], mat[i][j]);
				fill(lines[i], mat[i][j]);
				fill(columns[j], mat[i][j]);
			}
		}
		
		printf("Case #%d: ", test + 1);
		if (xwin) printf("X won\n");
		else if (owin) printf("O won\n");
		else if (haspoint) printf("Game has not completed\n");
		else printf("Draw\n");
		
	}
	return 0;
}
