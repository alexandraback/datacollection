#ifndef LOCAL_BOBER
#pragma comment(linker, "/STACK:134217728")
#endif

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
#define prev prev239
#define next next239
#define hash hash239
#define rank rank239
#define sqrt(x) sqrt(abs(x))
#define unq(x) (x.resize(unique(all(x)) - x.begin()))

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef long long ll;
typedef double D;
typedef long double LD;
typedef pair<ll, ll> pll;

template<class T> T abs(T x) {
	return x > 0 ? x : -x;
}

int m;
int n;

int mas[1000];
int sum[1 << 20];
vector<pll> v;

int main() {
#ifdef LOCAL_BOBER
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#endif

	int tc;
	cin >> tc;
	rep(tt, tc) {
		cout << "Case #" << tt + 1 << ": " << endl;

		cin >> n;
		rep(i, n)
		cin >> mas[i];

		rep(i, (1 << n)) {
			ll tmp = 0;
			rep(j, n)
			if (i & (1 << j))
				tmp += mas[j];
			sum[i] = tmp;
		}

		v.clear();
		rep(i, (1 << n))
			v.pb(mp(sum[i], i));
		sort(all(v));
		int f = 0;
		rep(i, sz(v) - 1)
		if (v[i].fi == v[i + 1].fi) {
			int c1 = v[i].se;
			int c2 = v[i + 1].se;

			vi v1, v2;
			rep(i, n) {
				if ((c1 & (1 << i)) && (c2 & (1 << i)))
					continue;
				if (c1 & (1 << i))
					v1.pb(mas[i]);
				if (c2 & (1 << i))
					v2.pb(mas[i]);
			}

			rep(i, sz(v1))
				cout << v1[i] << ' ';
			cout << endl;
			rep(i, sz(v2))
				cout << v2[i] << ' ';
			cout << endl;
			f = 1;
			break;
		}

		if (!f)
			cout << "Impossible" << endl;
	}

	re 0;
}
