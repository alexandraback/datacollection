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

void print_bin(ui32 x) {
	bool start = false;
	for (int i = 31; i >= 0; --i) {
		int byte = (x >> i) & 1;
		if (byte || start) {
			cout << byte;
			start = true;
		}
	}
}

int find_div(ui64 x) {
	if (x % 2 == 0) return 2;

	for (int i = 3; i * i <= x && i < 40000; i += 2) {
		if (x % i == 0) return i;
	}
	return 0;
}

ui64 to_base(ui32 x, int base) {
	ui64 r = 0;
	ui64 p = 1;

	for (int i = 0; i < 32; ++i) {
		r += p * (x & 1);
		p *= base;
		x >>= 1;
	}

	return r;
}

bool check(ui32 x) {
	int divs[10] = {0};
	for (int i = 2; i <= 10; ++i) {
		ui64 y = to_base(x, i);
		
		int d = find_div(y);
		if (!d) {
			return false;
		}
		divs[i - 2] = d;
	}

	print_bin(x);
	cout << " ";
	for (int i = 0; i < 9; ++i) {
		cout << divs[i] << " ";
	}
	cout << endl;

	return true;
}

void solve() {
	cout << endl;

	int n, m;
	cin >> n >> m;

	for (ui32 i = (1 << (n - 1)) + 1; m > 0; i += 2) {
		if (check(i)) {
			--m;
		}
	}
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