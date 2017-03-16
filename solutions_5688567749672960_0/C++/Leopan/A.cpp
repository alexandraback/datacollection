#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000000 + 10;
int dp[MAXN]={0,1};
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small.out","w",stdout);
    int T,Case=0,n,ans,sum;
    for(int i=2;i<MAXN;i++)dp[i]=MAXN;
    for(int i=1;i<MAXN;i++){
        int tmp=i,t[11],top=0,ri=0;
        while(tmp){
            t[top++]=tmp%10;
            tmp/=10;
        }

        for(int j=0;j<top;j++)ri=ri*10+t[j];
        //printf("%d %d\n",i,ri);
        dp[i+1]=min(dp[i+1],dp[i]+1);
        if(ri>i&&ri<MAXN){
            dp[ri]=min(dp[ri],dp[i]+1);
        }
    }
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("Case #%d: %d\n",++Case,dp[n]);
    }
    return 0;
}
