#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 16384;

int n, cnt;

int p[N];

vector<int> primes;

bool test(unsigned st, int base, int mod) {
	int left = 0;
	for (int i = n - 1; i >= 0; --i) {
		left = left * base % mod;
		if (st >> i & 1) {
			left = (left + 1) % mod;
		}
	}
	return left == 0;
}

int main() {
	printf("Case #1:\n");
	for (int i = 2; i < N; ++i) {
		if (!p[i]) {
			primes.push_back(i);
			for (long long j = (long long)i * i; j < N; j += i) {
				p[j] = i;
			}
		}
	}
	scanf("%*d%d%d", &n, &cnt);
	for (unsigned cur = (1u << (n - 1)) | 1; cnt; cur += 2) {
		vector<int> divs;
		for (int base = 2; base <= 10; ++base) {
			for (int i = 0; i < (int)primes.size(); ++i) {
				if (test(cur, base, primes[i])) {
					divs.push_back(primes[i]);
					break;
				}
			}
			if (divs.size() != base - 1) {
				break;
			}
		}
		if (divs.size() == 9) {
			--cnt;
			for (int i = 0; i < n; ++i) {
				printf("%c", '0' + (cur >> (n - i - 1) & 1));
			}
			for (int i = 0; i < 9; ++i) {
				printf(" %d", divs[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
