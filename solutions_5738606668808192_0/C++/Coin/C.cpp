#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <bitset>
#include <algorithm>
using namespace std;

const int MAXP = 70000;
int primer[MAXP], np = 0;
bool isCnum[MAXP] = {};

void genPrimer() {
	for (int i = 2; i*i < MAXP; i++) {
		if (isCnum[i]) continue;
		for (int j = i*i; j < MAXP; j += i) {
			isCnum[j] = true;
		}
	}
	for (int i = 2; i < MAXP; i++) {
		if (!isCnum[i])
			primer[np++] = i;
	}
}


long long getVal(long long num, int base) {
	long long res = 0;
	for (long long i = 1; num; i *= base, num /= 2) 
		res += i * (num % 2);
	return res;
}

void printBinary(long long num) {
	long long base = 1;
	while (base < num) base *= 2;
	base /= 2;
	while (num) {
		printf("%lld", num / base);
		num %= base;
		base /= 2;
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	genPrimer();
	int T, kase = 0;
	scanf("%d", &T);
	while (++kase <= T) {
		int N, J;
		scanf("%d%d", &N, &J);
		printf("Case #%d:\n", kase);
		long long m = 1 << N;
		for (long long i = ((long long)1<<(N-1))+1, cnt = 0; i < ((long long)1 << N) && cnt < J; i += 2) {
			int factor[11] = {};
			int j;
			for (j = 2; j <= 10; j++) {
				long long val = getVal(i, j);
				bool isOk = false;
				for (int k = 0; k < np && (long long)primer[k] * primer[k] < val; k++) {
					if (val % primer[k] == 0){
						isOk = true;
						factor[j] = primer[k];
						break;
					}
				}
				if (!isOk) break;
			}
			if (j > 10) {
				printBinary(i);
				for (int i = 2; i <= 10; i++)
					printf(" %d", factor[i]);
				printf("\n");
				cnt++;
			}
		}
	}

	return 0;
}