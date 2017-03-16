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

const int N = 10 * 1000 + 3;

int n, k;
char a[N];

inline bool read()
{
	if (!(cin >> n >> k)) return false;
	assert(gets(a));
	assert(gets(a));
	return true;
}

struct quat {
	int v, sg;
	quat() { }
	quat(int v, int sg = 1): v(v), sg(sg) { }
};

ostream& operator<< (ostream& out, const quat& a) {
	if (a.sg == -1) out << "-";
	switch (a.v) {
		case 0: out << 1; break;
		case 1: out << 'i'; break;
		case 2: out << 'j'; break;
		default: out << 'k';
	}
	return out;
}

bool operator< (const quat& a, const quat& b) {
	if (a.v != b.v) return a.v < b.v;
	return a.sg < b.sg;
}

bool operator== (const quat& a, const quat& b) { return a.v == b.v && a.sg == b.sg; }
bool operator!= (const quat& a, const quat& b) { return a.v != b.v || a.sg != b.sg; }

quat operator* (const quat& a, const quat& b) {
	quat ans(-1, a.sg * b.sg);
	if (a.v == 0) ans.v = b.v;
	else if (b.v == 0) ans.v = a.v;
	else if (a.v == b.v) ans.v = 0, ans.sg *= -1;
	else if (a.v == 1 && b.v == 2) ans.v = 3;
	else if (a.v == 1 && b.v == 3) ans.v = 2, ans.sg *= -1;
	else if (a.v == 2 && b.v == 1) ans.v = 3, ans.sg *= -1;
	else if (a.v == 2 && b.v == 3) ans.v = 1;
	else if (a.v == 3 && b.v == 1) ans.v = 2;
	else if (a.v == 3 && b.v == 2) ans.v = 1, ans.sg *= -1;
	else throw;
	return ans;
}

quat get(char c) { return quat(c == '1' ? 0 : c == 'i' ? 1 : c == 'j' ? 2 : 3); }

quat p[N], s[N];
quat pw[5];

inline string solve()
{
	p[0] = quat(0);
	forn(i, n) p[i + 1] = p[i] * get(a[i]);
	s[n] = quat(0);
	ford(i, n) s[i] = get(a[i]) * s[i + 1];

	map<quat, int> fp, lp;
	ford(i, n + 1) fp[p[i]] = i;
	forn(i, n + 1) lp[s[i]] = i;

	vector<int> p1, p2;
	for (map<quat, int>::iterator it = fp.begin(); it != fp.end(); it++) p1.pb(it->sc);
	for (map<quat, int>::iterator it = lp.begin(); it != lp.end(); it++) p2.pb(it->sc);

	//forn(i, n + 1) cerr << p[i] << ' '; cerr << endl;

	pw[0] = quat(0); forl(i, 4) pw[i] = pw[i - 1] * p[n];
	//forn(i, 5) cerr << pw[i] << ' '; cerr << endl;
	assert(pw[4] == quat(0));

	forn(rm1, 4)
		forn(rm2, 4)
			forn(ii, sz(p1))
				forn(jj, sz(p2)) {
					int i = p1[ii], j = p2[jj];
					if (rm1 + (i > 0 || j < n) + (i > j) + rm2 > k) continue;
					if (pw[rm1] * p[i] != quat(1)) continue;
					//if (rm1 == 0 && rm2 == 0 && i == 2 && j == 2) cerr << s[j] << ' ' << pw[rm2] << endl;
					if (s[j] * pw[rm2] != quat(3)) continue;
					if (pw[k % 4] != quat(0, -1)) continue;
					return "YES";
				}
	return "NO";
}

int main()
{
#ifdef SU2_PROJ
    assert(freopen("input.txt", "rt", stdin));
    assert(freopen("output.txt", "wt", stdout));
#endif
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;

	int tt;
	cin >> tt;
	forn(t, tt) {
		cerr << "Test #" << t + 1 << " is processing" << endl;
		printf("Case #%d:", t + 1);
		assert(read());
		printf(" %s\n", solve().c_str());
	}
	
    return 0;
}
