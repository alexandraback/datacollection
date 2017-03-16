#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;


int main() {
	FILE *fpi, *fpo;
	fpi = fopen("D-small-attempt1.in", "r");
	fpo = fopen("smallD1.out", "w");
	int re;
	fscanf(fpi, "%d", &re);
	for (int co = 1; co <= re; co++) {
		fprintf(fpo, "Case #%d:", co);
		unsigned int K, C, S;
		fscanf(fpi, "%d%d%d", &K, &C, &S);
		if (K < C)C = K;
		int t = (K - 1) / C + 1;
		if (t > S)
			fprintf(fpo, " IMPOSSIBLE\n");
		else {
			unsigned long long int sum = 0;
			for (int j = 0; j < t; j++) {
				sum = 0;
				unsigned long long int p = j;
				for (int i = 0; i < C&&p<K; i++) {
					sum = sum*K + p;
					p += t;
				}
				fprintf(fpo, " %lld", sum+1);
			}
			fprintf(fpo, "\n");
		}


	}
	fclose(fpi);
	fclose(fpo);
}