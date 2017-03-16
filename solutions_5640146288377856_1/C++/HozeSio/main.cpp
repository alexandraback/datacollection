#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <stdlib.h>
#include <stdio.h>]

using namespace std;

int check(int C, int W){
	if (C == W)
		return W;
	else
		return W + 1;

	int tmp = 0;

	for (int i = 0; i < C%W + W; i++){
		if (i%W == W - 1){
			tmp++;
		}
	}

	tmp += W - 1;
	return W+1;
}

int main(){

	int T;
	scanf("%d", &T);

	FILE *file=fopen("output.txt", "w");

	for (int t = 1; t <= T; t++){

		int R, C, W;
		scanf("%d %d %d", &R, &C, &W);

		int sum = 0;

		if (W == 1){
			fprintf(file,"Case #%d: %d\n", t, R*C);
			continue;
		}
		if (W == C){
			fprintf(file,"Case #%d: %d\n", t, W + (R - 1));
			continue;
		}

		/*
		if (C/2 < W){
			sum += W+1;
		}
		*/

		int tmp = 0;
		for (int j = 0; j < (C/W-1)*W; j++){
			if (j%W == W-1){
				tmp++;
			}

		}
		tmp *= R;
		sum += tmp;
		sum += R - 1;

		sum+=check(C%W + W, W);

		fprintf(file,"Case #%d: %d\n", t, sum );

	}
	fclose(file);

}