#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<pair<ll, ll>, pair<ll, ll> > lll;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const ll inf = 3e18;

int n;
int m;

ll base[19];
lll res[19];
string s, t;

void update (lll &a, ll c) {
	if (c >= 0) {
		a.fi.fi = min (a.fi.fi, c);
		a.fi.se = max (a.fi.se, c);
	}
	if (c <= 0) {
		a.se.fi = max (a.se.fi, c);
		a.se.se = min (a.se.se, c);
	}
}

lll merge (lll a, lll b, ll c) {
	if (b.fi.fi < inf) update (a, b.fi.fi + c);
	if (b.fi.se >= 0) update (a, b.fi.se + c);
	if (b.se.fi > -inf) update (a, b.se.fi + c);
	if (b.se.se <= 0) update (a, b.se.se + c);
	re a;
}

int out (int i, ll d) {
	if (i == n) re 0;
//	cout << i << " " << d <<endl;
	for (int a = 0; a < 10; a++)
		for (int b = 0; b < 10; b++) {
			if (s[i] != '?' && s[i] - '0' != a) continue;
			if (t[i] != '?' && t[i] - '0' != b) continue;
			lll cur = merge (mp (mp (inf, -inf), mp (-inf, inf)), res[i + 1], (a - b) * base[n - i - 1]);
			if (cur.fi.fi == d || cur.fi.se == d || cur.se.fi == d || cur.se.se == d) {
				s[i] = '0' + a;
				t[i] = '0' + b;
				out (i + 1, d - (a - b) * base[n - i - 1]);
				re 0;
			}
		}
	re 0;
}

int main () {
	base[0] = 1;
	for (int i = 1; i <= 18; i++) base[i] = base[i - 1] * 10;	
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		cin >> s >> t;
		n = sz (s);
		res[n] = mp (mp (0, 0), mp (0, 0));
		for (int i = n - 1; i >= 0; i--) {
			res[i] = mp (mp (inf, -inf), mp (-inf, inf));
			for (int a = 0; a < 10; a++)
				for (int b = 0; b < 10; b++) {
					if (s[i] != '?' && s[i] - '0' != a) continue;
					if (t[i] != '?' && t[i] - '0' != b) continue;
					res[i] = merge (res[i], res[i + 1], (a - b) * base[n - i - 1]);
				}
//			printf ("%d = %lld %lld | %lld %lld\n", i, res[i].fi.fi, res[i].fi.se, res[i].se.fi, res[i].se.se);
		}
		if (res[0].fi.fi < -res[0].se.fi) out (0, res[0].fi.fi); else 
		if (res[0].fi.fi > -res[0].se.fi) out (0, res[0].se.fi); else {
			string os = s, ot = t;
			out (0, res[0].fi.fi);
			string s1 = s, t1 = t;
			s = os; t = ot;
			out (0, res[0].se.fi);
			string s2 = s, t2 = t;
			if (s2 < s1 || (s1 == s2 && t2 < t1)) {				
				s = s2;
				t = t2;
			} else {
				s = s1;
				t = t1;
			}
		}
		cout << "Case #" << it << ": " << s << " " << t;
//		cout << min (abs (res[0].fi.fi), abs (res[0].se.fi));
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}