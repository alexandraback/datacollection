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
int f[20], t[20], k[20];
int g[20][40];
int ct;
int was[1 << 20];
int res[20];

int go (int i, int mask) {
	if (i == m) re 1;
	if (was[mask] == ct) re 0;
	was[mask] = ct;
	for (int j = 0; j < m; j++)
		if (((mask >> j) & 1) == 0 && f[t[j]] > 0) {
			f[t[j]]--;
			for (int k = 0; k < ::k[j]; k++)
				f[g[j][k]]++;
			res[i] = j;
			if (go (i + 1, mask | (1 << j))) re 1;
			for (int k = 0; k < ::k[j]; k++)
				f[g[j][k]]--;
			f[t[j]]++;
		}
	re 0;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {

		scanf ("%d%d", &n, &m);
		memset (f, 0, sizeof (f));
		for (int i = 0; i < n; i++) {
			int a;
			scanf ("%d", &a); a--;
			f[a]++;
		}	
		for (int i = 0; i < m; i++) {
			scanf ("%d%d", &t[i], &k[i]);
			t[i]--;
			for (int j = 0; j < k[i]; j++) {
				scanf ("%d", &g[i][j]);
				g[i][j]--;
			}
		}

		cout << "Case #" << it << ": ";
		ct++;
		if (!go (0, 0)) {
			cout << "IMPOSSIBLE";
		} else {
			for (int i = 0; i < m; i++) printf ("%d ", res[i] + 1);
		}

		cout << endl;

		cerr << it << " / " << tt << endl;
	}
	return 0;
}