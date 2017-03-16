#include <cstdio>

const int N = 16;
int J = 50;

long long convert(int t, int base) {
	long long x = 0, p = 1;
	while (t) {
		x += (t & 1) * p;
		p *= base;
		t >>= 1;
	}
	return x;
}

long long findFactor(long long x) {
	for (long long i = 2; i * i <= x; ++i)
		if (!(x % i)) return i;
	return -1;
}

void work(FILE *ofp) {
	int factor[11];
	bool flag;
	for (int t = (1 << (N - 1)) + 1; J; t += 2) {
		flag = true;
		for (int base = 2; base <= 10; ++base) {
			if ((factor[base] = findFactor(convert(t, base))) < 0) {
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
