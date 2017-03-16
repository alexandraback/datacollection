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

int x;
int a[100];

int dp[100][1000001];

int go(int x, int k) {
	if (x > a[n - 1])
		re 0;
	if (k == n) {
		re 0;
	}
	if (dp[k][x] >= 0) {
		re dp[k][x];
	}
	int &ans = dp[k][x];
	if (a[k] < x) {
		ans = go(x + a[k], k + 1);
		re ans;
	}
	if (x != 1)
		ans = min(1 + go(x * 2 - 1, k), 1 + go(x, k + 1));
	if (x == 1)
		ans = 1 + go(x, k + 1);
	re ans;
}

int main() {
	int T;
	cin >> T;
	rep(I, T) {
		cerr << I + 1 << endl;
		cin >> x >> n;
		rep(i, n)
			cin >> a[i];
		sort(a, a + n);
		fill(dp, 255);
		cout << "Case #" << I + 1 << ": " << go(x, 0) << endl;
	}
	return 0;
}
