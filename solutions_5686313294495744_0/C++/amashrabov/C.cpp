#include <bits/stdc++.h>


#define y1 AAA_BBB
#define y0 AAA_AAA

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef vector<int> vi;
typedef vector<i64> vi64;
typedef pair<int, int> pii;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef vector<vi64> vvi64;

template <class T> T inline sqr(T x) {
    return x * x;
}

const ld pi = 3.1415926535897932384626433832795;
const ld eps = 1e-8;

mt19937 generator;

struct solution {

	vector < vector<int> > g;
	vector<int> mt;
	vector<char> used;
	 
	bool try_kuhn (int v) {
		if (used[v])  return false;
		used[v] = true;
		for (size_t i=0; i<g[v].size(); ++i) {
			int to = g[v][i];
			if (mt[to] == -1 || try_kuhn (mt[to])) {
				mt[to] = v;
				return true;
			}
		}
		return false;
	}	

    int test;
 	vvi e;
	int n, k;
	int ans;
    void read() {
		int n; cin >> n;
		string s[2][n];
		forn (i, n) forn (j, 2) cin >> s[j][i];
		e.assign(2, vi(n));
		forn (j, 2) {
			vector<string> ar(n);forn(i,n)ar[i] = s[j][i];
			sort(all(ar)); ar.resize(unique(all(ar)) - ar.begin());
			if (!j) {this->n = ar.size();}
			else k = ar.size();
			forn (i, n) e[j][i] = lower_bound(all(ar), s[j][i]) - ar.begin();
		}
    }
    void print() {
		cout << "Case #" << test << ": "<< ans << "\n";
    }

    void solve() {
		g.assign(n, vi());
		forn (i, e[0].size())
			g[e[0][i]].pb(e[1][i]);
		mt.assign (k, -1);
		vector<char> used1 (n);
		int res = 0;
		for (int i=0; i<n; ++i)
			for (size_t j=0; j<g[i].size(); ++j)
				if (mt[g[i][j]] == -1) {
					mt[g[i][j]] = i;
					used1[i] = true;
					res++;
					break;
				}
		
		for (int i=0; i<n; ++i) {
			if (used1[i])  continue;
			used.assign (n, false);
			res += try_kuhn (i);
		}
		ans = n + k - res;
		ans = e[0].size() - ans;
    }
} * solutions;


void solve(int test) {
    solutions[test].solve();
}




int main() {
#ifdef HOME
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	
	int tests; cin >> tests;

    solutions = new solution[tests];

    for (int i = 0; i < tests; ++i) {
        solutions[i].test = i + 1;
        solutions[i].read();
    }

    thread threads[tests];

    for (int i = 0; i < tests; ++i) {
        threads[i] = thread(solve, i);
    }

    for (int i = 0; i < tests; ++i) {
        threads[i].join();
        solutions[i].print();
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
} 
