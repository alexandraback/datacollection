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

class BigNum {
public:
	Vi digs;
	int base;

	int mod(int x) {
		int carry = 0;
		for (int i = digs.size() - 1; i >= 0; --i) {
			int d = digs[i] + carry * base;
			carry = d % x;
		}

		return carry;
	}
};

int find_div(BigNum &x) {
	if (x.mod(2) == 0) return 2;

	// check 3, 5, 7, 11
	for (int i = 3; i < 12; i += 2) {
		if (x.mod(i) == 0) return i;
	}
	return 0;
}

void print_bin(BigNum &x) {
	for (int i = x.digs.size() - 1; i >= 0; --i) {
		cout << x.digs[i];
	}
}

bool check(BigNum &x) {
	int divs[10] = {0};

	for (int i = 2; i <= 10; ++i) {
		x.base = i;
		
		int d = find_div(x);
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

void to_big(BigNum &b, ui32 x) {
	auto &digs = b.digs;
	digs.clear();

	while (x > 0) {
		digs.push_back(x & 1);
		x >>= 1;
	}
}

void solve() {
	cout << endl;

	int n, m;
	cin >> n >> m;

	BigNum b;
	for (ui32 i = (1 << (n - 1)) + 1; m > 0; i += 2) {
		to_big(b, i);
		if (check(b)) {
			m--;
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