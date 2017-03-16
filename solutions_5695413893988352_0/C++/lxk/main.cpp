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

string print_num(int num, int len) {
	string s;
	while (num > 0) {
		s = char((num % 10) + '0') + s;
		num /= 10;
		len--;
	}

	while (len > 0) {
		s = '0' + s;
		--len;
	}

	return s;
}

bool check(string &s, int num) {
	int n = s.size();
	string snum = print_num(num, n);
	
	if (snum.size() > n) return false;
	for (int i = 0; i < n; ++i) {
		if (s[i] != '?' && s[i] != snum[i]) return false;
	}
	return true;
}

void solve() {
	string a, b;
	cin >> a >> b;

	int n = a.size();
	int mx = pow(10, n);

	int mnD = INF;
	int mnI = 0, mnJ = 0;

	for (int i = 0; i < mx; ++i) {
		if (!check(a, i)) continue;

		for (int j = 0; j < mx; ++j) {
			if (!check(b, j)) continue;

			int d = abs(i - j);
			if (d < mnD) {
				mnD = d;
				mnI = i;
				mnJ = j;
			} else if (d == mnD && (i < mnI || (i == mnI && j < mnJ))) {
				mnD = d;
				mnI = i;
				mnJ = j;
			}
		}
	}

	cout << print_num(mnI, n) << " " << print_num(mnJ, n) << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(15);

	int t;
	cin >> t;

	for (int ti = 0; ti < t; ++ti) {
		cout << "Case #" << ti + 1 << ": ";
		solve();
	}

	return 0;
}