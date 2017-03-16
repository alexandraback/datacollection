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

int64_t isq(int32_t x) { return int64_t(x)*x; }
int64_t isq(int64_t x) { return int64_t(x)*x; }
int32_t isqrt(int64_t x) { if (x <= 0) return 0; int32_t q = int32_t(floor(sqrt(double(x)))); while (isq(q) > x) q--; while (isq(q+1) <= x) q++; return q; }
int32_t isqrtc(int64_t x) { if (x <= 0) return 0; int32_t q = int32_t(ceil(sqrt(double(x)))); while (isq(q) < x) q++; while (q > 0 && isq(q-1) >= x) q--; return q; }

char w[32];
int is_pali(ll n) {
	sprintf(w, "%lld", n);
	int l = 0; for (l = 0; w[l]; l++);
	for (int i = 0; i < l-1 - i; i++)
		if (w[i] != w[l-1 - i]) return 0;
	return 1;
}

int sn = 0;
int s[10000000+1];
int count(int n) {
	while (sn < n) {
		sn++;
		s[sn] = s[sn - 1] + (is_pali(sn) && is_pali(isq(sn)));
	}
	return s[n];
}

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		int qa = isqrtc(a), qb = isqrt(b);
		int r = count(qb) - count(qa - 1);
		printf("Case #%d: %d\n", t, r);
	}
	return 0;
}
