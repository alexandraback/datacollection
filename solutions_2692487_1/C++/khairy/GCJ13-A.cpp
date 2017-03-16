#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <list>
#include <set>
#include <climits>
#include <map>
#include <stack>
#include <queue>
#include <complex>
#include <cmath>
#include <sstream>
#include <deque>
#include <utility>
#include <bitset>
#include <ext/hash_set>
#include <ext/hash_map>

using namespace std;
using namespace __gnu_cxx;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back
#define oo (1<<30)
#define M 1001
#define sz(v) (int)v.size()
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define iter(it,s) for(it=s.begin();it!=s.end();it++)
#define show(x) cerr<<#x<<" = "<<x<<endl;
#define mem(s,v) memset(s,v,sizeof(s))
#define ppc(x) __builtin_popcount((x))

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

ll tot;
int n, mx;
vi v;
int memo[102][1000002];

int rec(int idx, int cnt) {
	if (idx == n)
		return 0;
	int &res = memo[idx][cnt];
	if (res != -1)
		return res;
	res = oo;
	if (cnt > v[idx])
		res = rec(idx + 1, min(mx, cnt + v[idx]));
	else {
		res = min(res, rec(idx + 1, cnt) + 1);
		res = min(res, rec(idx, min(mx, cnt + cnt - 1)) + 1);
	}
	return res;
}

int dp(int x) {
	REV (idx, 0, n - 1) {
		REV (cnt , x, mx) {
			memo[idx][cnt] = oo;
			if (cnt > v[idx])
				memo[idx][cnt] = memo[idx + 1][min(mx, cnt + v[idx])];
			else {
				memo[idx][cnt] = min(memo[idx][cnt], memo[idx + 1][cnt] + 1);
				memo[idx][cnt] = min(memo[idx][cnt],
						memo[idx][min(mx, cnt + cnt - 1)] + 1);
			}
		}
	}
	return memo[0][x];
}

int main() {
	freopen("AL.in", "rt", stdin);
	freopen("o.txt", "wt", stdout);
	int t;
	cin >> t;
	FOR (cs, 1 , t + 1) {
		int x;
		cin >> x >> n;
		v.clear();
		v.resize(n);
		mx = 0;
		FOR (i ,0 , n)
			cin >> v[i], mx = max(mx, v[i]);
		mx++;
		sort(all(v));
		tot = x;
		mem (memo, 0);
		printf("Case #%d: %d\n", cs, dp(x));
	}
	return 0;
}
