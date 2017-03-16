#pragma comment(linker, "/STACK:67108864")

#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>
#include <ctime>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 111;

bool is_palin(ll x) {
	string s = "", ss;
	while (x > 0) {
		s = s + char(x % 10);
		x /= 10;
	}
	ss = s;
	reverse(all(ss));
	return s == ss;
}

int t;
ll a, b, ans;
vector<ll> w;

int main() {

	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	for (ll x = 1; x <= 1000; x++) {
		if (is_palin(x) && is_palin(x * x))
			w.pb(x * x);
	}

	scanf("%d\n", &t);
	forn(ii, t) {
		cout << "Case #" << ii + 1 << ": ";
		cin >> a >> b;
		ans = 0;
		forn(i, w.size())
			if (a <= w[i] && w[i] <= b)
				ans++;
		cout << ans << '\n';
	}

    return 0;
}