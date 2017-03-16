#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <ctime>
#include <iostream>
#include <sstream>
#include <cctype>

#define PI 3.14159265358979
#define EPS 1e-9

using namespace std;

#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, m, n) for (int i=m; i<=n; i++)
#define ABS(a) (((a)>0)?(a):(-(a)))
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;

ll n;
map<ll, int> mp;
queue<ll> q;

ll rev(ll x) {
	ll res = 0;
	while (x>0) {
		res = res*10 + x%10;
		x /= 10;
	}
	return res;
}

void solve() {
	scanf("%lld", &n);
	q.push(1);
	mp[1] = 1;
	while (mp[n]==0) {
		ll x = q.front(); q.pop();
		ll y = rev(x);
		if (mp[y]==0) {
			q.push(y);
			mp[y] = mp[x]+1;
		}
		if (mp[x+1]==0) {
			q.push(x+1);
			mp[x+1] = mp[x]+1;
		}
	}
	printf("%d\n", mp[n]);
}

int main() {
	int t; scanf("%d", &t);
	REP(i, t) {
		printf("Case #%d: ", i+1);
		solve();
	}
	return 0;
}
