#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>

#pragma warning (disable:4996)

using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); i--)

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;

const ll mod = 1000000007;
ll powmod(ll a, ll b) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1) res = res*a%mod; a = a*a%mod; } return res; }

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int t, cas = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector< vi > a(2 * n - 1, vi(n));
		map<int, int> mp;
		rep(i, 0, 2 * n - 1) {
			rep(j, 0, n) {
				cin >> a[i][j];
				if (mp.count(a[i][j])) mp[a[i][j]]++;
				else mp[a[i][j]] = 1;
			}
		}
		vi b;
		rep(i, 1, 2501) {
			if (mp.count(i) && mp[i] % 2) {
				b.push_back(i);
			}
		}
		sort(all(b));
		cout << "Case #" << cas++ << ":";
		rep(i, 0, n) {
			cout << ' ' << b[i];
		}
		cout << endl;
	}
	return 0;
}
