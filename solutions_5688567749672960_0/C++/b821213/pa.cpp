#include <stdio.h>
#include <queue>
#define MAXN 1000000

int dp[MAXN+1];

int rev1(int n){
	while( n % 10 == 0 )
		n /= 10;
	return n;
}
int rev2(int n){
	int ret = 0;
	while( n ){
		int tmp = n % 10;
		n /= 10;
		ret = ret * 10 + tmp;
	}
	return ret;
}

int main(){
	dp[1] = 1;
	for(int i=2;i<=MAXN;++i)
		dp[i] = 2147483647;
	std::queue<int> q;
	q.push(1);
	while( !q.empty() ){
		int now = q.front();
		q.pop();
		int t[3] = {rev1(now), rev2(now), now+1};
		for(int i=0;i<3;++i)
			if( t[i] <= MAXN && t[i] > 0 &&
				dp[now] + 1 < dp[t[i]] ){
				dp[t[i]] = dp[now]+1;
				q.push(t[i]);
			}
	}
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t){
		int n;
		scanf("%d",&n);
		printf("Case #%d: %d\n", t, dp[n]);
	}
	return 0;
}