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

string s;

bool read() {
	return !!(cin >> s);
}

pair<char, pair<string, int>> dic[] = {
	{ 'Z', { "ZERO", 0 } },
	{ 'U', { "FOUR", 4 } },
	{ 'X', { "SIX", 6 } },
	{ 'F', { "FIVE", 5 } },
	{ 'W', { "TWO", 2 } },
	{ 'O', { "ONE", 1 } },
	{ 'G', { "EIGHT", 8 } },
	{ 'I', { "NINE", 9 } },
	{ 'V', { "SEVEN", 7 } },
	{ 'R', { "THREE", 3 } }
};

int cnt[130];

void solve(int test) {
	printf("Case #%d: ", test + 1);

	memset(cnt, 0, sizeof(cnt));
	forn(i, sz(s)) cnt[(int) s[i]]++;

	//cerr << "s=" << s << endl;

	string ans;
	forn(i, 10) {
		/*cerr << "i=" << i << endl;
		cerr << "dic[i].x=" << dic[i].x << endl;
		cerr << "cnt=" << cnt[(int) dic[i].x] << endl;*/
		while (cnt[(int) dic[i].x] > 0) {
			//cerr << dic[i].y.x << endl;
			forn(j, sz(dic[i].y.x)) {
				assert(--cnt[(int) dic[i].y.x[j]] >= 0);
			}
			//cerr << "IN" << endl;
			ans.pb(char('0' + dic[i].y.y));
		}
	}
	//cerr << "ans=" << ans << endl;
	assert(*max_element(cnt, cnt + 130) == 0);
	sort(all(ans));
	puts(ans.c_str());
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
		solve(tt);
		cerr << "TEST #" << tt + 1 << endl;
		cerr << "Time: " << gett() - stime << endl;
		//break;
	}
	
    return 0;
}
