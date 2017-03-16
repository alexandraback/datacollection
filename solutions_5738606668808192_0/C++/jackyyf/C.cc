#include <bits/stdc++.h>

#define LIMIT 8192

using namespace std;

bitset<LIMIT> isPrime;
vector<long> primes;
__int128_t res[16];
__int128_t powres[16][32];
long ans[16];

void generate_prime() {
	primes.push_back(2);
	isPrime.set(2);
	for (long i = 3; i < LIMIT; i += 2) isPrime.set(i);
	for (long i = 3; i < LIMIT; i += 2) {
		if (isPrime.test(i)) {
			primes.push_back(i);
			for (long j = i * i; j < LIMIT; j += (i + i)) isPrime.reset(j);
		}
	}
}

long get_division(const __int128_t res) {
	for (const auto &p : primes) {
		if (res % p == 0) return p;
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	primes.reserve(8192);
	generate_prime();
	for (long i = 2; i <= 10; ++ i) {
		powres[i][0] = 1;
		powres[i][1] = i;
	}
	for (long i = 2; i < 32; ++ i) {
		for (long j = 2; j <= 10; ++ j) {
			powres[j][i] = powres[j][i - 1] * j;
		}
	}
	ofstream fsmall("C-small.out");
	fsmall << "Case #1:" << endl;
	// N = 16, J = 50
	long left = 50;
	for (register long now = (1 << 15) | 1; left > 0; now += 2) {
		memset(res, 0, sizeof res);
		for (long i = 0; i < 16; ++ i) {
			if (now & (1 << i)) {
				for (long x = 2; x <= 10; ++ x) {
					res[x] += powres[x][i];
				}
			}
		}
		bool flag = true;
		for (long x = 2; x <= 10; ++ x) {
			if ((ans[x] = get_division(res[x])) < 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			-- left;
			fsmall << bitset<16>(now).to_string();
			for (long x = 2; x <= 10; ++ x) fsmall << " " << ans[x];
			fsmall << endl;
		}
	}
	fsmall.close();
	ofstream flarge("C-large.out");
	flarge << "Case #1:" << endl;
	// N = 32, J = 500
	left = 500;
	for (register long now = (1 << 31) | 1; left > 0; now += 2) {
		memset(res, 0, sizeof res);
		for (long i = 0; i < 32; ++ i) {
			if (now & (1 << i)) {
				for (long x = 2; x <= 10; ++ x) {
					res[x] += powres[x][i];
				}
			}
		}
		bool flag = true;
		for (long x = 2; x <= 10; ++ x) {
			if ((ans[x] = get_division(res[x])) < 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			-- left;
			flarge << bitset<32>(now).to_string();
			for (long x = 2; x <= 10; ++ x) flarge << " " << ans[x];
			flarge << endl;
		}
	}
	flarge.close();

}
