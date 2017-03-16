#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;
typedef long double ld;

ll E, R, N;
ll v[10010], cur[10010];
bool vis[10010];
pair<ll, int> v2[10010];

ll memo[100][100];

ll calc(int ind, ll now) {
	if (ind == N - 1)
		return v[ind] * now;
	if (memo[ind][now] != -1)
		return memo[ind][now];
	ll res = 0;
	for (ll i = 0; i <= now; ++i)
		res = max(res, calc(ind + 1, min(E, now - i + R)) + v[ind] * i);
	return memo[ind][now] = res;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("1.in", "rt", stdin);
//	freopen("1A/B-small-attempt0.in", "rt", stdin);
//	freopen("1A/B-fast.out","wt",stdout);
	freopen("1A/B-large.in", "rt", stdin);
	freopen("1A/B-large.out","wt",stdout);
#endif
	int n;
	cin >> n;
	for (int tt = 0; tt < n; ++tt) {
		cout << "Case #" << tt + 1 << ": ";
		cin >> E >> R >> N;
		ll res = 0;
		for (int i = 0; i < N; ++i) {
			cur[i] = E;
			vis[i] = 0;
			cin >> v[i];
//			if (i != N - 1)
//				res += v[i] * min(E, R);
//			else
//				res += v[i] * E;
			v2[i] = make_pair(v[i], i);
		}
		sort(v2, v2 + N);
		reverse(v2, v2 + N);
		for (int i = 0; i < N; ++i) {
			ll val = v2[i].first;
			int ind = v2[i].second;
			int prv = ind, nxt = ind;
			while (prv >= 0 && !vis[prv])
				prv--;
			while (nxt < N && !vis[nxt])
				nxt++;
			// calculate value at leaving

			// Max value I start with?
			ll start = (prv == -1) ? E : min(E, cur[prv] + R * (ind - prv));
			// Minimum value I can end with?
			ll end = (nxt == N) ? 0 : max(0ll, E - (nxt - ind) * R);
			vis[ind] = 1;
			cur[ind] = min(start, end);
			res += max(0ll, start - end) * val;
		}
//		memset(memo, -1, sizeof memo);
//		cout << res << " " << calc(0, E) << endl;
//		cout << calc(0, E) << endl;
		cout << res << endl;
	}
	return 0;
}
