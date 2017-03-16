#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <algorithm>

#define sz(a) int((a).size())
#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define all(c) (c).begin(),(c).end()
#define INF 2000000000
#define EPS 1e-5
#define PB push_back
#define MP make_pair
#define S second
#define F first
#define X first
#define Y second
#define DEBUG(x) printf("debugging.. %d\n", x);
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

int T, n, a[15], b[15];
int dp[1 << 10][1 << 10];

int f(int ms1, int ms2) {
	if(ms2 == (1 << n)-1) return 0;
	
	int &ret = dp[ms1][ms2];
	if(ret != -1) return ret;
	
	ret = INF;
	
	int star = 0;
	for(int i = 0; i < n; ++i)
		if(ms2 & (1 << i))		star += 2;
		else if(ms1 & (1 << i))	star += 1;
	
	for(int i = 0; i < n; ++i) {
		if(!(ms2 & (1 << i)) && star >= b[i])
			ret = min(ret, f(ms1, ms2 | (1 << i)) + 1);
		
		if(!(ms2 & (1 << i)) && !(ms1 & (1 << i)) && star >= a[i])
			ret = min(ret, f(ms1 | (1 << i), ms2) + 1);
	}
	
	return ret;
}

int main() {
	scanf("%d", &T);
	
	for(int tc = 0; tc < T; ++tc) {
		printf("Case #%d: ", tc + 1);
		
		scanf("%d", &n);
		
		for(int i = 0; i < n; ++i)
			scanf("%d%d", &a[i], &b[i]);
			
		memset(dp, -1, sizeof(dp));
		int ans = f(0, 0);
		
		if(ans == INF) 	printf("Too Bad\n");
		else			printf("%d\n", ans);
	}
	
	return 0;
}
