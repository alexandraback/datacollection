#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define size(x) (int) x.size()

const int maxn = 1000005;
const int logn = 30;
const int inf = (int) 1e9 + 5;
const long long mod = (int) 1e9 + 7;
const long long base = 2204234849;
const long long l_inf = (long long) 4e18;
const long double pi = acos(-1.0);
const long double eps = 1e-12;

int T;

string a, b;
int n;
long long bestA, bestB;
long long ten[19];

inline void process(long long A, long long B, int i, int eq) {
	if (i == n) {
		if (abs(A - B) < abs(bestA - bestB) || (abs(A - B) == abs(bestA - bestB) && A < bestA) || (abs(A - B) == abs(bestA - bestB) && A == bestA && B < bestB)) {
			bestA = A;
			bestB = B;
		}
		return;
	}
	if (a[i] == '?' && b[i] == '?') {
		if (eq == 0) {
			process(A, B, i + 1, 0);
			if (i + 1 < n && (a[i + 1] != '?' || b[i + 1] != '?')) {
				process(A, B + ten[n - i - 1], i + 1, -1);
				process(A + ten[n - i - 1], B, i + 1, +1);
			}
		} else {
			if (eq < 0) {
				process(A + 9 * ten[n - i - 1], B, i + 1, eq);
			} else {
				process(A, B + 9 * ten[n - i - 1], i + 1, eq);
			}
		}
		return;
	}
	if (a[i] == '?') {
		if (eq == 0) {
			process(A + (b[i] - '0') * ten[n - i - 1], B + (b[i] - '0') * ten[n - i - 1], i + 1, 0);
			if (b[i] != '9')
				process(A + (b[i] - '0' + 1) * ten[n - i - 1], B + (b[i] - '0') * ten[n - i - 1], i + 1, +1);
			if (b[i] != '0')
				process(A + (b[i] - '0' - 1) * ten[n - i - 1], B + (b[i] - '0') * ten[n - i - 1], i + 1, -1);
		} else {
			if (eq < 0) {
				process(A + 9 * ten[n - i - 1], B + (b[i] - '0') * ten[n - i - 1], i + 1, eq);
			} else {
				process(A, B + (b[i] - '0') * ten[n - i - 1], i + 1, eq);
			}
		}
		return;
	}
	if (b[i] == '?') {
		if (eq == 0) {
			process(A + (a[i] - '0') * ten[n - i - 1], B + (a[i] - '0') * ten[n - i - 1], i + 1, 0);
			if (a[i] != '9')
				process(A + (a[i] - '0') * ten[n - i - 1], B + (a[i] - '0' + 1) * ten[n - i - 1], i + 1, -1);
			if (a[i] != '0')
				process(A + (a[i] - '0') * ten[n - i - 1], B + (a[i] - '0' - 1) * ten[n - i - 1], i + 1, +1);
		} else {
			if (eq < 0) {
				process(A + (a[i] - '0') * ten[n - i - 1], B, i + 1, eq);
			} else {
				process(A + (a[i] - '0') * ten[n - i - 1], B + 9 * ten[n - i - 1], i + 1, eq);
			}
		}
		return;
	}
	if (eq == 0) {
		if (a[i] < b[i])
			eq = -1;
		if (a[i] > b[i])
			eq = +1;
	}
	process(A + (a[i] - '0') * ten[n - i - 1], B + (b[i] - '0') * ten[n - i - 1], i + 1, eq);
}

bool good(int A, int B) {
	bool f = true;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] != '?')
			f &= a[i] - '0' == A % 10;
		if (b[i] != '?')
			f &= b[i] - '0' == B % 10;
		A /= 10;
		B /= 10;
	}
	return f;
}

void trivial() {
	for (int A = 0; A < ten[n]; A++) {
		for (int B = 0; B < ten[n]; B++) {
			if (!good(A, B))
				continue;
			if (abs(A - B) < abs(bestA - bestB) || (abs(A - B) == abs(bestA - bestB) && A < bestA)) {
				bestA = A;
				bestB = B;
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	cout << fixed;
	srand(566);

#ifdef LOCAL
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	ten[0] = 1;
	for (int i = 1; i < 19; i++)
		ten[i] = ten[i - 1] * 10ll;

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> a >> b;

		n = size(a);
		bestA = l_inf;
		bestB = -l_inf;
		cout << "Case #" << t << ": ";
		process(0, 0, 0, 0);
		for (int i = n - 1; i >= 0; i--) {
			a[i] = '0' + bestA % 10;
			b[i] = '0' + bestB % 10;
			bestA /= 10;
			bestB /= 10;
		}
		cout << a << ' ' << b << '\n';
	}

	return 0;
}
