#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int arrJ[1000], arrP[1000], arrS[1000], numofSet = 0;

int checkArr(int J, int P, int S, int K){
	int JP = 0, PS = 0, JS = 0;
	for (int i = 0; i < numofSet; i++){
		if (arrJ[i] == J && arrP[i] == P&&arrS[i] == S) return 1;
		if (arrJ[i] == J&&arrP[i] == P) JP++;
		if (arrP[i] == P&&arrS[i] == S)PS++;
		if (arrJ[i] == J&&arrS[i] == S)JS++;
		if (JP >= K || PS >= K || JS >= K) return 1;
	}
	return 0;
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("Text.txt", "w", stdout);
	int num;
	scanf("%d", &num);
	getchar();
	for (int i = 0; i < num; i++){
		int J, P, S, K;
		scanf("%d %d %d %d", &J, &P, &S, &K);
		for (int a = 0; a < 1000; a++){
			arrJ[a] = 0;
			arrP[a] = 0;
			arrS[a] = 0;
		}
		numofSet = 0;
		for (int a = 1; a <= S; a++){
			for (int b = 1; b <= P; b++){
				for (int c = 1; c <= J; c++){
					if (checkArr(c, b, a, K) == 0){
						arrJ[numofSet] = c;
						arrP[numofSet] = b;
						arrS[numofSet] = a;
						numofSet++;
					}
				}
			}
		}
		printf("Case #%d: %d\n", i + 1, numofSet);
		for (int j = 0; j < numofSet; j++){
			printf("%d %d %d\n", arrJ[j], arrP[j], arrS[j]);
		}
	}
	return 0;
}