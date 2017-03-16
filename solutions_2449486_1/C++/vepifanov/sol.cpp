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
int x[100][100];
int r[100];
int c[100];

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		scanf ("%d%d", &n, &m);
		for (int i = 0; i < n; i++) r[i] = 0;
		for (int j = 0; j < m; j++) c[j] = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				scanf ("%d", &x[i][j]);
				r[i] = max (r[i], x[i][j]);
				c[j] = max (c[j], x[i][j]);
			}
		int ok = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (x[i][j] != min (r[i], c[j]))
					ok = 0;
		
		cout << "Case #" << it << ": " << (ok ? "YES" : "NO");

		cout << endl;

		cerr << it << " / " << tt << endl;
	}
	return 0;
}