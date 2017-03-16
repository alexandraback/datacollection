#include<bits/stdc++.h>
using namespace std;
long long reverse(long long x){
   while(x%10==0)
      x/=10;
   
   int rx=0;
   while(x!=0){
      rx*=10;
      rx+=(x%10);
      x/=10;
   }
   return rx;
}
int dp[1000010];
int main(){
   int t;
   for(int i=1;i<1000010;i++)
      dp[i]=1000011;
   
   int ile=1;
   for(int i=1;i<=1000000;i++){
      dp[i]=min(dp[i],ile);
      ile=dp[i];
      int ri=reverse(i);
      dp[ri]=min(dp[ri],ile+1);
      ile++;
   }
   //for(int i=1;i<=25;i++)
     // printf("%d: %d\n",i,dp[i]);
   scanf("%d",&t);
   for(int i=1;i<=t;i++){
      int n;
      scanf("%d",&n);
      printf("Case #%d: %d\n",i,dp[n]);
   }
   return 0;
}