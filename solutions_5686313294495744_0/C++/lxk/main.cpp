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

void solve() {
	int n;
	cin >> n;

	V<pair<string, string>> a(n);
	map<string, int> w1;
	map<string, int> w2;

	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
		
		w1[a[i].first]++;
		w2[a[i].second]++;
	}

	int res = 0;
	for (int i = 1; i < (1 << n); ++i) {
		map<string, int> cw1 = w1;
		map<string, int> cw2 = w2;

		bool ok = true;
		int count = 0;

		int s = i;
		int j = 0;
		while (s > 0) {
			if (s & 1) {
				count++;
				cw1[a[j].first]--;
				cw2[a[j].second]--;

				if (cw1[a[j].first] == 0 || cw2[a[j].second] == 0) {
					ok = false;
				}
			}

			j++;
			s >>= 1;
		}

		if (ok) {
			res = max(res, count);
		}
	}

	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(15);

	int t;
	cin >> t;

	for (int ti = 0; ti < t; ++ti) {
		cerr << ti << endl;

		cout << "Case #" << ti + 1 << ": ";
		solve();
	}

	return 0;
}