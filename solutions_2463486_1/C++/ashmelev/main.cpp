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

int o[11000000];

ll get(int l, int r) {
	int ans = o[r];
	if (l > 0)
		ans -= o[l - 1];
	re ans;
}

ll getans(ll l, ll r) {
	ll t = max(0ll, (ll)sqrt(l) - 10ll);
	while (t * t < l)
		t++;
	l = t;
	t = (ll) sqrt(r) + 10;
	while (t * t > r)
		t--;
	r = t;

	re get(l, r);
}

int check(ll x) {
	ll y = 0;
	ll sx = x;
	while (x) {
		y = y * 10 + x % 10;
		x /= 10;
	}
	re sx == y;
}

void prep() {
	for (int i = 1; i <= 10000000; i++)
		if (check(i)) {
			if (check((ll) i * (ll) i))
				o[i] = 1;
		}
	for (int i = 1; i <= 10000000; i++)
		o[i] += o[i - 1];
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	prep();

	int tc;
	cin >> tc;
	rep(tt, tc) {
		cout << "Case #" << tt + 1 << ": ";

		ll l, r;
		cin >> l >> r;
		cout << getans(l, r) << endl;
	}

	re 0;
}
