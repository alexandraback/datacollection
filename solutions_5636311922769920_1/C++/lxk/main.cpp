#include <bits/stdc++.h>
#include <stdint.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef uint8_t byte;
typedef int16_t i16;
typedef uint16_t ui16;
typedef int32_t i32;
typedef uint32_t ui32;
typedef int64_t i64;
typedef uint64_t ui64;
typedef long double ld;
typedef pair<int, int> Pii;

template <typename T>
using V = vector<T>;

typedef V<int> Vi;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename K, typename V>
using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

#ifndef M_PI
#	define M_PI 3.14159265358979323846
#endif

int gcdex(int a, int b, int &x, int &y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;		
	}

	int x1, y1;
	int g = gcdex(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;

	return g;
}

#define MOD 1000000007
inline int ADD_MOD(int a, int b) { return (a + b) % MOD; }
inline int MUL_MOD(int a, int b) { return (i64(a) * b) % MOD; }
inline int SUB_MOD(int a, int b) { return a >= b ? a - b : a + MOD - b; }
int DIV_MOD(int a, int b) {
	int x, y;
	gcdex(b, MOD, x, y);
	
	int b1 = (x % MOD + MOD) % MOD;
	return MUL_MOD(a, b1);
}

const ld EPS = 1. / 1e9;
inline bool EPS_EQUAL(ld a, ld b) { return abs(a - b) <= EPS; }
inline bool EPS_LESS(ld a, ld b) { return b - a > EPS; }
inline bool EPS_GREATER(ld a, ld b) { return a - b > EPS; }

const int INF = 1e9;
const i64 INF64 = 2e18;

i64 my_pow(i64 k, int p) {
	i64 r = 1;
	while (p > 0) {
		r *= k;
		--p;
	}
	return r;
}

i64 get_offset(int k, int c, int i) {
	return my_pow(k, c - 1) * i;
}

void solve() {
	int k, c, s;
	cin >> k >> c >> s;

	int n = (k + c - 1) / c;
	if (n > s) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}

	for (int i = 0; i < n; ++i) {
		int start = i * c;

		i64 d = 0;
		for (int j = c; j > 0; --j) {
			d += get_offset(k, j, start);
			if (start < k - 1) start++;
		}

		cout << d + 1 << " ";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(15);

	int t;
	cin >> t;

	for (int ti = 0; ti < t; ++ti) {
		cout << "Case #" << (ti + 1) << ": ";
		solve();
	}

	return 0;
}