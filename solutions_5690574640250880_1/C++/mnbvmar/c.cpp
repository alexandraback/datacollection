#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

int R, C, M, MM;

void input(){
	scanf("%d%d%d", &R, &C, &M);
	MM = M;
}

bool chg[70][70];

void test(){
	input();
	printf("\n");
	M = R*C-M;
	
	if(R == 1){
		printf("c");
		for(int i = 1; i < M; i++)
			printf(".");
		for(int i = M; i < C; i++)
			printf("*");
		printf("\n");
		return;
	}
	
	if(C == 1){
		printf("c\n");
		for(int i = 1; i < M; i++)
			printf(".\n");
		for(int i = M; i < R; i++)
			printf("*\n");
		return;
	}
	
	if(M == 1){
		printf("c");
		for(int i = 1; i < C; i++) printf("*");
		printf("\n");
		for(int i = 1; i < R; i++){
			for(int j = 0; j < C; j++) printf("*");
			printf("\n");
		}
		return;
	}
	
	if(R == 2){
		if(M == 0 || M == 2 || M % 2 != 0){
			printf("Impossible\n");
			return;
		}
		M /= 2;
		printf("c");
		for(int i = 1; i < M; i++)
			printf(".");
		for(int i = M; i < C; i++)
			printf("*");
		printf("\n");
		for(int i = 0; i < M; i++)
			printf(".");
		for(int i = M; i < C; i++)
			printf("*");
		printf("\n");
		return;
	}
	
	if(C == 2){
		if(M == 0 || M == 2 || M % 2 != 0){
			printf("Impossible\n");
			return;
		}
		M /= 2;
		
		printf("c.\n");
		for(int i = 1; i < M; i++)
			printf("..\n");
		for(int i = M; i < R; i++)
			printf("**\n");
		return;
	}
	
	if(M == 0 || M == 2 || M == 3 || M == 5 || M == 7){
		printf("Impossible\n");
		return;
	}
	
	for(int i = 0; i < R; i++)
		fill(chg[i], chg[i]+60, false);
	
	// i == 0
	int pos = 0;
	M -= 2;
	while(pos < C-1 && M != 0 && M != 3){
		chg[0][pos++] = true;
		M -= 2;
	}
	
	for(int i = 1; i < R-1; i++){
		if(!M) break;
		M--;
		pos = 0;
		while(pos < C-1 && M != 0 && (i == R-2 || M != 2 || pos < C-2)){
			chg[i][pos++] = true;
			M--;
		}
	}
	
	int NumM = 0;
	
	printf("c");
	for(int j = 1; j < C; j++){
		printf(chg[0][j-1] ? "." : "*");
		if(!chg[0][j-1]) NumM++;
	}
	printf("\n");
	
	for(int i = 1; i < R; i++){
		for(int j = 0; j < C; j++){
			bool ok = (chg[i][j] || chg[i-1][j] ||
			           (j && chg[i][j-1]) ||
			           (j && chg[i-1][j-1]));
						
			printf(ok ? "." : "*");
			if(!ok) NumM++;
		}
		printf("\n");
	}
	
	if(NumM != MM){
		printf("EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE\n");
		exit(1);
	}
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		printf("Case #%d:", i);
		test();
	}
}

