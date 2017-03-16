#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define nfor(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pti;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

template<typename A, typename B> inline ostream& operator<< (ostream& out, const pair<A, B>& p) { return out << "(" << p.x << ", " << p.y << ")"; }
template<typename T> inline ostream& operator<< (ostream& out, const vector<T>& a) { out << "["; forn(i, sz(a)) { if (i) out << ','; out << ' ' << a[i]; } return out << " ]"; } 
template<typename T> inline ostream& operator<< (ostream& out, const set<T>& a) { return out << vector<T>(all(a)); }
template<typename X, typename Y> inline ostream& operator<< (ostream& out, const map<X, Y>& a) { return out << vector<pair<X, Y>>(all(a)); }
template<typename T> inline ostream& operator<< (ostream& out, pair<T*, int> a) { return out << vector<T>(a.x, a.x + a.y); }

inline ld gett() { return ld(clock()) / CLOCKS_PER_SEC; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

#ifdef SU1
#define LOG
#endif

string a, b;

bool read() {
	return !!(cin >> a >> b);
}

bool better(pair<string, string> a, pair<string, string> b) {
	if (b.x.empty()) return true;
	auto toInt = [](string s) {
		stringstream ss;
		ss << s;
		li x;
		ss >> x;
		return x;
	};
	li ax = toInt(a.x), ay = toInt(a.y);
	li bx = toInt(b.x), by = toInt(b.y);
	if (abs(ax - ay) != abs(bx - by)) return abs(ax - ay) < abs(bx - by);
	if (ax != bx) return ax < bx;
	return ay < by;
}

//#define CHECK

pair<string, string> solve(int test) {
	printf("Case #%d: ", test + 1);

	pair<string, string> ans("", "");
	forn(len, sz(a) + 1)
	for (char da = '0'; da <= '9'; da++)
	for (char db = '0'; db <= '9'; db++) {
		string a(::a), b(::b);

		bool can = true;
		forn(v, len) {
			if (a[v] == '?' && b[v] == '?') a[v] = b[v] = '0';
			else if (a[v] == '?') a[v] = b[v];
			else if (b[v] == '?') b[v] = a[v];
			else if (a[v] != b[v]) can = false;
		}

		if (len < sz(a)) {
			if (a[len] != '?' && a[len] != da) can = false;
			else a[len] = da;
			if (b[len] != '?' && b[len] != db) can = false;
			else b[len] = db;
			if (da == db) can = false;
		}

		if (!can) continue;

		fore(i, len, sz(a)) {
			if (a[i] == '?') a[i] = a[len] < b[len] ? '9' : '0';
			if (b[i] == '?') b[i] = b[len] < a[len] ? '9' : '0';
		}

		if (better(mp(a, b), ans))
			ans = mp(a, b);
	}

	return ans;
}

bool match(string s, string p) {
	assert(sz(s) == sz(p));
	forn(i, sz(s))
		if (p[i] != '?' && s[i] != p[i])
			return false;
	return true;
}

pair<string, string> naive() {
	auto toString = [](int x) {
		stringstream ss;
		ss << x;
		return ss.str();
	};
	pair<string, string> ans("", "");
	//cerr << "ans=" << ans << endl;
	forn(i, 1000) {
		string x = toString(i);
		while (sz(x) < sz(a)) x = "0" + x;
		if (sz(x) > sz(a) || !match(x, a)) continue;
		forn(j, 1000) {
			//i = 19, j = 23;
			string x = toString(i);
			string y = toString(j);
			while (sz(x) < sz(a)) x = "0" + x;
			while (sz(y) < sz(b)) y = "0" + y;
			if (sz(x) > sz(a) || sz(y) > sz(b)) continue;
			/*cerr << "x=" << x << " y=" << y << endl;
			cerr << "match(x, a)=" << match(x, a) << " match(y, b)=" << match(y, b) << endl;
			exit(0);*/
			if (match(x, a) && match(y, b))
				if (better(mp(x, y), ans))
					ans = mp(x, y);
		}
	}
	assert(isdigit(ans.x[0]));
	return ans;
}

int main() {
#ifdef SU1
    assert(freopen("input.txt", "rt", stdin));
    assert(freopen("output.txt", "wt", stdout));
#endif
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;

	int tc;
	cin >> tc;
	forn(tt, tc) {
		assert(read());
		ld stime = gett();

		string a = ::a, b = ::b;
		auto ans1 = solve(tt);
		cout << ans1.x << ' ' << ans1.y << endl;

#ifdef CHECK
		::a = a, ::b = b;
		auto ans2 = naive();

		if (ans1 != ans2) {
			cerr << "exp: " << ans2 << " rec: " << ans1 << endl;
			cerr << a << ' ' << b << endl;
			exit(0);
		}
#endif

		cerr << "TEST #" << tt + 1 << endl;
		cerr << "Time: " << gett() - stime << endl;
		//break;
	}
	
    return 0;
}
