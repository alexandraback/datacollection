#include <cstdio>

const int MAX_P = 10000;
int TC, N, J;
int D[32];

bool IsPrime[MAX_P];
int Primes[MAX_P];
int NPrimes;
int Divisor[11];

bool solve() {
	for (int base = 2; base <= 10; ++base) {
		bool ok = false;
		for (int pi = 0; pi < NPrimes; ++pi) {
			int prime = Primes[pi];
			int r = 0;
			for (int d = 0; d < N; ++d) {
				r = r * base + D[d];
				r %= prime;
			}
			if (r == 0) {
				Divisor[base] = prime;
				ok = true;
				break;
			}
		}
		if (!ok) {
			return false;
		}
	}
	return true;
}

void printJamcoin() {
	for (int i = 0; i < N; ++i) {
		printf("%d", D[i]);
	}
	for (int base = 2; base <= 10; ++base) {
		printf(" %d", Divisor[base]);
	}
	printf("\n");
}

void go(int d) {
	if (J == 0) return;
	if (d == N - 1) {
		if (solve()) {
			printJamcoin();
			J--;
		}
	} else {
		D[d] = 0;
		go(d + 1);
		D[d] = 1;
		go(d + 1);
	}
}

void seive() {
	for (int i = 2; i < MAX_P; ++i) {
		IsPrime[i] = true;
	}
	for (int i = 2; i * i < MAX_P; ++i) {
		if (IsPrime[i]) {
			for (int j = i * i; j < MAX_P; j += i) {
				IsPrime[j] = false;
			}
		}
	}
	for (int i = 2; i < MAX_P; ++i) {
		if (IsPrime[i]) {
			Primes[NPrimes++] = i;
		}
	}
}

int main() {
	seive();
	scanf("%d%d%d", &TC, &N, &J);
	printf("Case #1:\n");
	D[0] = D[N - 1] = 1;
	go(1);
	return 0;
}
