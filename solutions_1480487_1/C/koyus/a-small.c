#include <stdio.h>

int main() {
	int i, j, k, T, N;
	int s[1000];
	int flag[1000];
	int flagnum;
	int total;
	int max, maxi;
	int flagsum;
	double score;
	FILE *in, *out;

	in = fopen("A-large.in", "r");
	out = fopen("output.txt", "w");

	fscanf(in, "%d", &T);

	for(i = 0; i < T; i++) {

		// 各Caseの読み込み
		fscanf(in, "%d", &N);
		total = 0;
		for (j = 0; j < N; j++) {
			fscanf(in, "%d", &s[j]);
			total += s[j];
			flag[j] = 0;
		}

		flagnum = 0;
		flagsum = 0;
		while (1) {
			max = -1;
			// フラグなしで最大値見つける
			for (j = 0; j < N; j++) {
				if (flag[j] == 1) continue;
				if (max < s[j]) {
					max = s[j];
				}
			}
			// もし条件を満たせば，
			// 最大値にフラグをたてる
			if ( 2 * total - (max * (N - flagnum)) - flagsum < 0) {
				for (j = 0; j < N; j++) {
					if (s[j] == max) {
						flag[j] = 1;
						flagnum++;
						flagsum += s[j];
					}
				}
			}else{
				break;
			}
		}

		fprintf(out, "Case #%d:", i+1);
		for (j = 0; j < N; j++) {
			if (flag[j] == 1) {
				fprintf(out, " %f", 0.0);
			}else{
				score = total;
				for (k = 0; k < N; k++) {
					if (flag[k] == 1) continue;
					score -= (s[j] - s[k]);
				}
				score = score / ((N - flagnum) * total);
				fprintf(out, " %f", score*100);
			}
		}
		fprintf(out, "\n");
	}
	fclose(in);
	fclose(out);
}
