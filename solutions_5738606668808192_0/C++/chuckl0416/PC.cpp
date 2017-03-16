#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TC, T;
int N, J;
char toPrint[50];
long long int BitToN[50][50];/*Base, Length*/
int i, x;

void DFS(int L, int S, int Reversed){
	if (J<=0) return ;
	int i;
	if (S+L>=N){
		if (Reversed){
			printf("%s", toPrint);
			for (i=2; i<=10; i++) printf(" %lld", BitToN[i][L]);
			puts("");
			J--;
		}
		return ;
	}
	
	DFS(L, S+1, Reversed);
	for (i=0; i<L; i++) toPrint[S+i] = '0';
	DFS(L, S+L, 1);
	for (i=0; i<L; i++) toPrint[S+i] = '1';
	
	return ;
}

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	for (i=2; i<=10; i++){
		BitToN[i][1] = 1;
		for (x=2; x<=40; x++) BitToN[i][x] = BitToN[i][x-1]*i + 1;
	}
	
	scanf("%d", &TC);
	for (T=1; T<=TC; T++){
		printf("Case #%d:\n", T);
		scanf("%d%d", &N, &J);
		for (i=0; i<N; i++) toPrint[i] = '1';
		toPrint[N] = '\0';
		
		DFS(2, 1, 0);
		
	}
	
	
	
	return 0;
}


