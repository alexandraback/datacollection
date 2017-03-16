#include <cstdio>

const int N = 32, cntP = 5, prime[] = {2, 3, 5, 7, 11};
int J = 500;

int findFactor(long long t, int base) {
	int r[cntP], powmod[cntP];
	for (int i = 0; i < cntP; ++i)
		r[i] = 0, powmod[i] = 1;
	while (t) {
		for (int i = 0; i < cntP; ++i) {
			r[i] += (t & 1) * powmod[i];
			powmod[i] = powmod[i] * base % prime[i];
		}
		t >>= 1;
	}
	for (int i = 0; i < cntP; ++i)
		if (!(r[i] % prime[i])) return prime[i];
	return -1;
}

void work(FILE *ofp) {
	int factor[11];
	bool flag;
	for (long long t = (1LL << (N - 1)) + 1; J; t += 2) {
		flag = true;
		for (int base = 2; base <= 10; ++base) {
			if ((factor[base] = findFactor(t, base)) < 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			for (int i = N - 1; i >= 0; --i)
				fprintf(ofp, "%d", (t >> i) & 1);
			for (int base = 2; base <= 10; ++base)
				fprintf(ofp, " %d", factor[base]);
			fprintf(ofp, "\n");
			--J;
		}
	}
}

int main() {
	FILE *ofp = fopen("C.out", "w");
	fprintf(ofp, "Case #1:\n");
	work(ofp);
	fclose(ofp);
	return 0;
}
