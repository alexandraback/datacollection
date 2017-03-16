#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int c, R, C, M;
bool found;

void print(char gg[][51]){
	printf("Case #%d:\n", c);
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(gg[i][j] != '\0')	printf("%c", i == 0 && j == 0 ? gg[i][j] : '.');
			else					printf("%c", '*');
		}
		printf("\n");
	}
}

int fill(char gg[][51], int x, int y){
	int count = 0;
	for(int k = x - 1; k <= x + 1; k++){
		for(int l = y - 1; l <= y + 1; l++){
			if(k >= 0 && k < R && l >= 0 && l < C && gg[k][l] != '.' && gg[k][l] != 'c'){
				gg[k][l] = '.';
				count++;
			}
		}
	}
	return count;
}

bool solve(int i, int j, int mines, char grid[][51]){
	
	char newGrid[51][51];
	for(int k = 0; k < R; k++){
		for(int l = 0; l < C; l++){
			newGrid[k][l] = grid[k][l];
		}
	}
	
	int count = fill(newGrid, i, j);
	bool done = mines - count == M;
	//print(newGrid);
	if(done)
		print(newGrid);
		
	if(!done && j + 1 < C && newGrid[i][j + 1] != 'c'){
		char temp = newGrid[i][j + 1];
		newGrid[i][j + 1] = 'c';
		done = solve(i, j + 1, mines - count, newGrid);
		newGrid[i][j + 1] = temp;
	}
	if(!done && i + 1 < R && newGrid[i + 1][j] != 'c'){
		char temp = newGrid[i + 1][j];
		newGrid[i + 1][j] = 'c';
		done = solve(i + 1, j, mines - count, newGrid);
		newGrid[i + 1][j] = temp;
	}
	if(!done && j - 1 >= 0 && newGrid[i][j - 1] != 'c'){
		char temp = newGrid[i][j - 1];
		newGrid[i][j - 1] = 'c';
		done = solve(i, j - 1, mines - count, newGrid);
		newGrid[i][j - 1] = temp;
	}
	return done;
}

int main (int argc, char *argv[])
{
	int TC;
	scanf("%d", &TC);
	
	for(c = 1; c <= TC; c++){
		scanf("%d %d %d", &R, &C, &M);
		char grid[51][51];
		memset(grid, '\0', sizeof grid);
		grid[0][0] = 'c';
		if(R*C - 1 == M){
			print(grid);
		}
		else{
			int mines = R*C - 1;
			if(!solve(0, 0, mines, grid))
				printf("Case #%d:\nImpossible\n", c);
			else{
				
			}
		}
	}
	return 0;
}
