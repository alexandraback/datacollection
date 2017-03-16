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

ll gcd(ll a, ll b) {
	re b ? gcd(b, a % b) : a;
}

int main() {
	int T;
	cin >> T;
	rep(I, T) {
		ll a, b;
		char c;
		scanf("%lld%c%lld", &a, &c, &b);
		ll q = gcd(a, b);
		a /= q;
		b /= q;
		if (b > 1ll << 40) {
			cout << "Case #" << I + 1 << ": impossible" << endl;
			continue;
		}
		if (b & (b - 1)) {
			cout << "Case #" << I + 1 << ": impossible" << endl;
			continue;
		}
		int ans = 0;
		while (1) {
			ans++;
			if (a * 2 >= b)
				break;
			b /= 2;
		}
		cout << "Case #" << I + 1 << ": " << ans << endl;
	}
	return 0;
}
