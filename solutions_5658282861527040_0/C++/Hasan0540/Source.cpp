#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
using namespace std;
typedef long long ll;
inline char bit(int &x, int &i){
	return (x >> i) & 1;
}
int a, b, k;
ll dp[32][2][2][2];
ll calc(int i, bool la, bool lb, bool lk){
	if (i == -1)
		return int(la && lb && lk);
	if (dp[i][la][lb][lk] == -1){
		dp[i][la][lb][lk] = 0;
		for (char x = 0; x < 2;++x)
			for (char y = 0; y < 2; ++y)
				if ((la || x <= bit(a, i)) && (lb || y <= bit(b, i)) && (lk || (x&y) <= bit(k, i)))
					dp[i][la][lb][lk] += calc(i - 1, la || x < bit(a, i), lb || y < bit(b, i), lk || (x&y) < bit(k, i));
	}
	return dp[i][la][lb][lk];
}
int main()
{
	freopen("src.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int kk = 1; kk <= t; ++kk){
		printf("Case #%d: ", kk);
		scanf("%d%d%d", &a, &b, &k);
		memset(dp, -1, sizeof(dp));
		ll res = calc(31, false, false, false);
		printf("%lld\n", res);
	}
	return 0;
}