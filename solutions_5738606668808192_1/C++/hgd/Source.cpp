#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <vector>
#include <unordered_set>
using namespace std;

long long N, J, num[32], factor[11];
vector<long long> primes;

long long tmp[32];
long long pos;
const long long BASE = (1LL << 32);

void maketmp(long long b) {
	tmp[0] = 0;
	pos = 0;
	for (long long i = 0; i < N; ++i) {
		for (long long j = 0; j <= pos; ++j) tmp[j] *= b;
		tmp[0] += num[i];
		for (long long j = 0; j < pos; ++j) {
			if (tmp[j] < BASE) continue;
			tmp[j + 1] += tmp[j] / BASE;
			tmp[j] %= BASE;
		}
		if (tmp[pos] >= BASE) {
			tmp[pos + 1] = tmp[pos] / BASE;
			tmp[pos] %= BASE;
			++pos;
		}
	}
}

long long rem(long long prm) {
	long long rtn = 0;
	for (long long i = pos; i >= 0; --i) {
		rtn = rtn * BASE + tmp[i];
		rtn %= prm;
	}
	return rtn;
}

bool check() {
	for (long long base = 2; base <= 10; ++base) {
		maketmp(base);
		factor[base] = -1;
		for (long long prm : primes) {
			long long x = prm * prm;
			long long x0 = x % BASE, x1 = x / BASE;
			if (pos == 0) {
				if (x1 > 0) break;
				if (x0 > tmp[0]) break;
			}
			else if (pos == 1) {
				if (x1 > tmp[1]) break;
				if (x1 == tmp[1] && x0 > tmp[0]) break;
			}
			if (rem(prm) == 0) {
				factor[base] = prm;
				break;
			}
		}
		if (factor[base] == -1) return false;
	}
	return true;
}

void readprime() {
	FILE *fp = fopen("primes1.txt", "r");
	long long p;
	while (fscanf(fp, "%lld", &p) != EOF) {
		primes.push_back(p);
	}
	fclose(fp);
}

int main() {
	readprime();
	srand(time(0));
	FILE *fp = fopen("in.txt", "r");
	FILE *fout = fopen("out.txt", "w");
	int T;
	fscanf(fp, "%d", &T);
	for (int iii = 0; iii < T; ++iii) {
		fscanf(fp, "%lld%lld", &N, &J);
		fprintf(fout, "Case #%d:\n", iii + 1);
		num[0] = 1;
		num[N - 1] = 1;
		unordered_set<long long> store;
		long long n = 0;
		while (n < J) {
			long long tmp = 1;
			for (long long i = 1; i < N - 1; ++i) {
				num[i] = ((rand() >> 2) & 1);
				tmp = (tmp << 1) | num[i];
			}
			tmp = (tmp << 1) | 1;
			if (store.find(tmp) != store.end()) continue;
			if (!check()) continue;
			for (long long i = 0; i < N; ++i) fprintf(fout, "%lld", num[i]);
			for (long long i = 2; i <= 10; ++i) fprintf(fout, " %lld", factor[i]);
			fprintf(fout, "\n");
			++n;
			printf("%lld\n", n);
		}
	}
	fclose(fp);
	fclose(fout);
	return 0;
}