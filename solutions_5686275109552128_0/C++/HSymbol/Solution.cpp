#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
void main(){
	FILE* input = fopen("B-small-attempt2.in", "r");
	FILE* output= fopen("answer.out", "w");
	int T = 0;
	int D = 0;
	int P[1001] = {};
	int time = 0;
	int max = 0;
	int nownum = 0;
	bool reduced = false;
	fscanf(input,"%d", &T);
	for (int i = 0; i < T; i++){
		for (int j = 0; j < 1001; j++)
			P[j] = 0;
		time = 1000;
		max = 0;
		fscanf(input, "%d", &D);
		for (int j = 0; j < D; j++){
			fscanf(input, "%d", &nownum);
			P[nownum]++;
			if (nownum > max)
				max = nownum;
		}
		for (int j = 1; j <= max; j++){
			nownum = j;
			for (int k = 1; k <= max; k++){
				if (k <= j)
					continue;
				if (k%j==0)
					nownum += P[k]*((k/j)-1);
				else
					nownum += P[k]*(k / j);
			}
			if (nownum < time)
				time = nownum;
		}
		fprintf(output, "Case #%d: %d\n", i + 1,time);
	}
	return;
}