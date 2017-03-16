#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define maxD 1001
#define maxP 1001

int nums[maxD], dp[maxP][maxP];

int getDp(int n, int k) {
	if (n <= k) return 0;
	if (dp[n][k] != -1) return dp[n][k];
	else return dp[n][k] = getDp((n + 1) / 2, k) + getDp(n / 2, k) + 1;
}

int main() {
	int T, caso=1, ans, D;
	FOR(i, 0, maxP) {
		FOR(j, 0, maxD) {
			if (i <= j) {
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = INF;
			FOR(k, 1, i) {
				dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
			}
		}
	}
	cin >> T;
	while (T--) {
		cin >> D;
		FOR(i, 0, D) {
			cin >> nums[i];
		}
		sort(nums, nums + D);
		ans = INF;
		FOR(i, 1, nums[D - 1]+1) {
			int t = i;
			FOR(j, 0, D) {
				t+=getDp(nums[j], i);
			}
			ans = min(ans, t);
		}
		/*int lo = 0, hi = nums[D - 1];
		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;
			if (possible(mid)) {
				lo = mid;
			}
			else hi = mid - 1;
		}
		ans = lo;
		if (possible(hi)) ans = hi;*/
		cout << "Case #" << caso++ << ": " << ans << endl;
	}
 	return 0;
}
