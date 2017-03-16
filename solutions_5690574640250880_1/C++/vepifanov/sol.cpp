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
int k;
string g[51];
int was[51][51][2501];

int go (int i, int j, int k) {
	if (i == n) re int (k == 0);
	if (was[i][j][k]) re 0;
	was[i][j][k] = 1;
	for (int t = 0; t <= j; t++)
		if (t != 1 && go (i + 1, t, k - j)) {
			for (int a = 0; a < j; a++)
				g[i][a] = '.';
			re 1;
		}
	re 0;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		cin >> n >> m >> k; k = n * m - k;
		int ok = 0;
		for (int i = 0; i < n; i++) g[i] = string (m, '*');
		int cur;
		if (k == 1)
			ok = 1;
		else {
			if (m == 1) {
				ok = 1;
				for (int i = 0; i < k; i++) g[i][0] = '.';
			} else {
				memset (was, 0, sizeof (was));
				for (int t = 2; t <= m && t <= k; t++)
					if (go (1, t, k - t)) {
						for (int i = 0; i < t; i++) g[0][i] = '.';
						ok = 1;
						break;
					}
			}
		}
		g[0][0] = 'c';
		cout << "Case #" << it << ":" << endl;
		if (!ok) {
			cout << "Impossible" << endl;
			cerr << n << " " << m << " " << n * m - k << endl;
		}	
		else 
			for (int i = 0; i < n; i++) cout << g[i] << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}