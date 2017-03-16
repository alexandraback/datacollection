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
int e, u;
int x[10000];

ll go (int l, ll el, int r, ll er) {
	if (r <= l) re 0;
	int t = l;
	for (int i = l; i < r; i++)
		if (x[i] > x[t])
			t = i;
	int a = max ((ll)0, er - (ll)(r - t) * u);
	int b = min ((ll)e, el + (ll)(t - l) * u);
	re (ll)(b - a) * x[t] + go (l, el, t, b) + go (t + 1, a + u, r, er);
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {

		scanf ("%d%d%d", &e, &u, &n);
		for (int i = 0; i < n; i++) scanf ("%d", &x[i]);

			
		cout << "Case #" << it << ": " << go (0, e, n, 0);

		cout << endl;

		cerr << it << " / " << tt << endl;
	}
	return 0;
}