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

#define maxN 1000001

ll dp[maxN];

ll revert(ll n) {
	ll ret = 0;
	while (n) {
		ret *= 10;
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main() {
	FOR(i, 0, maxN) dp[i] = INF;
	queue<int> q;
	q.push(1);
	dp[1] = 1;
	while (!q.empty()) {
		int f = q.front(); 
		q.pop();
		if (f+1<maxN&&dp[f + 1] > dp[f] + 1) {
			dp[f + 1] = dp[f] + 1;
			q.push(f + 1);
		}
		int rev = revert(f);
		if (rev<maxN&&dp[rev] > dp[f] + 1) {
			dp[rev] = dp[f] + 1;
			q.push(rev);
		}
	}
	int T, caso=1;
	ll N, counter, ans;
	cin >> T;
	while (T--) {
		cin >> N;
		cout << "Case #" << caso++ << ": ";
		counter = 10, ans = 10;
		if (N <= 10) {
			cout << N << endl;
			continue;
		}
		ll t1 = N;
		int cont = 0;
		while (t1 /= 10) cont++;
		t1 = 1;
		while (cont--) t1 *= 10;
		while (counter < t1) {
			ans += 9+counter;
			counter *= 10;
		}
		ll v1 = N - counter;
		ll v2;
		ll t = N;
		while (t >= 10) t /= 10;
		if (N == t*counter) {
			t--;
		}
		v2 = t;
		t *= counter;
		v2 += N - t;
		ans += min(v1, v2);
		//cout << dp[N] << " ";
		ans = dp[N];
		cout << ans << endl;
	}
	return 0;
}
