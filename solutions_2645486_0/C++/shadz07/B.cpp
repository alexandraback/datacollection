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
#define INF 2123123123
#define pb push_back
using namespace std;

int n, dp[7][100], v[105], E, R;

int f(int energy, int pos) {
	if (pos == n)
		return 0;
	
	if (dp[energy][pos] != -1)
		return dp[energy][pos];
	
	int &ret = dp[energy][pos] = 0;
	
	REP(i, energy + 1)
		ret = max(ret, (v[pos] * i) + f(min(E, energy - i + R), pos + 1));
	
	return ret;
}

int main() {
	int T;
	
	scanf("%d", &T);
	
	FORU(tc, 1, T) {
		scanf("%d %d %d", &E, &R, &n);
		
		REP(i, n)
			scanf("%d", &v[i]);
		
		memset(dp, -1, sizeof(dp));
		
		printf("Case #%d: %d\n", tc, f(E, 0));
	}
	
	return 0;
}
