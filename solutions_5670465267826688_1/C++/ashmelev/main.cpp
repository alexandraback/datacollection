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

ll m;
int n;
int zi = 2;
int zj = 3;
int zk = 4;

ii get(int a, int b) {
	if (a == 1)
		re mp(b, 1);
	if (b == 1)
		re mp(a, 1);
	if (a == b)
		re mp(1, -1);
	if (a == zi && b == zj)
		re mp(zk, 1);
	if (a == zi && b == zk)
		re mp(zj, -1);
	if (a == zj && b == zk)
		re mp(zi, 1);
	ii tmp = get(b, a);
	re mp(tmp.fi, -tmp.se);
}

ii get(ii a, int b) {
	ii tmp = get(a.fi, b);
	tmp.se *= a.se;
	re tmp;
}
string s, cs;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tc;
	cin >> tc;
	rep(tt, tc) {
		cout << "Case #" << tt + 1 << ": ";

		cin >> n >> m;
//cout << n << ' ' << m << endl;
		if (m > 20)
			m = 16 + m % 4;

		cin >> s;
		cs = s;
		rep(i, m - 1)
			s += cs;

		n = sz(s);
		int p1 = -1, p2 = -1;

		ii cur = mp(1, 1);
		rep(i, n) {
			cur = get(cur, s[i]-'i'+zi);
			if (cur == mp(zi, 1)) {
				p1 = i;
				break;
			}
		}
		if (p1 == n) {
			cout << "NO" << endl;
			continue;
		}

		cur = mp(1, 1);
		for (int i = p1 + 1; i < n; i++) {
			cur = get(cur, s[i]-'i'+zi);
			if (cur == mp(zj, 1)) {
				p2 = i;
				break;
			}
		}
		if (p2 == n) {
			cout << "NO" << endl;
			continue;
		}

		cur = mp(1, 1);
		for (int i = p2 + 1; i < n; i++) {
			cur = get(cur, s[i]-'i'+zi);
		}
		if (cur == mp(zk, 1))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	re 0;
}
