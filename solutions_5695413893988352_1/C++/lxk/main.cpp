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

struct Res {
	string a;
	string b;
	i64 mn;

	Res(string a, string b, i64 mn) : a(a), b(b), mn(mn) {
	}
};

void maximize(string &a) {
	for (auto &i : a) {
		if (i == '?') {
			i = '9';
		}
	}
}

void minimize(string &a) {
	for (auto &i : a) {
		if (i == '?') {
			i = '0';
		}
	}
}

i64 get_diff(string &a, string &b) {
	i64 d = 0;

	int n = a.size();
	for (int i = 0; i < n; ++i) {
		d = d * 10 + (a[i] - b[i]);
	}

	return abs(d);
}

Res solve_req(string a, string b);

Res solve(string a, string b) {
	if (!a.size()) return {"", "", 0};

	char ac = a[0];
	char bc = b[0];

	if (ac == '?' && bc == '?') {
		// a == b
		Res rs1 = solve(a.substr(1), b.substr(1));
		i64 mn1 = rs1.mn;

		// a < b
		string a2 = a;
		a2[0] = '0';
		maximize(a2);

		string b2 = b;
		b2[0] = '1';
		minimize(b2);

		i64 mn2 = get_diff(a2, b2);

		// a > b
		string a3 = a;
		a3[0] = '1';
		minimize(a3);

		string b3 = b;
		b3[0] = '0';
		maximize(b3);

		i64 mn3 = get_diff(a3, b3);

		if (mn1 <= min(mn2, mn3)) {
			rs1.a = '0' + rs1.a;
			rs1.b = '0' + rs1.b;
			return rs1;
		} else if (mn2 <= mn3) {
			return {a2, b2, mn2};
		}

		return {a3, b3, mn3};
	}

	if (ac != '?' && bc != '?') {
		if (ac > bc) {
			minimize(a);
			maximize(b);
			return {a, b, get_diff(a, b)};
		}
		if (bc > ac) {
			maximize(a);
			minimize(b);
			return {a, b, get_diff(a, b)};
		}
		
		Res rs = solve(a.substr(1), b.substr(1));
		return {ac + rs.a, bc + rs.b, rs.mn};
	}

	if (ac == '?') {
		return solve_req(a, b);
	}

	Res res = solve_req(b, a);
	swap(res.a, res.b);
	return res;
}

Res solve_req(string a, string b) {
	char bc = b[0];

	// a < b
	i64 mn1 = INF64;
	if (bc != '0') {
		string a1 = a;
		a1[0] = bc - 1;
		maximize(a1);

		string b1 = b;
		minimize(b1);

		mn1 = get_diff(a1, b1);
	}

	// a > b
	i64 mn2 = INF64;
	if (bc != '9') {
		string a1 = a;
		a1[0] = bc + 1;
		minimize(a1);

		string b1 = b;
		maximize(b1);

		mn2 = get_diff(a1, b1);
	}

	// a == b
	Res res3 = solve(a.substr(1), b.substr(1));
	i64 mn3 = res3.mn;

	if (mn1 <= min(mn2, mn3)) {
		a[0] = bc - 1;
		maximize(a);
		minimize(b);
		return {a, b, mn1};
	} else if (mn3 <= mn2) {
		return {bc + res3.a, bc + res3.b, mn3};
	} else {
		a[0] = bc + 1;
		minimize(a);
		maximize(b);
		return {a, b, mn2};
	}
}

void solve() {
	string a, b;
	cin >> a >> b;

	Res res = solve(a, b);
	cout << res.a << " " << res.b << endl; 
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