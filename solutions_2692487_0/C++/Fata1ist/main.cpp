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
const int MAXN = 1111;
const ll MOD = 1E9;

int i, t, sz, n, ans, nans;
vi a;

int main() {

	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	cin >> t;
	forn(ii, t) {
		cout << "Case #" << ii + 1 << ": ";

		cin >> sz >> n;

		a.clear();
		a.resize(n);
		forn(j, n)
			cin >> a[j];
		sort(all(a));

		if (sz == 1) {
			cout << n << '\n';
			continue;
		}

		i = 0;
		while (i < n && sz > a[i]) {
			sz += a[i];
			i++;
		}

		ans = n - i;
		nans = 0;
		while (i < n) {
			while (sz <= a[i]) {
				sz += sz - 1;
				nans++;
			}
			while (i < n && sz > a[i]) {
				sz += a[i];
				i++;
			}
			ans = min(ans, nans + (n - i));
		}

		cout << ans << '\n';
	}

    return 0;
}