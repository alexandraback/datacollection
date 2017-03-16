#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
void main(){
	FILE* input = fopen("D-small-attempt0.in", "r");
	FILE* output= fopen("answer.out", "w");
	int T = 0;
	int X = 0;
	int R = 0;
	int C = 0;
	fscanf(input,"%d", &T);
	for (int i = 0; i < T; i++){
		fscanf(input, "%d", &X);
		fscanf(input, "%d", &R);
		fscanf(input, "%d", &C);
		if (X > 6){
			fprintf(output, "Case #%d: RICHARD\n", i + 1);
			continue;
		}
		if ((R*C) % X !=0){
			fprintf(output, "Case #%d: RICHARD\n", i + 1);
			continue;
		}
		if (X == 3 && (R<2 || C<2)){
			fprintf(output, "Case #%d: RICHARD\n", i + 1);
			continue;
		}
		if (X == 4 && (R<3 || C<3)){
			fprintf(output, "Case #%d: RICHARD\n", i + 1);
			continue;
		}
		fprintf(output, "Case #%d: GABRIEL\n", i + 1);
	}
	return;
}