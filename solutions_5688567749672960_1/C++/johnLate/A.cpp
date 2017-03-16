#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for(__typeof__((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) ({ if(1) fprintf(stderr, __VA_ARGS__); })
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })


// horrible hack - I'm sorry

const string zero = "000000000000000000";
const string nine = "999999999999999999";

int TC;
const int maxDP = 91;
pll dp[maxDP];

pll quick[1000]; // value, cost
int Q;

ll bar(ll x) {
	ll res = x;
	string z = to_string(x);
	reverse(all(z));
	ll r = stoll(z);

	if (r > x || z[0] == '0') r = x;
	int add = (r == x) ? 0 : 1;
	FOR(i,0,Q) {
		if (quick[i].first > r) break;
		res = min(res, quick[i].second + r - quick[i].first + add);
	}

	return res;
}

ll foo(ll x) {
	ll res = x;
	if (x < maxDP) {
		res = dp[x].first;
		while (false && x > 1) {
			if (x != dp[x].second + 1)
				DBG("%lld: %lld %lld\n", x, dp[x].first, dp[x].second);
			x = dp[x].second;
		}
		return res;
	}

	res = min(res, bar(x));
	string num = to_string(x);
	int k = sz(num) - 1;
	while(true) {
		if (num[k] != '1') {
			if (num[k] == '0')
				num[k-1]--;
			num[k] = '1';
		} else {
			int v = k-1;
			while (v > 0 && num[v] == '0') v--;
			if (v < 0) break;
			num[v]--;
		}

		FORD(i,1,k) {
			if (num[i] < '0') {
				num[i-1]--;
				num[i] = '0';
			}
		}

		if (num[0] <= '0') break;

		ll d = stoll(num);
		assert(d < x);
		res = min(res, bar(d) + x-d);
	}
	//if (stop-- < 1) exit(1);
	return res;
}

int main() {
	ios::sync_with_stdio(false);

	dp[0] = mp(ll(1e15), 0);
	dp[1] = mp(1, 0);
	FOR(i,2,maxDP) {
		ll rev = 0;
		string x = to_string(i);
		reverse(all(x));
		if (x[0] != '0') {
			int tmp = stoi(x);
			if (tmp < i)
				rev = tmp;
		}
		dp[i] = min(
			mp(dp[i-1].first + 1, ll(i-1)),
			mp(dp[rev].first + 1, rev)
		);
		if (i < 5)
			DBG("%d: %lld %lld\n", i, dp[i].first, dp[i].second);
	}

	set<ll> tmp;
	FOR(len,2,15) {
		FOR(mid,1,len) {
			string nu = nine.substr(0, mid) + zero.substr(0, len - mid - 1) + "1";
			ll num = stoll(nu);
			tmp.insert(num);
		}
	}

	Q = 0;
	quick[Q++] = mp(1LL, 1LL);
	for (ll x : tmp) {
		string z = to_string(x);
		reverse(all(z));
		ll r = stoll(z);

		ll y = x;
		FOR(i,0,Q) {
			if (r < quick[i].first) continue;
			y = min(y, quick[i].second + r - quick[i].first + 1);
		}
		ll f = foo(x);
		if (f >= y) {
			//DBG("quick %d %lld %lld - %lld\n", Q, x, y, f);
			quick[Q++] = mp(x, y);
		}
	}

	cin >> TC;
	FOR(tc, 1, TC+1) {
		ll want;
		cin >> want;
		ll res = foo(want);
		if (want > maxDP) {
			res = min(res, foo(want-1) + 1);
		}
		printf("Case #%d: %lld\n", tc, res);
	}
}
