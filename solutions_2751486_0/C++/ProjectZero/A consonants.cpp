#include <cstdio>
#include <cstring>
const int MAXL = 1000005;

int T,L,n;
int dp[MAXL];
char str[MAXL];

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-output0.out","w",stdout);
	
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
				ans += (i-n+1-left)*(L-i+1); // right
				//printf("i = [%d to %d] ans = %lld (%d)(%d)\n",i-n+1,i,ans,(i-n+1-left+1),(L-i+1));
				left = i-n+1;
			}
		}
		/*
		1-3	(1-4...1-8)
		6-8	(1-8...6-8)
		
		1-5
		1-6
		*/
		
		/*for(int i=L;i-n+1>=1;i--){
			if(dp[i]-dp[i-n] == n){
				ans += (i-n+1);
				printf("i = %d ans = %lld (%d)(%d)\n",i,ans,(i-n+1),(L-i+1));
				break;
			}
		}*/
		/*
		12345678
		straight
		1-3,1-4,1-5,1-6,1-7,1-8 = 6
		1-8,2-8,3-8,4-8,5-8,6-8 = 5 
		*/
		printf("%lld\n",ans);
	}
	return 0;
}