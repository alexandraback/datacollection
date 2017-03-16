#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <cstdlib>
#include <numeric>
#include <bitset>
#include <deque>
using namespace std;

#define REP(i, m, n) for(int i=(m); i<int(n); ++i)
#define rep(i, n) for(int i=0; i<int(n); ++i)
#define each(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pb push_back                                                                          
#define mp make_pair
#define def(a, x) __typeof(x) a = x
#define fi first
#define se second
typedef long long ll;
typedef pair<ll, ll> PI;
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

const int INF = 1<<29;
int N, M, K;
bool check(int s) {
	queue<int> Q;
	bool ok[20] = {};
	rep(i, N) rep(j, M) if (i == 0 || i+1 == N || j == 0 || j+1 == M) {
		if (!(s>>(i*M+j)&1)) {
			Q.push(i*M+j);
			ok[i*M+j] = true;
		}
	}
	while(!Q.empty()) {
		int k = Q.front();
		Q.pop();
		int i = k/M, j = k%M;
		rep(d, 4) {
			int ai = i+dx[d], aj = j+dy[d];
			if (0 <= ai && ai < N && 0 <= aj && aj < M && !(s>>(ai*M+aj)&1) && !ok[ai*M+aj]) {
				ok[ai*M+aj] = true;
				Q.push(ai*M+aj);
			}
		}
	}
	int cnt = 0;
	rep(i, N*M) if (!ok[i]) cnt++;
	if (cnt < K) return false;
	return true;
}
void solve() {
	cin >> N >> M >> K;
	int T = N*M;
	int ans = INF;
	rep(s, 1<<T) {
		if (ans <= __builtin_popcountll(s)) continue;
		if (!check(s)) continue;
		ans = __builtin_popcountll(s);
	}
	cout << ans << endl;
}

int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
}

