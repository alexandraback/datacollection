#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <utility>
#include <algorithm>

#define pii pair<int, int>
#define vi vector<int>
#define fi first
#define se seconda
#define ll long long
#define mp make_pair
#define pb push_back
#define REP(a, b) for (int a = 0; a < b; ++a)
#define FORU(a, b, c) for (int a = b; a <= c; ++a)
#define FORD(a, b, c) for (int a = b; a >= c; --a)
using namespace std;

int dp[10000005];

bool isPalin(ll x) {
	char st[22];
	
	sprintf(st, "%lld", x);
	
	int len = strlen(st);
	
	REP(i, len >> 1) {
		if (st[i] != st[len-i-1])
			return false;
	}
	
	return true;
}

int main() {
	int T;
	ll a, b;
	
	memset(dp, 0, sizeof(dp));
	
	FORU(i, 1, 10000000)
		if (isPalin((ll)i * (ll)i) && (isPalin((ll)i)))
			dp[i] = dp[i-1] + 1;
		else
			dp[i] = dp[i-1];
	
	scanf("%d", &T);
	
	FORU(tc, 1, T) {
		scanf("%lld %lld", &a, &b);
		
		--a;
		
		int awal = (int)sqrt(a);
		int akhir = (int)sqrt(b);
		
		printf("Case #%d: %d\n", tc, dp[akhir] - dp[awal]);
	}
	
	return 0;
}
