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

#define INF 1000000000000000LL
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

ll dp[maxN], prevvv[maxN];

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
			prevvv[f + 1] = f;
			q.push(f + 1);
		}
		int rev = revert(f);
		if (rev<maxN&&dp[rev] > dp[f] + 1) {
			dp[rev] = dp[f] + 1;
			prevvv[rev] = f;
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
		int cont = 0, cont2;
		while (t1 /= 10) cont++;
		cont2 = cont;
		t1 = 1;
		while (cont--) t1 *= 10;
		cont = 1;
		while (counter < t1) {
			cont++;
			ll tt = 1;
			FOR(i, 0, (cont+1)/2) {
				tt *= 10;
			}
			ans += 9+tt;
			tt = 1;
			FOR(i, 0, (cont) / 2) {
				tt *= 10;
			}
			ans += tt-10;
			counter *= 10;
		}
		ll temp1=N-counter;
		FOR(i, 0, cont2+1) {
			ll t = 1;
			FOR(j, 0, i) {
				t *= 10;
			}
			ll v1, v2, ttt;
			ttt = N;
			v2 = revert(ttt) % t;
			v1 = counter + v2;
			v1=revert(v1);
			if (v1<=N) v2 += N - v1;
			else {
				ttt--;
				v2 = revert(ttt) % t;
				v1 = counter + v2;
				v1 = revert(v1);
				if (v1 <= N) v2 += N - v1;
			}
			temp1 = min(temp1, v2+1);
		}
		ans += temp1;
		//cout << dp[N] << " ";
		//ans = dp[N];
		cout << ans << endl;
		//if (dp[N] != ans) cout << "ERRORRR" << endl;
		/*while (N != 1) {
			cout << N << endl;;
			N = prevvv[N];
		}*/
	}
	return 0;
}
