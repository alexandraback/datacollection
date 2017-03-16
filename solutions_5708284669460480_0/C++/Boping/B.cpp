#include <cstdio>
#include <cstring>

int K, L, S, total, max, scount;

char keyboard[8], target[8], thestring[7];

void brute(int index) {
	int i;
	if (index < S) {
		for (i = 0; i < K; ++i) {
			thestring[index] = keyboard[i];
			brute(index + 1);
		}
	} else {
		int count = 0;
		for (i = 0; i + L <= S; ++i) {
			if (!memcmp(target, thestring + i, L)) {
				++count;
			}
		}
		total += count;
		if (max < count) {
			max = count;
		}
		++scount;
	}
}


int main() {
	int T, t;
	FILE * fin = fopen("B.in", "r"), * fout = fopen("B.out", "w");
	fscanf(fin, "%d", &T);
	for (t = 1; t <= T; ++t) {
		fscanf(fin, "%d%d%d\n%s\n%s", &K, &L, &S, keyboard, target);
		total = 0;
		max = 0;
		scount = 0;
		brute(0);
		fprintf(fout, "Case #%d: %.7f\n", t, max - (double)total / scount);
	}
	return 0;
}
