#include <bits/stdc++.h>

using namespace std;

#define fillchar(a, s) memset((a), (s), sizeof(a))
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define all(v) (v).begin(), (v).end()
#define rep(it, v) for (auto it = (v).begin(); it != (v).end(); it++)
#define rfile(f) freopen(f, "r", stdin)
#define wfile(f) freopen(f, "w", stdout)
#define rwfile(prob) rfile(prob".in"); wfile(prob".out")
#define pb push_back
#define mpair make_pair
#define fi first
#define se second
#define dri(x) scanf("%d", &x)
#define drii(x, y) scanf("%d %d", &x, &y)
#define driii(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define driiii(x, y, z, w) scanf("%d %d %d %d", &x, &y, &z, &w)
#define drl(x) scanf("%lld", &x)
#define drll(x, y) scanf("%lld %lld", &x, &y)
#define drlll(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define drllll(x, y, z, w) scanf("%lld %lld %lld %lld", &x, &y, &z, &w)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 21;

struct answer {
	ll a, b;
	answer (ll _a, ll _b) : a(_a), b(_b) {}
	ll diff() const {
		return llabs(a - b);
	}
};

bool operator < (answer a1, answer a2) {
	ll d1 = a1.diff(), d2 = a2.diff();
	return d1 < d2 || (d1 == d2 && mpair(a1.a, a1.b) < mpair(a2.a, a2.b));
}

void print (ll x, int n) {
	string s = to_string(x);
	cout << string(n - s.size(), '0') << s;
}

ll toll (string s) {
	stringstream ss(s);
	ll x;
	ss >> x;
	return x;
}

int N;
char S[MAXN], T[MAXN];

int pmatch (char c1, char c2) {
	if (c1 == '?') {
		if (c2 == '?') {
			return 0;
		} else {
			return c2 - '0';
		}
	} else {
		if (c2 == '?' || c2 == c1) {
			return c1 - '0';
		} else {
			return -1;
		}
	}
}

answer go() {
	answer ans(0, 2e18);
	for (int i = 0; i < N; i++) {
		if (S[i] != '?' && T[i] != '?' && S[i] < T[i]) {
			if (S[i] < T[i]) {
				break;
			}
			if (S[i] == T[i]) {
				continue;
			}
		}

		//match [0..i-1], but not match [i]

		string s = S, t = T;
		bool matchable = true;
		for (int j = 0; j < i; j++) {
			int p = pmatch(S[j], T[j]);
			if (p == -1) {
				matchable = false;
				break;
			}
			s[j] = t[j] = p + '0';
		}
		if (!matchable) {
			break;
		}

		//S[i] > T[i]
		if (S[i] == '?') {
			if (T[i] == '?') {
				s[i] = '1';
				t[i] = '0';
			} else {
				if (t[i] == '9') {
					continue;	//can't actually do it
				}
				s[i] = t[i] + 1;
			}
		} else {
			if (T[i] == '?') {
				if (s[i] == '0') {
					continue;	//can't do it
				}
				t[i] = s[i] - 1;
			}
		}

		//for j in [i + 1, N): make s[j] small, t[j] big
		for (int j = i + 1; j < N; j++) {
			if (s[j] == '?') {
				s[j] = '0';
			}
			if (t[j] == '?') {
				t[j] = '9';
			}
		}

		ans = min(ans, answer(toll(s), toll(t)));

		if (S[i] != '?' && T[i] != '?' && S[i] > T[i]) {
			break;
		}
	}
	return ans;
}

void solve() {
	cin >> S >> T;
	N = strlen(S);

	if (!count(S, S + N, '?') && !count(T, T + N, '?')) {
		cout << S << ' ' << T << '\n';
		return;
	}

	//can S = T?
	bool caneq = true;
	for (int i = 0; i < N; i++) {
		if (S[i] != '?' && T[i] != '?' && T[i] != S[i]) {
			caneq = false;
			break;
		}
	}

	if (caneq) {
		for (int i = 0; i < N; i++) {
			if (S[i] == '?') {
				if (T[i] == '?') {
					S[i] = T[i] = '0';
				} else {
					S[i] = T[i];
				}
			} else {
				if (T[i] == '?') {
					T[i] = S[i];
				}
			}
		}
		assert(!strcmp(S, T));
		cout << S << ' ' << T << '\n';
		return;
	}

	answer ans = go();
	swap_ranges(S, S + N, T);
	answer ans2 = go();
	swap(ans2.a, ans2.b);
	ans = min(ans, ans2);
	print(ans.a, N);
	cout << ' ';
	print(ans.b, N);
	cout << endl;
}

int main() {
	if (fopen("input.txt", "r")) {
		rfile("input.txt");
		wfile("output.txt");
	}
	ios::sync_with_stdio(false);
	int ncas;
	cin >> ncas;
	for (int cas = 1; cas <= ncas; cas++) {
		cout << "Case #" << cas << ": ";
		solve();
	}
}