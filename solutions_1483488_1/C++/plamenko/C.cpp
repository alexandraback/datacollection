#define _CRT_SECURE_NO_DEPRECATE
//#define _CRT_RAND_S

//#include <windows.h>
//#include <tchar.h>
//#include <atlbase.h>
//#include <winerror.h>

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

#include <gmpxx.h>
//typedef int64_t mpz;
typedef mpz_class mpz;
typedef mpq_class mpq;
typedef mpf_class mpf;

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

int main() {
	set<int> su;
	vector<vector<int>> vv;

	int U = 2000000;
	
	int e = 0, w = 1;
	for (int i = 10; i <= U; i++) {
		if (su.find(i) != su.end()) continue;
		while (w * 10 <= i) w *= 10, e++;
		int j = i;
		vector<int> t;
		for (int k = 0; k <= e; k++) {
			j = (j % 10) * w + (j / 10);
			if (w < j && j <= U && su.find(j) == su.end())
				t.push_back(j), su.insert(j);
		}
		sort(t.begin(), t.end());
		if (t.size() > 1) vv.push_back(t);
	}

	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int a, b;
		scanf("%d %d", &a, &b);
		
		ll r = 0;
		for (int i = 0; i < (int) vv.size(); i++) {
			int l = upper_bound(vv[i].begin(), vv[i].end(), b) - lower_bound(vv[i].begin(), vv[i].end(), a);
			r += l * (l - 1) / 2;
		}
		printf("Case #%d: %lld\n", t, r);
	}
	
	return 0;
}
