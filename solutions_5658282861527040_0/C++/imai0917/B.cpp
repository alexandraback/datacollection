#include <stdio.h>

FILE *fin, *fout;
void process(int A, int B, int K)
{
	int a, b, dab=0;
	for (a=0;a<A;++a){
		for (b=0;b<B;++b){
			if ((a&b) < K) ++dab;
		}
	}
	fprintf(fout, "%d\n", dab);
}
int main(void)
{
	int T, t;
	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");
	fscanf(fin, "%d", &T);
	for (t=1;t<=T;++t){
		fprintf(fout, "Case #%d: ", t);
		int A, B, K;
		fscanf(fin, "%d %d %d", &A, &B, &K);
		process(A, B, K);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
