#include <cstdio>

#define N 32 //currently N should be even
#define J 500 //and J <= 2^(N/2-1)

// so we can take each digit's position (n^d) and mod by n + 1,
// resulting in 1,-1,1,-1... values
// thus all numbers where sum of even numbered digits equals sum of odd numbered digits is 0 mod n + 1
// for simplicity we'll just have pairs of adjacent digits be equal

int main() {
	FILE * fout = fopen("c.out", "w");
	int i, d;
	fprintf(fout, "Case #1:\n");
	for (i = 0; i < J; ++i) {
		fprintf(fout, "1");
		for (d = N / 2 - 2; d >= 0; --d) fprintf(fout, i & (1 << d) ? "11" : "00");
		fprintf(fout, "1 3 2 5 2 7 2 3 2 11\n");
	}
	return 0;
}