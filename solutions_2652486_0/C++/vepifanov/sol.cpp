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

int n;
int m;
int r, k;
set<int> all;
ll x[12], y[12], z[12];

int go (int i, int j) {
	if (i == n) {
		for (int t = 0; t < k; t++) all.insert (x[t]);
		for (int mask = 0; mask < (1 << n); mask++) {
			ll cur = 1;
			for (int i = 0; i < n; i++)
				if ((mask >> i) & 1)
					cur *= y[i];
			all.erase (cur);
		}
		if (sz (all) == 0) {
			for (int i = 0; i < n; i++) z[i] = y[i];
			re 1;
		}
		re 0;
	}
	for (int k = j; k <= m; k++) {
		y[i] = k;
		if (go (i + 1, k)) re 1;
	}
	re 0;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {

	        scanf ("%d%d%d%d", &r, &n, &m, &k);
		cout << "Case #" << it << ":" << endl;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < k; j++) cin >> x[j];
			go (0, 2);
			for (int j = 0; j < n; j++) cout << z[j];
			cout << endl;
		}

		cout << endl;

		cerr << it << " / " << tt << endl;
	}
	return 0;
}