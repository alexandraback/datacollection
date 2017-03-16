#undef NDEBUG
#ifdef SU2_PROJ
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

string n;

inline bool read() {
	return cin >> n;
}

li toInt(string s) {
	li ans = 0;
	forn(i, sz(s)) ans = ans * 10 + int(s[i] - '0');
	return ans;
}

string toString(li x) {
	stringstream ss;
	ss << x;
	string s;
	ss >> s;
	return s;
}

li naive(string n) {
	map<string, li> d;
	queue<string> q;

	d["1"] = 1;
	q.push("1");

	while (!q.empty()) {
		string c = q.front();
		q.pop();

		{
			string nc(c);
			reverse(all(nc));
			if (!d.count(nc) || d[nc] > d[c] + 1) {
				d[nc] = d[c] + 1;
				q.push(nc);
			}
		}

		{
			string nc = toString(toInt(c) + 1);
			if (sz(nc) <= sz(n) && (!d.count(nc) || d[nc] > d[c] + 1)) {
				d[nc] = d[c] + 1;
				q.push(nc);
			}
		}
	}

	return d[n];
}

li _pow(li a, li b) {
	li ans = 1;
	while (b) {
		if (b & 1) ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}

inline void solve() {
	li ans = 1;

	bool g = false;
	if (sz(n) > 1 && n.substr(1) == string(sz(n) - 1, '0')) {
		g = true;
		ans++;
		n = toString(toInt(n) - 1);
	}

	forl(i, sz(n) - 1) {
		if (i > 1) ans++;
		ans += _pow(10, i / 2) - 1;
		ans += _pow(10, (i + 1) / 2) - 1;
	}

	li madd = toInt(n) - _pow(10, sz(n) - 1);
	forl(i, sz(n)) {
		string s = n.substr(0, i);
		reverse(all(s));
		li cur = 0;
		cur += toInt(s);
		cur++;
		cur += toInt(n.substr(i)) - 1;
		//cerr << i << ' ' << cur << endl;
		madd = min(madd, cur);
	}
	ans += madd;

	if (sz(n) < 6) {
		if (g) n = toString(toInt(n) + 1);
		li nans = naive(n);
		cerr << n << ' ' << ans << ' ' << nans << endl;
		assert(ans == nans);
	}
	cout << ' ' << ans << endl;
}

int d[1000 * 1000 + 3];

void prepare() {
	memset(d, 63, sizeof(d));
	queue<int> q;

	d[1] = 1;
	q.push(1);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		if (v + 1 <= 1000 * 1000 && d[v + 1] > d[v] + 1) {
			d[v + 1] = d[v] + 1;
			q.push(v + 1);
		}

		int nv = 0, x = v;
		int sz = 0;
		static int p[20];
		while (x) p[sz++] = x % 10, x /= 10;
		forn(i, sz) nv = nv * 10 + p[i];
		if (nv <= 1000 * 1000 && d[nv] > d[v] + 1) {
			d[nv] = d[v] + 1;
			q.push(nv);
		}
	}
}

void solve2() {
	cout << ' ' << d[toInt(n)] << endl;
}

int main()
{
#ifdef SU2_PROJ
	assert(freopen("input.txt", "rt", stdin));
	assert(freopen("output.txt", "wt", stdout));
#endif
	
	cout << setprecision(10) << fixed;
	cerr << setprecision(5) << fixed;
	
	prepare();
	int tc;
	cin >> tc;
	forn(tt, tc) {
		assert(read());
		printf("Case #%d:", tt + 1);
		solve2();
	}
	
	return 0;
}
