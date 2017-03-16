#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


double dp[3000][1000];
bool ok(int remain,int y,int cnt) {
	if (y > cnt) return false;
	if (remain - y > cnt) return false;
	return true;
}
double func(int x,int y,int remain,int cnt) {
	if (x < 0) {
		if (y - x <= 2 * cnt) {
			return 1.0;
		}
		if (y - x > 2 * cnt + 2) {
			return 0.0;
		}
	} else {
		if (x + y <= 2 * cnt) {
			return 1.0;
		}
		if (x + y > 2 * cnt + 2) {
			return 0.0;
		}
	}
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	y ++;
	for (int i = 0 ; i < remain ; i ++) {
		for (int j = 0 ; j < y ; j ++) {
			if (dp[i][j] == 0) continue;
			int c = 0;
			if (ok(i+1,j+1,cnt*2+2)) c ++;
			if (ok(i+1,j,cnt*2+2)) c++;
			if (ok(i+1,j+1,cnt*2+2)) dp[i+1][j+1] += dp[i][j] / c;
			if (ok(i+1,j,cnt*2+2)) dp[i+1][j] += dp[i][j] / c;
		}
		dp[i+1][y] += dp[i][y];
	}
	return dp[remain][y];
}

int main() {
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int T , cas = 1;
	scanf("%d",&T);
	while (T --) {
		int n , x , y;
		scanf("%d%d%d",&n,&x,&y);
		int total = 0;
		int cnt = -1;
		for (int i = 1 ;; i += 4) {
			total += i;
			if (total > n) {
				total -= i;
				break;
			}
			cnt ++;
		}
		printf("Case #%d: %.10lf\n",cas ++ , func(x,y,n-total,cnt));
	}
	return 0;
}
