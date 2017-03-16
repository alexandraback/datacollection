#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define y0 y32479
#define y1 y95874
#define fill(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define unq(x) (x.resize(unique(all(x)) - x.begin()))
#define spc(i,n) " \n"[i == n - 1]

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

template<class T> T abs(T x) { return x > 0 ? x : -x;}

int m;
int n;
int was[1050];
vi v1[1050], v2[1050];
int z;
int color[1050];
int mc[1050];

int get1(int x) {
	int ans = 1;
	fill(was, 0);
	was[x] = 1;
	int y = v1[x][0];
	while (!was[y]) {
		was[y] = 1;
		ans++;
		y = v1[y][0];
	}
	if (y == x)
		re ans;
	else
		re 0;
}

int getmax(int x, int p) {
	int ans = 1;
	for (int y: v2[x])
		if (y != p)
			ans = max(ans, 1 + getmax(y, p));
	re ans;
}

int get2(int a, int b) {
	re getmax(a, b) + getmax(b, a);
}

void go(int x, int c) {
	color[x] = c;
	was[x] = 1;
	for (int y : v2[x])
		if (!was[y])
			go(y, c);
	for (int y : v1[x])
		if (!was[y])
			go(y, c);

}

int main() {
#ifdef LOCAL_BOBER
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int tc;
	cin >> tc;
	rep(tt, tc) {
		cout << "Case #" << tt + 1 << ": ";

		cin >> n;
		rep(i, n) {
			v1[i].clear();
			v2[i].clear();
		}
		rep(i, n) {
			int x;
			cin >> x;
			x--;
			v1[i].pb(x);
			v2[x].pb(i);
		}

		fill(mc, 0);
		fill(was, 0);
		int cc = 0;
		rep(i, n) {
			if (!was[i])
				go(i, cc++);
		}

		int ans = 0;
		rep(i, n) {
			ans = max(ans, get1(i));
		}

		rep(i, n) rep(j, n)
			if (v1[i][0] == j && v1[j][0] == i) {
				//ans = max(ans, get2(i, j));
				mc[color[i]] = max(mc[color[i]], get2(i, j));
			}

		int tmp = 0;
		rep(i, cc)
		tmp += mc[i];
		ans = max(ans, tmp);

		cout << ans << endl;
	}

	re 0;
}
