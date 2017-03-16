#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

int J, P, S, K;
int AnswerN;
char Answer[1000][15];
int JP[11][11];
int JS[11][11];
int PS[11][11];

int main() {
	//FILE *fi = fopen("sample.in", "r");
	//FILE *fi = fopen("C-large.in", "r");
	FILE *fi = fopen("C-small-attempt0.in", "r");
	FILE *fo = fopen("output.txt", "w");
	int T;

	fscanf(fi, "%d", &T);
	for (int t = 1; t <= T; t++) {
		fscanf(fi, "%d %d %d %d", &J, &P, &S, &K);
		memset(JP, 0, sizeof JP);
		memset(JS, 0, sizeof JS);
		memset(PS, 0, sizeof PS);
		AnswerN = 0;
		for (int j = 1; j <= J; j++) {
			for (int p = 1; p <= P; p++) {
				for (int s = 1; s <= S; s++) {
					if (JP[j][p] < K && JS[j][s] < K && PS[p][s] < K) {
						JP[j][p]++;
						JS[j][s]++;
						PS[p][s]++;
						sprintf(Answer[AnswerN], "%d %d %d", j, p, s);
						AnswerN++;
					}
				}
			}
		}




		fprintf(fo, "Case #%d: %d\n", t, AnswerN);
		for (int i = 0; i < AnswerN; i++) {
			fprintf(fo, "%s\n", Answer[i]);
		}
	}

	fclose(fi);
	fclose(fo);
	return 0;
}
