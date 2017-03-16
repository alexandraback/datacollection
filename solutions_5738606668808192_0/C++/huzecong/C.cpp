//Template
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
#include <string>
#include <vector>
#include <bitset>
#include <cstdarg>
#include <complex>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
#define pair(x, y) make_pair(x, y)
#define runtime() ((double)clock() / CLOCKS_PER_SEC)

inline int read() {
	static int r, sign;
	static char c;
	r = 0, sign = 1;
	do c = getchar(); while (c != '-' && (c < '0' || c > '9'));
	if (c == '-') sign = -1, c = getchar();
	while (c >= '0' && c <= '9') r = r * 10 + (int)(c - '0'), c = getchar();
	return sign * r;
}

template <typename T>
inline void print(T *a, int n) {
	for (int i = 1; i < n; ++i) cout << a[i] << " ";
	cout << a[n] << endl;
}
#define PRINT(_l, _r, _s, _t) { cout << #_l #_s "~" #_t #_r ": "; for (int _i = _s; _i != _t; ++_i) cout << _l _i _r << " "; cout << endl; }

const int N = 1 << 16;
ll d[11];

inline ll prime(ll x) {
	for (ll i = 2; i * i <= x; ++i)
		if (!(x % i)) return i;
	return 0LL;
}

int main(int argc, char *argv[]) {
#ifdef KANARI
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	printf("Case #%d:\n", 1);
	int remain = 50;
	for (int x = (1 << 15) | 1; remain > 0 && x < (1 << 16); x += 2) {
		bool ok = true;
		for (int base = 2; ok && base <= 10; ++base) {
			ll y = 0;
			for (int i = 15; i >= 0; --i)
				y = y * base + (x >> i & 1);
			ll p = prime(y);
			if (p == 0) ok = false;
			else d[base] = p;
		}
		if (ok) {
			--remain;
			for (int i = 15; i >= 0; --i)
				printf("%d", x >> i & 1);
			for (int i = 2; i <= 10; ++i)
				printf(" %lld", d[i]);
			printf("\n");
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
