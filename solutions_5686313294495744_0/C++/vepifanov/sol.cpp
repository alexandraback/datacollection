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

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
int was[1000];
vi v[1000];
int p[1000];
int ct;
int c[2];
map<string, int> all[2];
string s, t;

int get (int t, string s) {
	if (all[t].count (s)) re all[t][s];
	if (t == 0) v[c[t]].clear ();
	all[t][s] = c[t]++;
	re c[t] - 1;
}

int go (int x) {
	if (x == -1) re 1;
	if (was[x] == ct) re 0;
	was[x] = ct;
	for (int i = 0; i < sz (v[x]); i++)
		if (go (p[v[x][i]])) {
			p[v[x][i]] = x;
			re 1;
		}
	re 0;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		cin >> n;
		for (int i = 0; i < 2; i++) all[i].clear ();
		c[0] = c[1] = 0;
		for (int i = 0; i < n; i++) {
			cin >> s >> t;
			int a = get (0, s);
			int b = get (1, t);
			v[a].pb (b);
		}
		for (int i = 0; i < c[1]; i++) p[i] = -1;
		int cur = 0;
		for (int i = 0; i < c[0]; i++) {
			ct++;
			if (go (i)) cur++;
		}
		cout << "Case #" << it << ": " << n - (c[0] + c[1] - cur);
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}