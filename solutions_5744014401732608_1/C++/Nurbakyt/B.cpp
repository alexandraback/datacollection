#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define sz(a) int((a).size())
#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%lld"
#endif
#define fname "."
#define pi pair < int, int >
#define pp pop_back

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int MAX_N = (int)2e5 + 123;
const double eps = 1e-6;
const int inf = (int)1e9 + 123;

using namespace std;

int n;
ll dp[60];
ll must;
bool ans[60][60];

void solve(int test) {
	cin >> n >> must;
	memset(dp, 0, sizeof dp);
	dp[n] = 1;
	memset(ans, 0, sizeof ans);
	for (int i = n - 1; i > 0; i--) {
		ll now = must;
		for (int j = i + 1; j <= n; j++) {
			if (now >= dp[j]) {
				ans[i][j] = 1;
				now -= dp[j];
				dp[i] += dp[j];
			}
		}
	}
	cout << "Case #" << test << ": ";
	if (dp[1] != must) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	cout << "POSSIBLE\n";
	for (int i = 1; i <= n; i++, cout << '\n')
		for (int j = 1; j <= n; j++)
			cout << ans[i][j];				
}

int main() {
	#ifdef Nick
	freopen(fname"in", "r", stdin);
	freopen(fname"out", "w", stdout);
	#endif
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
		solve(i);
	return 0;
}
