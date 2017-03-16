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

bool ok(vvi a) {
	int n = sz(a);
	if (!n)
		re true;
	int m = sz(a[0]);
	if (!m)
		re true;
	int imin, jmin;
	imin = jmin = 0;
	rep(i, n) {
		rep(j, m) {
			if (a[i][j] < a[imin][jmin]) {
				imin = i;
				jmin = j;
			}
		}
	}
	//line
	bool kpyto = true;
	rep(j, m) {
		if (a[imin][j] != a[imin][jmin])
			kpyto = false;
	}
	if (kpyto) {
		for (int i = imin + 1; i < n; i++)
			a[i - 1] = a[i];
		a.pop_back();
		return ok(a);
	}
	//column
	kpyto = true;
	rep(i, n)
		if (a[i][jmin] != a[imin][jmin])
			kpyto = false;
	if (kpyto) {
		rep(i, n) {
			for (int j = jmin + 1; j < m; j++)
				a[i][j - 1] = a[i][j];
			a[i].pop_back();
		}
		return ok(a);
	}
	re false;
}

int main() {
	int T;
	cin >> T;
	rep(I, T) {
		cin >> n >> m;
		vvi a;
		a.resize(n);
		rep(i, n) {
			a[i].resize(m);
			rep(j, m)
				cin >> a[i][j];
		}
		cout << "Case #" << I + 1 << ": " << (ok(a) ? "YES" : "NO") << endl;
	}
	return 0;
}
