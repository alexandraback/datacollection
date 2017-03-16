#include <cstdio>
#include <cstring>
const int MAXL = 1000005;

int T,L,n;
int dp[MAXL];
char str[MAXL];

int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	
	scanf("%d",&T);
	for(int _i=1;_i<=T;_i++){
		printf("Case #%d: ",_i);
		
		scanf("%s %d",&str[1],&n);
		L = strlen(&str[1]);
		for(int i=1;i<=L;i++){
			if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') dp[i] = 0;
			else dp[i] = 1;
		}
		for(int i=1;i<=L;i++) dp[i] += dp[i-1];
		//for(int i=1;i<=L;i++) printf("[%d]",dp[i]);
		//printf("\n");
		
		int left=0,right;
		long long ans=0;
		for(int i=n;i<=L;i++){
			if(dp[i]-dp[i-n] == n){
				ans += (long long)(i-n+1-left)*(long long)(L-i+1); // right
				left = i-n+1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}