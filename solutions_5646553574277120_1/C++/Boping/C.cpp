#include <cstdio>
#include <cstdlib>

int comp(const void * a, const void * b) {
	return *(int *)a - *(int *)b;
}

int coins[100];

int main() {
	int T, t, C, D, V, i, count;
	long long total;
	FILE * fin = fopen("C.in", "r"), * fout = fopen("C.out", "w");
	fscanf(fin, "%d", &T);
	for (t = 1; t <= T; ++t) {
		fscanf(fin, "%d%d%d", &C, &D, &V);
		for (i = 0; i < D; ++i) {
			fscanf(fin, "%d", coins + i);
		}
		qsort(coins, D, sizeof(int), comp); // not needed
		total = 0;
		count = 0;
		i = 0;
		while (i < D && total < V) {
			if (coins[i] > total + 1) {
				++count;
				total += (total + 1) * C;
			} else {
				total += (long long)coins[i] * C;
				++i;
			}
		}
		while (total < V) {
			++count;
			total += (total + 1) * C;
		}
		fprintf(fout, "Case #%d: %d\n", t, count);
	}
	return 0;
}

