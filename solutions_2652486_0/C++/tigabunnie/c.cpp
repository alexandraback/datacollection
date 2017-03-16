#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;


int main(int argc, char **argv) {
	if (argc!=3) {
		printf("provide input and output file names as command line parameters\n");
	}
	FILE *fp_in, *fp_out;
	if ((fp_in=fopen(argv[1],"r"))==NULL) { printf("can't open file %s\n", argv[1]); exit(1); }
	if ((fp_out=fopen(argv[2],"w"))==NULL) { printf("can't open file %s\n", argv[2]); exit(1); }
	
	int num_cases;
	fscanf(fp_in, "%d\n", &num_cases);
	
	int R, N, M, K;
	int i, j, k, digit, power;
	int prod[7];
	char div[8][8];
	int answer[1000];
	int answer_size, num;
	for (int test_case=1; test_case<=num_cases; test_case++) {
		fscanf(fp_in, "%d %d %d %d\n", &R, &N, &M, &K);
		fprintf(fp_out, "Case #%d:\n", test_case);
		for (i=0; i<R; i++) {
			for (j=0; j<K; j++) fscanf(fp_in, "%d", &(prod[j]));
			for (digit=2; digit<=5; digit++) {
				num = digit;
				for (power=1; power<8; power++) {
					div[power][digit] = 0;
					for (k=0; k<K; k++) if ((prod[k] % num)==0) {
						div[power][digit] = 1;
						break;
					}
					num *= digit;
				}
			}
			
			answer_size = 0;
			for (digit=5; digit>=2; digit--) {
				for (power=1; power<8; power++) {
					if (div[power][digit]) answer[answer_size++] = digit;
				}
			}
			for (digit=5; digit>=3; digit--) if (div[1][digit]) break;
			while (answer_size < N) {
				answer[answer_size++] = digit;
			}
			
			for (j=0; j<N; j++) fprintf(fp_out, "%d", answer[j]);
			fprintf(fp_out, "\n");
			
		}	
	}
	
	
	fclose(fp_in);
	fclose(fp_out);
	return 0;
}
