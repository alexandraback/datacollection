#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
void main(){
	FILE* input = fopen("A-small-attempt2.in", "r");
	FILE* output= fopen("answer.out", "w");
	int T = 0;
	int Sm=0;
	int result;
	int r,mul;
	fscanf(input,"%d", &T);
	for (int i = 0; i < T; i++){
		fscanf(input, "%d", &Sm);
		result = 0;
		r = 0;
		mul = 0;
		char * shy = (char*)malloc(1001*sizeof(char));
		fscanf(input, "%s", shy);
		for (int j = 0; j <= Sm; j++){
			if (shy[j] - 48 == 0){
				if (r == 0){
					mul++;
					result++;
				}
				else
					r--;
			}
			else{
				mul = 0;
				r += shy[j] - 49;
			}
		}
		result -= mul;
		fprintf(output, "Case #%d: %d\n", i+1, result);
	}
	return;
}