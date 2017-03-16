
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

int one_line_fill(char grid[51][51], int R, int C, int M){
	for (int r = 1; r <= R; r++){
		for (int c = 1; c <= C; c++){
			if (r == R && c == C) grid[r][c] = 'c';
			else if (M){
				grid[r][c] = '*'; M--;
			}
			else grid[r][c] = '.';
		}
	}
	return M;
}

void print_grid(char grid[51][51], int R, int C){
	for (int r = 1; r <= R; r++){
		for (int c = 1; c <= C; c++){
			printf("%c", grid[r][c]);
		}
		printf("\n");
	}
}

int main(){
	int T;
	char grid[51][51];
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t){
		int R, C, M, S;
		scanf("%d %d %d", &R, &C, &M);
		printf("Case #%d:\n", t);

		for (int r = 1; r <= R; r++){
			for (int c = 1; c <= C; c++){
				grid[r][c] = '*';
			}
		}
		grid[1][1] = 'c';
		S = R*C - M - 1;
		if (S < 0){
			printf("Impossible\n");
			continue;
		}

		if (S == 0){
			print_grid(grid, R, C);
			continue;
		}

		if (R == 1 || C == 1){
			one_line_fill(grid, R, C, M);
			print_grid(grid, R, C);
			continue;
		}

		if (R == 2 || C == 2){
			if (M % 2 == 1){
				printf("Impossible\n");
				continue;
			}
		}

		if (S == 1 || S == 2 || S == 4 || S == 6){
			printf("Impossible\n");
			continue;
		}
		
		grid[1][2] = grid[2][1] = grid[2][2] = '.';
		S -= 3;
		int r(3), c(3);
		while (S>=2 && (r <= R || c<=C)){
			if (S >= 2 && r<=R){
				grid[r][1] = grid[r][2] = '.';
				++r;
				S -= 2;
			}
			if (S >= 2 && c<=C){
				grid[1][c] = grid[2][c] = '.';
				++c;
				S -= 2;
			}
		}
		int d(6);
		r = 3;
		while (S){
			c = d - r;
			if (r<=R && c <= C){
				grid[r][c] = '*';
				S--;
			}
			if (r+3 >= d){
				d++;
				r = 3;
			}
			else
				r++;
		}
		print_grid(grid, R, C);
	}
	return 0;
}
