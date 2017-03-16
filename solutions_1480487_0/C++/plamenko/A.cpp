#define _CRT_SECURE_NO_DEPRECATE

#include <stdint.h>
#include <climits>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <string>
#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

//#include <gmpxx.h>
//typedef mpz_class mpz;
//typedef mpq_class mpq;
//typedef mpf_class mpf;

//mpz int64_to_mpz(int64_t x) { return (mpz(int32_t(x >> 32)) << 32) | mpz(uint32_t(x & 0xFFFFFFFF)); }
//int64_t mpz_to_int64(mpz x) { mpz xh = x >> 32, xl = x & 0xFFFFFFFF; return (int64_t(xh.get_si()) << 32) | uint64_t(xl.get_ui()); }
//int is_prime(int64_t x, int iter = 8) { return mpz_probab_prime_p(int64_to_mpz(x).get_mpz_t(), iter); }
//int64_t next_prime(int64_t x) { mpz p; mpz_nextprime(p.get_mpz_t(), int64_to_mpz(x).get_mpz_t()); return mpz_to_int64(p); }
//int64_t sq(int32_t x) { return int64_t(x)*x; }
//int32_t isqrt(int64_t x) { int32_t q = int32_t(sqrt(double(x))); if (sq(q) > x) q--; if (q < _I32_MAX && sq(q+1) <= x) q++; return q; }
//int32_t isqrtc(int64_t x) { int32_t q = int32_t(ceil(sqrt(double(x)))); if (sq(q) < x) q++; if (q > 0 && sq(q-1) >= x) q--; return q; }
//int is_square(int64_t x) { return (sq(isqrt(x)) == x); }
//mpz z_pow(mpz x, int n) { mpz r; mpz_pow_ui(r.get_mpz_t(), x.get_mpz_t(), n); return r; }
//int f_int(mpf x) { return mpf_get_si(x.get_mpf_t()); }
//mpf f_sqrt(int n) { mpf r; mpf_sqrt_ui(r.get_mpf_t(), n); return r; }
//mpf f_abs(mpf x) { mpf r; mpf_abs(r.get_mpf_t(), x.get_mpf_t()); return r; }
//mpf f_floor(mpf x) { mpf r; mpf_floor(r.get_mpf_t(), x.get_mpf_t()); return r; }
//template<typename T> T sq(T x) { return x * x; }

int a[256];
int u[256];
double r[256];

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int n; scanf("%d", &n);
		double s = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
			s += a[i];
			u[i] = 0;
		}
		for (;;) {
			int b = 0;
			int cl = 0;
			double sl = 0;
			for (int i = 0; i < n; i++) {
				if (!u[i]) sl += a[i], cl++;
				r[i] = 0;
			}
			for (int i = 0; i < n; i++) {
				if (!u[i]) r[i] = ((s + sl) / cl - a[i]) / s;
			}
			for (int i = 0; i < n; i++) {
				if (r[i] < 0) u[i] = 1, b = 1;
			}
			if (!b) break;
		}

		printf("Case #%d:", t);
		for (int i = 0; i < n; i++) {
			printf(" %lf", 100 * r[i]);
		}
		printf("\n");
	}
	return 0;
}
