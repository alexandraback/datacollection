#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 1000000
using namespace std;

int dp[MAX+1];
int num[MAX+1];
void process(){
	int now, n;
	memset(dp,0,sizeof(dp));
	memset(num,0,sizeof(num));

	scanf("%d %d",&now,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	sort(num +1,num+1+n);
	int ans = n;
	if(now == 1){
		printf("%d\n",n);
		return;
	}
	for(int i=1;i<=n ;i++){
		if(num[i] < now){
			now += num[i];
			continue;
		}
		dp[i] ++;
		ans ++;
		now = now*2-1;
		i--;
	}
	for(int i=1;i<=n;i++){
		dp[i] += dp[i-1];
	}
	for(int i=n;i>=0;i--){
		int t = dp[i] + (n-i);
		ans = min(ans,t);
	}
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case #%d: ",i);
		process();
	}
	return 0;
}