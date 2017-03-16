#include<stdio.h>
#include<string.h>

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

int A() 
{
	int J,P,S,K;
	int C_J[12][12] = { 0, }, C_P[12][12] = { 0, }, C_S[12][12] = { 0, },Cnt=0;
	int D_J[12][12] = { 0, }, D_P[12][12] = { 0, }, D_S[12][12] = { 0, };
	fscanf(in, "%d%d%d%d", &J, &P,&S,&K);
	int i, j, k, l;

	for (i = 1; i <= J; i++) {
		for (j = 1; j <= P; j++) {
			for (k = 1; k <= S; k++) {
				if (C_J[j][k] >= K || C_P[i][k] >= K || C_S[i][j] >= K) continue;

				C_J[j][k]++;
				C_P[i][k]++;
				C_S[i][j]++;
				Cnt++;
			}
		}
	}

	fprintf(out,"%d\n", Cnt);

	for (i = 1; i <= J; i++) {
		for (j = 1; j <= P; j++) {
			for (k = 1; k <= S; k++) {
				if (D_J[j][k] >= K || D_P[i][k] >= K || D_S[i][j] >= K) continue;

				D_J[j][k]++;
				D_P[i][k]++;
				D_S[i][j]++;
				fprintf(out, "%d %d %d\n", i, j, k);
			}
		}
	}

	return 0;
}

int main()
{
	int T,i=1; fscanf(in,"%d",&T);

	while (T--) {
		fprintf(out,"Case #%d: ",i++);
		A();
	}

	return 0;
}