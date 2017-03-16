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

#define SZ 100
#define INF 1e100

int ac[SZ][SZ];
int af[SZ][SZ];
int au[SZ][SZ];
double at[SZ][SZ];

double calc(int f1, int c1, int f2, int c2, double h) {
	if (c1 - f1 < 50) return INF;
	if (c1 - f2 < 50) return INF;
	if (c2 - f1 < 50) return INF;
	if (c2 - f2 < 50) return INF;
	return max(0.0, (h - (c2 - 50)) / 10.0);
}

int dx[4] = {0, 0, -1, +1};
int dy[4] = {-1, +1, 0, 0};

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int h, n, m; scanf("%d %d %d", &h, &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &ac[i][j]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &af[i][j]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				at[i][j] = INF;
		
		vector<pii> q;
		at[0][0] = 0, q.push_back(pii(0, 0));
		for (int k = 0; k < (int) q.size(); k++) {
			int i = q[k].first, j = q[k].second;
			for (int d = 0; d < 4; d++) {
				int in = i + dy[d], jn = j + dx[d];
				if (!(0 <= in && in < n && 0 <= jn && jn < m)) continue;
				double dt = calc(af[i][j], ac[i][j], af[in][jn], ac[in][jn], h);
				if (dt < at[in][jn] && dt < 0.001)
					at[in][jn] = 0, q.push_back(pii(in, jn));
			}
		}
		
		while (!q.empty()) {
			vector<pii> qn;
			for (int k = 0; k < (int) q.size(); k++) {
				int i = q[k].first, j = q[k].second;
				for (int d = 0; d < 4; d++) {
					int in = i + dy[d], jn = j + dx[d];
					if (!(0 <= in && in < n && 0 <= jn && jn < m)) continue;
					double ho = max(0.0, h - at[i][j] * 10);
					double dt = calc(af[i][j], ac[i][j], af[in][jn], ac[in][jn], ho);
					double hn = max(0.0, h - (at[i][j] + dt) * 10);
					double tn = (at[i][j] + dt) + (hn - af[i][j] < 20 ? 10 : 1);
					if (tn < at[in][jn])
						at[in][jn] = tn, qn.push_back(pii(in, jn));
				}
			}
			q.swap(qn);
		}
		
		printf("Case #%d: %lf\n", t, at[n-1][m-1]);
	}
	return 0;
}
