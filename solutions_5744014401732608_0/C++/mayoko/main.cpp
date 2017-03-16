#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
//#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<list>
#include<queue>
#include<deque>
#include<algorithm>
//#include<numeric>
#include<utility>
//#include<memory>
#include<functional>
#include<cassert>
#include<set>
#include<stack>
#include<random>

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

void solve() {
	int B;
	ll M;
	cin >> B >> M;
	ll maxi = 1ll<<(B-2);
	if (maxi < M) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	cout << "POSSIBLE" << endl;
	vector<ll> dp(B);
	vector<vi> ans(B, vi(B));
	dp[B-1] = 1;
	for (int i = B-2; i >= 0; i--) {
		ll rest = M;
		for (int j = i+1; j < B; j++) {
			if (rest >= dp[j]) {
				rest -= dp[j];
				dp[i] += dp[j];
				ans[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < B; i++) {
		for (int j = 0; j < B; j++)
			cout << ans[i][j];
		cout << endl;
	}
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
    	cout << "Case #" << t << ": ";
    	solve();
    }
    return 0;
}
