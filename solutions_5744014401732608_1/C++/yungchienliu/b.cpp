#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;

#define S second
#define F first
#define mp make_pair
typedef pair<int, int> PII;
#define pb push_back
typedef long long ll;

int m[60][60];

int dp[100];

int N;

int f(int x){
	if(dp[x]!=-1) return dp[x];
	int res = 0;
	for(int i = 0; i < N; ++i){
		if(m[x][i]) res += f(i);
	}
	return dp[x] = res;
}

int main () {
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; ++tt){
		memset(m, 0, sizeof(m));
		int x;
		ll y;
		scanf("%d%lld", &x, &y);
		if(y > (1LL<<(x-2))) {
			printf("Case #%d: IMPOSSIBLE\n", tt);
			continue;
		}
		else printf("Case #%d: POSSIBLE\n", tt);
		m[0][x-1] = 1;
		for(int i = 1; i < x-1; ++i){
			m[i][x-1] = 1;
			for(int j = 1; j < i; ++j) m[i][j] = 1;
		}
		--y;
		for(int i = 0; (1LL<<i) <= y; ++i){
			if((1LL<<i) & y) m[0][i+1] = 1;
		}
		for(int i = 0; i < x; ++i){
			for(int j = 0; j < x; ++j) printf("%d", m[i][j]);
			puts("");
		}
		// memset(dp, -1, sizeof(dp));
		// dp[x-1] = 1;
		// N = x;
		// int ans = f(0);
		// cout << "CC" << ans <<endl;
		// if(ans != y+1) puts("XXXXXXXDDDDDDDDD");
	}
}