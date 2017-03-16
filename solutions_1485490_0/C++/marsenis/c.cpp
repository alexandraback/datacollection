#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <functional>
#include <string>
#include <map>

using namespace std;

//	Pairs
#define MP make_pair
#define F first
#define S second
typedef pair<long , long long> ii;

// Vectors
#define PB push_back
typedef vector<int> vi;
typedef vector<vi> vvi;

#define MAX 105

map< pair< ii, ii >, long long > dp;
long long q1[MAX], q2[MAX], typ1[MAX], typ2[MAX];

long long rdp(long long x,long long y, long long a, long long b) {
	pair<ii, ii> p = MP( MP(x, y), MP(a, b) );
	if (dp.find(p) != dp.end() ) return dp[p];

	if (x == 0 || y  == 0) return 0;
	
	if (typ1[x] != typ2[y]) {
		dp[p] = max( rdp(x-1, y, q1[x-1], b), rdp(x, y-1, a, q2[y-1]) );
		return dp[p];
	} else {
		if (a < b)
			dp[p] = rdp(x-1, y, q1[x-1], b - a) + a;
		else if (a > b)
			dp[p] = rdp(x, y-1, a - b, q2[y-1]) + b;
		else
			dp[p] =  rdp(x-1, y-1, q1[x-1], q2[y-1]) + a;

		return dp[p];
	}
}

int main() {
	//freopen("c.in", "r", stdin);
	long long tst, n, m;

	scanf("%lld", &tst);
	for (long long t = 1; t<=tst; t++) {
		scanf("%lld %lld", &n, &m);

		for (long long i=1; i<=n; i++)
			scanf("%lld%lld", &q1[i], &typ1[i]);
		for (long long i=1; i<=m; i++)
			scanf("%lld%lld", &q2[i], &typ2[i]);
	
		printf("Case #%lld: %lld\n", t, rdp(n, m, q1[n], q2[m]));
		dp.clear();
	}
	return 0;
}

