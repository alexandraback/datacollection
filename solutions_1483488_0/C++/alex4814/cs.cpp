#include <stdio.h>
#include <math.h>

int A, B;
int moves[10], jx;
int pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

int moving(int num, int d)
{
	return num / 10 + num % 10 * pow10[d];
}

int in(int num)
{
	int i;
	for (i = 0; i < jx; ++i)
		if (moves[i] == num) return 1;
	return 0;
}

int cal()
{
	int i, j;
	int cnt = 0;
	int n, m, d;
	for (i = A; i < B; ++i) {
		m = n = i;
		d = log10(i);
		//printf("d = %d\n", d);
		if (d == 0) return 0;
		for (jx = j = 0; j < d; ++j) {
			m = moving(m, d);
			if (!in(m)) moves[jx++] = m;
		}
		for (j = 0; j < jx; ++j)
			if (moves[j] > n && moves[j] <= B) {
				
				//printf("%d %d\n", n, m);
				++cnt;
			}
	}
	return cnt;
}

int main()
{
	FILE *fin = fopen("C-small-attempt0.in.txt", "r");
	FILE *fout = fopen("csout.txt", "w");

	int i, c, t;
	fscanf(fin, "%d", &t);
	for (c = 1; c <= t; ++c) {
		fscanf(fin, "%d%d", &A, &B);
		fprintf(fout, "Case #%d: %d\n", c, cal());
	}
	return 0;
}
