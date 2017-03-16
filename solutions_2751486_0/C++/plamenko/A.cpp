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
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int64_t isq(int32_t x) { return int64_t(x)*x; }
int64_t isq(int64_t x) { return int64_t(x)*x; }
int32_t isqrt(int64_t x) { if (x <= 0) return 0; int32_t q = int32_t(floor(sqrt(double(x)))); while (isq(q) > x) q--; while (isq(q+1) <= x) q++; return q; }
int32_t isqrtc(int64_t x) { if (x <= 0) return 0; int32_t q = int32_t(ceil(sqrt(double(x)))); while (isq(q) < x) q++; while (q > 0 && isq(q-1) >= x) q--; return q; }

#define SZ 1000000
char s[SZ+1];

bool is_vowel(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int n; scanf("%s %d", s, &n);
		ll r = 0;
		int c = 0; int lo = -1, hi = 0;
		for (hi = 0; s[hi]; hi++) {
			if (!is_vowel(s[hi])) {
				if (++c >= n) {
					lo = hi - n + 1;
				}
			}
			else {
				c = 0;
			}
			r += lo + 1;
		}
		printf("Case #%d: %lld\n", t, r);
	}
	return 0;
}
