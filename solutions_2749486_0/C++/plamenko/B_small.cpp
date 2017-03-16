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

char xc[2][2] = {{'W', 'E'}, {'E', 'W'}};
char yc[2][2] = {{'S', 'N'}, {'N', 'S'}};

char s[512];

int main() {
	freopen("in.txt", "r", stdin);
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int x, y; scanf("%d %d", &x, &y);
		int xd = (x > 0) ? 1 : 0; x = abs(x);
		int yd = (y > 0) ? 1 : 0; y = abs(y);
		int i = 0;
		while (x > 0) s[i++] = xc[xd][1], s[i++] = xc[xd][0], x--;
		while (y > 0) s[i++] = yc[yd][1], s[i++] = yc[yd][0], y--;
		s[i] = 0;
		printf("Case #%d: %s\n", t, s);
	}
	return 0;
}
