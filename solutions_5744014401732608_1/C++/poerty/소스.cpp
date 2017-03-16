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
		if (JP>=K || PS >= K || JS >= K) return 1;
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
		long long int M;
		int B;
		scanf("%d %lld", &B, &M);
		if (M>pow((long double)2, (long double)(B - 2))){
			printf("Case #%d: IMPOSSIBLE\n", i + 1);
		}
		else if (M == pow((long double)2, (long double)(B - 2))){
			int binaryM[100];
			int len = 0;
			for (int j = 0; j < 100; j++){
				binaryM[j] = 0;
			}
			while (M != 0){
				binaryM[len] = M % 2;
				len++;
				M = M / 2;
			}
			printf("Case #%d: POSSIBLE\n", i + 1);
			for (int j = 0; j < B - 1; j++){
				for (int k = 0; k < B; k++){
					if (k <= j)printf("0");
					else if (k < (B - 1)) printf("1");
					else{
						printf("1");
					}
				}
				printf("\n");
			}
			for (int k = 0; k < B; k++)printf("0");
			printf("\n");
		}
		else{
			int binaryM[100];
			int len = 0;
			for (int j = 0; j < 100; j++){
				binaryM[j] = 0;
			}
			while (M != 0){
				binaryM[len] = M % 2;
				len++;
				M = M / 2;
			}
			printf("Case #%d: POSSIBLE\n", i + 1);
			for (int j = 0; j < B - 1; j++){
				for (int k = 0; k < B; k++){
					if (k<=j)printf("0");
					else if (k < (B - 1)) printf("1");
					else{
						if (j == 0) printf("0");
						else printf("%d", binaryM[j-1]);
					}
				}
				printf("\n");
			}
			for (int k = 0; k < B; k++)printf("0");
			printf("\n");
			
		}
	}
	return 0;
}