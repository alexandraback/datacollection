#include <bits/stdc++.h>
using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI  3.1415926535897932385
#define EPS 1e-7
#define MOD 1000000007
#define INF 1500111222
#define MAX 100111

int n, m, r;
string a, b;
char s[MAX];
double sum, maxi, cnt;

void process() {
	set<char> s;
	rep(i, a.length()) s.insert(a[i]);
	a = "";
	foreach(it, s) a += *it;
}

void recurse(int k, int match) {
	bool ok = true;
	//s[k] = '\0'; puts(s);
	if (k >= m) {
		rep(i, m) if (s[k - i - 1] != b[m - i - 1]) {
			ok = false;
			break;
		}
	} else ok = false;
	if (ok) match++;

	if (k >= r) {
		maxi = max(maxi, (double)match);
		sum += match;
		cnt++;
		return;
	}

	rep(i, a.size()) {
		s[k] = a[i];
		recurse(k + 1, match);
	}
}

double solve() {
	//process();
	sum = 0;
	cnt = 0;
	maxi = 0;
	recurse(0, 0);
	//printf("%lf %lf %lf\n", sum, cnt, maxi);
	return maxi - (sum / cnt);
}

int main() {
	#ifndef ONLINE_JUDGE
	    freopen("bsmall.inp", "r", stdin);
	    freopen("bsmall.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d %d", &n, &m, &r);
		cin >> a >> b;
		printf("Case #%d: %.10lf\n", ++caseNo, solve());
	}
	return 0;
}

// Viet P. Lam - lamphanviet@gmail.com - http://blog.lamphanviet.com