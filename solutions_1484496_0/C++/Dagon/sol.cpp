#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <deque>
#include <bitset>

#define sqr(x) ((x) * (x))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define y0 ywuerosdfhgjkls
#define y1 hdsfjkhgjlsdfhgsdf
#define j1 j924
#define j0 j2834
#define sqrt(x) (sqrt(abs(x)))
#define re return
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = ((n) - 1); i >= 0; i--)
#define fill(a, x) memset(a, x, sizeof(a))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef double D;
typedef vector <string> vs;

template <class T> inline T abs(T a) {
	return a > 0 ? a : -a;
}

int n;
int m;

int a[500];

const int nmax = 20 * 100000 + 1;

int p[nmax];
int q[20][nmax];


int main() {
	int T;
	cin >> T;
	rep(I, T) {
		cin >> n;
		rep(i, n) {
			cin >> a[i];
		}
		fill(p, 0);
		fill(q, 0);
		rep(mask, (1 << n)) {
			if (mask == 0)
				continue;
			int s = 0;
			rep(i, n) {
				if (mask & (1 << i))
					s += a[i];
			}
			p[s] = mask;
			rep(i, n) {
				if (!(mask & (1 << i)))
					q[i][s] = mask;
			}
		}
		bool kpyto = false;
		int ans1, ans2;
		ans1 = ans2 = -1;
		for (int i = 0; i < nmax; i++) {
			int mask = 0;
			if (p[i])
				mask = p[i];
			else
				continue;
			rep(j, n) {
				if (mask & (1 << j)) {
					if (q[j][i]) {
						ans1 = mask;
						ans2 = q[j][i];
						kpyto = true;
						break;
					}
				}
			}
			if (kpyto)
				break;
		}
		cout << "Case #" << I + 1 << ":" << endl;
		if (!kpyto)
			cout << "Impossible" << endl;
		else {
			rep(i, n) {
				if (ans1 & (1 << i))
					cout << a[i] << ' ';
			}
			cout << endl;
			rep(i, n) {
				if (ans2 & (1 << i))
					cout << a[i] << ' ';
			}
			cout << endl;
		}
	}
	return 0;
}
