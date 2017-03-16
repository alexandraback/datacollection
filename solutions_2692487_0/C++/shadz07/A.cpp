#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <map>
#include <stack>

#define fi first
#define se second
#define mp make_pair
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define REP(a,b) for(int a = 0; a < b; ++a)
#define FORU(a,b,c) for(int a = b; a <= c; ++a)
#define FORD(a,b,c) for(int a = b; a >= c; --a)
#define MOD 1000000000
#define MODLL 1000007LL
#define INF 1023123123
#define pb push_back
using namespace std;

int n;
ll mote[105];
map <pair <int, ll>, int> dp;

int f(int pos, ll x) {
	if (pos == n)
		return 0;
	
	pair <int, ll> temp = mp(pos, x);
	
	if (dp.count(temp) != 0)
		return dp[temp];
	
	int ret;
	
	dp[temp] = INF;
	
	if (x > mote[pos])
		ret = f(pos + 1, x + mote[pos]);
	else
		ret = min(1 + f(pos + 1, x), 1 + f(pos, (x << 1LL) - 1));
	
	dp[temp] = ret;
	
	return ret;
}

int main() {
	int T;
	ll armin;
	
	scanf("%d", &T);
	
	FORU(tc, 1, T) {
		printf("Case #%d: ", tc);
		
		scanf("%lld %d", &armin, &n);
		
		REP(i, n)
			scanf("%lld", &mote[i]);
		
		sort(mote, mote + n);
		
		dp.clear();
		
		printf("%d\n", f(0, armin));
	}
	
	return 0;
}
