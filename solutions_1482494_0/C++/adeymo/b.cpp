#include <vector>
#include <queue>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

/* tipos */
typedef pair<int,int> pint;
typedef long long tint;
typedef unsigned int mint;
typedef unsigned long long mtint;

typedef vector<int> vint;
typedef vector<vint> vvint;

typedef long double tdbl;

/* "funciones" */
#define forn(i,n) for(int ___n=n, i=0;i<___n;++i)
#define dforn(i,n) for(int i=(n)-1;i>=0;--i)
#define forsn(i,s,n) for(int ___n=n, i=s;i<___n;++i)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define forall(it,X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define dforall(it,X) for(typeof((X).rbegin()) it = (X).rbegin(); it != (X).rend(); ++it)
#define all(X) (X).begin(), (X).end()
#define esta(e, c) (c.find(e) != c.end())
#define DBG(a) cerr << #a << " = " << a << endl;

template<class T> string itos(const T&x) { ostringstream o; o<<x; return o.str(); }
// Sorters <int>
template<typename T> struct sorter_gen {
  T& v;
  sorter_gen(T& vv) : v(vv) {}
  bool operator()(int a, int b) { return v[a] < v[b]; }
};
#define sortind(I, X) sort(all(I), (sorter_gen<typeof(X)>)(X))


vint l1, l2;
bool sort21(int a, int b) {
	if (l2[a] != l2[b]) return l2[a] < l2[b];
	if (l1[a] != l1[b]) return l1[a] < l1[b];
	return a < b;
}
bool sort1(int a, int b) {
	if (l1[a] != l1[b]) return l1[a] < l1[b];
	return a < b;
}

int main() {
	int tt;
	cin >> tt;
	forn(_t, tt) {
		int n;
		cin >> n;
		l1.resize(n);
		l2.resize(n);
		forn(i, n) { cin >> l1[i] >> l2[i]; }
		int res = 0;
		vector<pint> lst; lst.resize(2*n);
		forn(i,n) {
			lst[2*i+0] = pint(l1[i], i);
			lst[2*i+1] = pint(l2[i], i);
		}
		sort(all(lst));
		forn(i, 2*n) {
			if (lst[i].first > i) { res = -1; break; }
		}
		if (res == -1) {
			printf("Case #%d: Too Bad\n", _t+1);
			continue;
		}

		vint p(n); forn(i,n) p[i] = i;
		sort(all(p), sort21);
		vint q(n); forn(i,n) q[i] = i;
		sort(all(q), sort1);

		int usd = 0, vl = 0;
		forn(i, n) {
			// cerr << i << ": " << l2[p[i]] << endl;
			while (l2[p[i]] > vl) {
				dforn(j,n) if (l1[p[j]] != -1 && l1[p[j]] <= vl) { l1[p[j]] = -1; break; }
				vl++; usd++;
			}
			vl++;
			if (l1[p[i]] != -1) vl++;
			l1[p[i]] = -1;
		}
		res = n + usd;

		// forn(i, n) cerr << l2[p[i]] - 2*i <<  " "; cerr<< endl;
		printf("Case #%d: %d\n", _t+1, res);
	}
	return 0;
}

