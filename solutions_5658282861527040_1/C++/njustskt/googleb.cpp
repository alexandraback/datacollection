/*************************************************************************
    > File Name: googleb.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年05月03日 星期六 23时55分35秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MAXN 50
int Cas = 1, t;
LL a, b, k, dp[MAXN][2][2][2];
LL gao(int len, int a1, int b1, int limit)
{
	if (len == -1) return 1;
	if (dp[len][a1][b1][limit] != -1) {
		return dp[len][a1][b1][limit];
	}
	int ac = (a1 == 0) ? 1 : ((a & (1 << len)) ? 1 : 0);
	int bc = (b1 == 0) ? 1 : ((b & (1 << len)) ? 1 : 0);
	int l = (k & (1 << len)) ? 1 : 0;
	LL ans = 0;
	for (int i = 0; i <= ac; i ++) {
		for (int j = 0; j <= bc; j ++) {
			if (limit == 1 && ((i & j) > l)) continue;
			ans += gao(len - 1, a1 && (i == ac), b1 && (j == bc), limit && ((i & j) == l));
		}
	}
	dp[len][a1][b1][limit] = ans;
	return ans;
}
void work()
{
	printf("Case #%d: ", Cas ++);
	cin >> a >> b >> k;
	memset(dp, -1, sizeof(dp));
	a --, b --, k --;
	cout << gao(30, 1, 1, 1) << endl;
}
int main()
{
	scanf("%d", &t);
	while (t --) {
		work();
	}
	return 0;
}
