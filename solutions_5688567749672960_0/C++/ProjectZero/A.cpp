/*
1-2-3-4-5-6-7-8-9-10-11-12-13-14-15-16-17-18-19-91->99->100->109 => 901 => 919 => 991 => 999 => 1009
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 1e6;
int dp[MAXN+100];

long long N;
char str[20];
long long reverse(int vv){
	if(vv%10 == 0) return vv;

	sprintf(str,"%d",vv);
	int len = strlen(str);

	long long val = 0LL;
	for(int i=len-1;i>=0;i--){
		val *= 10LL;
		val += (long long)(str[i]-'0');
	}
	return val;
}

void run(int testcase){
	scanf("%lld",&N);

	for(int i=0;i<MAXN;i++) dp[i] = INF;
	dp[0] = 0;
	for(int i=1;i<MAXN;i++){
		dp[i] = min(dp[i],dp[i-1] + 1);
		dp[i] = min(dp[i],dp[reverse(i)]+1);
		// printf("dp[%d] = %d\n",i,dp[i]);
	}
	dp[MAXN] = dp[MAXN-1] + 1;
	printf("Case #%d: %d\n",testcase,dp[N]);
}

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int T; scanf("%d",&T);
	for(int i=1;i<=T;i++) run(i);
	return 0;
}