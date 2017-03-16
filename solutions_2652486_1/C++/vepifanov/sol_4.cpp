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
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int dif = 50;

int n;
int m;
int r, k;
set<ll> all;
ll v[64];
ll x[12], y[12], z[12];
vector<pair<int, vi> > w;
int c[10];
int f[10];

int gen (int i, int j) {
	if (i == n) {
		int cur = 0;
		memset (c, 0, sizeof (c));
		vi e;
		for (int k = 0; k < n; k++) {
			e.pb (y[k]);
			c[y[k]]++;
		}	
		for (int k = 2; k <= m; k++) cur += sqr (12 - 7 * c[k]);
		w.pb (mp (cur, e));
		re 0;
	}
	for (int k = j; k <= m; k++) {
		y[i] = k;
		gen (i + 1, k);
	}
	re 0;
}
                                       
int check (vi e) {
	memset (c, 0, sizeof (c));
	for (int j = 0; j < n; j++) c[e[j]]++;
	memset (f, 0, sizeof (f));
	for (int j = 0; j < k; j++) {
		ll tmp = x[j];
		while (tmp % 2 == 0) {
			f[2]++;
			tmp /= 2;
		}
		while (tmp % 3 == 0) {
			f[3]++;
			tmp /= 3;
		}
		while (tmp % 5 == 0) {
			f[5]++;
			tmp /= 5;
		}
		while (tmp % 7 == 0) {
			f[7]++;
			tmp /= 7;
		}
	}
	int cur = sqr (f[2] - (6 * (c[2] + c[6]) + 12 * c[4] + 24 * c[8])) + sqr (f[3] - 6 * (c[3] + c[6])) + sqr (f[5] - 6 * c[5]) + sqr (f[7] - 6 * c[7]);
	if (cur > dif) re 0;
	for (int i = 0; i < n; i++) y[i] = e[i];
	all.clear ();
	for (int mask = 0; mask < (1 << (n / 2)); mask++) {
		ll cur = 1, tmp = 1;
		for (int i = 0; i < (n / 2); i++)
			if ((mask >> i) & 1) {
				cur *= y[i];
				tmp *= y[i + n / 2];
			}
		v[mask] = cur;
		all.insert (tmp);
	}
	for (int i = 0; i < k; i++) {
		int ok = 0;
		for (int j = 0; j < (1 << (n / 2)); j++)
			if (x[i] % v[j] == 0 && all.find (x[i] / v[j]) != all.end ()) {
				ok = 1;
				break;
			}	
		if (!ok) re 0;
	}
	for (int i = 0; i < n; i++) z[i] = y[i];
	re 1;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {

	        scanf ("%d%d%d%d", &r, &n, &m, &k);
	        gen (0, 2);
	        sort (all (w));
		cout << "Case #" << it << ":" << endl;


		int kkk = 0;
		for (int i = 0; i < r; i++) {
			int MM = 0;
			for (int j = 0; j < k; j++) {
				cin >> x[j];
				MM = max ((ll)MM, x[j]);
			}	
			for (int j = 0; j < n; j++) z[j] = 2;
			for (int j = 0; j < sz (w); j++)
				if (check (w[j].se))
					break;
			for (int j = 0; j < n; j++) cout << z[j];
			cout << endl;
			memset (c, 0, sizeof (c));
			for (int j = 0; j < n; j++) c[z[j]]++;
			memset (f, 0, sizeof (f));
			for (int j = 0; j < k; j++) {
				while (x[j] % 2 == 0) {
					f[2]++;
					x[j] /= 2;
				}
				while (x[j] % 3 == 0) {
					f[3]++;
					x[j] /= 3;
				}
				while (x[j] % 5 == 0) {
					f[5]++;
					x[j] /= 5;
				}
				while (x[j] % 7 == 0) {
					f[7]++;
					x[j] /= 7;
				}
			}
//			printf ("%d %d %d %d\n", abs (f[2] - (6 * (c[2] + c[6]) + 12 * c[4] + 24 * c[8])), abs (f[3] - 6 * (c[3] + c[6])), abs (f[5] - 6 * c[5]), abs (f[7] - 6 * c[7]));
			if ((i + 1) % 100 == 0)
				cerr << i + 1 << " / " << r << " " << clock () << endl;
		}
		cout << kkk << endl;

		cout << endl;

		cerr << it << " / " << tt << endl;
	}
	return 0;
}