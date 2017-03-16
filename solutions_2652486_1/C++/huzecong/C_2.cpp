//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <ios>
#include <iomanip>
#include <ctime>
#include <numeric>
#include <functional>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <bitset>
#include <cstdarg>
using namespace std;

inline int read() {
	static int r;
	static char c;
	r = 0, c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') r = r * 10 + (c - '0'), c = getchar();
	return r;
}

typedef long long ll;
#define pair(x, y) make_pair(x, y)
#define runtime() ((double)clock() / CLOCKS_PER_SEC)

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

int T, n, m, k, cnt[10], p[100];

inline bool tryfill(int _a, int _b, int _c, int _d, int _e) {
	for (int i = 1; i <= k; ++i) {
		int x = p[i], c2 = 0, c3 = 0, a = _a, b = _b, c = _c, d = _d, e = _e;
		while (!(x & 1)) ++c2, x >>= 1;
		while (x > 1) ++c3, x /= 3;
		
		while (c2 > 0 && c3 > 0 && d > 0) --d, --c2, --c3;
		while (c3 > 0 && b > 0) --c3, --b;
		if (c3 > 0) return false;
		while (c2 > 2 && e > 0) c2 -= 3, --e;
		while (c2 > 1 && c > 0) c2 -= 2, --c;
		while (c2 > 0 && a > 0) --c2, --a;
		if (c2 > 0) return false;
	}
	return true;
}

int main() {
#ifdef KANARI
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	scanf("%*d%d%d%d%d", &T, &n, &m, &k);
	printf("Case #1:\n");
	while (T--) {
		for (int i = 1; i <= k; ++i) scanf("%d", p + i);
		
		int l = 1;
		for (int i = 1; i <= k; ++i)
			l *= p[i] / gcd(l, p[i]);
		
		memset(cnt, 0, sizeof cnt);
		for (int i = 2; i <= m; ++i)
			while (!(l % i)) ++cnt[i], l /= i;
		
		int left = n;
		while (cnt[5] > 0) --cnt[5], --left, printf("5");
		while (cnt[7] > 0) --cnt[7], --left, printf("7");
		for (int i = 1; i <= k; ++i) {
			while (!(p[i] % 5)) p[i] /= 5;
			while (!(p[i] % 7)) p[i] /= 7;
		}
		
		int a = cnt[2], b = cnt[3], c = 0, d = 0, e = 0;
		while (a + b + c + d + e > left) {
			if (a + b - left >= 2 && a >= 3 && tryfill(a - 3, b, c, d, e + 1)) ++e, a -= 3;
			else if (a >= 1 && b >= 1 && tryfill(a - 1, b - 1, c, d + 1, e)) ++d, --a, --b;
			else if (a >= 2 && tryfill(a - 2, b, c + 1, d, e)) ++c, a -= 2;
			else break;
		}
		
		if (a + b + c + d + e > left) {
			while (left > 0) printf("2"), --left;
		} else {
			while (a > 0) printf("2"), --a, --left;
			while (b > 0) printf("3"), --b, --left;
			while (c > 0) printf("4"), --c, --left;
			while (d > 0) printf("6"), --d, --left;
			while (e > 0) printf("8"), --e, --left;
			while (left > 0) printf("2"), --left;
		}
		printf("\n");
	}
	
	return 0;
}

