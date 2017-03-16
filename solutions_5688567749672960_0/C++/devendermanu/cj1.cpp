#include<stdio.h>
int reverse(int n){
    int rev=0;
    while(n){
     rev=rev*10 + n%10;
     n/=10;
    }
    return rev;
}
int dp[1000001];
int main(){
    int t,x,n,i,rev;
    dp[1]=1;
    for(i=2;i<1000001;i++){
     if(dp[i]==0||dp[i]>dp[i-1])
      dp[i]=dp[i-1]+1;
     rev=reverse(i);
     if(dp[rev]==0)
      dp[rev]=dp[i]+1;
     //printf("%d -- %d\n",i,dp[i]);
    }
    scanf("%d",&t);
    for(x=1;x<=t;x++){
     scanf("%d",&n);
     printf("Case #%d: %d\n",x,dp[n]);
    }
    return 0;
}
