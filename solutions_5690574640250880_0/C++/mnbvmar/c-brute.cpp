#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int R, C, M, MM;

void input(){
	scanf("%d%d%d", &R, &C, &M);
	MM = M;
}

bool taken[6][6];
bool good[6][6];
bool vis[6][6];

const int X[9] = {-1, -1, -1,  0,  0,  0,  1,  1,  1},
          Y[9] = {-1,  0,  1, -1,  0,  1, -1,  0,  1};

int nn = 0;

void dfs(int i, int j){
	if(vis[i][j]) return;
	if(!taken[i][j]) return;
	vis[i][j] = true;
	
	if(i) dfs(i-1, j);
	if(j) dfs(i, j-1);
	if(i<R-1) dfs(i+1,j);
	if(j<C-1) dfs(i,j+1);
}

bool check(){
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			vis[i][j] = false;
	
	bool cont = true;
	for(int i = 0; i < R; i++){
		if(!cont) break;
		for(int j = 0; j < C; j++){
			if(taken[i][j]){
				dfs(i,j);
				cont = false;
				break;
			}
		}
	}
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			if(taken[i][j] && !vis[i][j])
				return false;
	
	//printf("A %d\n", ++nn);
	int num = 0;
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++){
			for(int m = 0; m < 9; m++){
				int ni = i+Y[m], nj = j+X[m];
				if(ni>=0 && ni < R && nj>=0 && nj < C && taken[ni][nj]){
					good[i][j] = true;
					num++;
					break;
				} else {
					good[i][j] = false;
				}
			}
		}
	//printf("B %d %d\n", num, M);
	if(num + M == R*C){
		bool pr = false;
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				if(taken[i][j] && !pr){
					printf("c");
					pr = true;
				} else if(good[i][j]){
					printf(".");
				} else {
					printf("*");
				}
			}
			printf("\n");
		}
		return true;
	}
	return false;
}

bool brute(int i, int j){
	if(i == R){ return check(); }
	if(j == C){ return brute(i+1, 0); }
	//printf("brute(%d,%d)\n", i,j);
	
	taken[i][j] = false;
	if(brute(i, j+1)) return true;
	
	/*if(i && j && !taken[i-1][j] && !taken[i][j-1])
		return;
	if(i && !j && !taken[i-1][j])
		return;
	if(!i && j && !taken[i][j-1])
		return;*/
	taken[i][j] = true;
	if(brute(i, j+1)) return true;
	taken[i][j] = false;
	
	return false;
}

void test(){
	input();
	printf("\n");
	
	if(M == R*C-1){
		printf("c");
		for(int i = 0; i < C-1; i++) printf("*");
		printf("\n");
		for(int i = 1; i < R; i++){
			for(int j = 0; j < C; j++)
				printf("*");
			printf("\n");
		}
		return;
	}
	
	if(!brute(0, 0)){
		printf("Impossible\n");
	}
}

int main(){
	setlinebuf(stdout);
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		printf("Case #%d:", i);
		test();
	}
}
