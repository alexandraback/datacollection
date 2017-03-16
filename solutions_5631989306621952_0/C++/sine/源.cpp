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
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int t, cas = 1;
	cin >> t;
	while (t--) {
		string s, ans = "";
		cin >> s;
		for (int i = 0; i < (int)s.length(); i++) {
			if (ans.empty() || ans[0] <= s[i]) ans = s[i] + ans;
			else ans = ans + s[i];
		}
		cout << "Case #" << cas++ << ": " << ans << endl;
	}
	return 0;
}
