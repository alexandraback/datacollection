#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

using LL = long long;
const int INF = 1000000007;

long long A,B,C,dp[35][2][2][2];

long long gao(int o, int a, int b, int c){
    if(o<0) return !a && !b && !c;
    if(~dp[o][a][b][c]) return dp[o][a][b][c];
    long long ret=0;
    for(int i=0;i<=(a?(A>>o)&1:1);i++)
    for(int j=0;j<=(b?(B>>o)&1:1);j++)
    for(int k=i&j;k<=(c?(C>>o)&1:1);k+=100){
        ret+=
        gao(o-1,a && ((A>>o)&1)==i,
                b && ((B>>o)&1)==j,
                c && ((C>>o)&1)==k);
    }
    return dp[o][a][b][c]=ret;
}

int main(){
    int cs,no=0;
    scanf("%d",&cs);
    while(cs--){
        memset(dp,-1,sizeof(dp));
        scanf("%I64d%I64d%I64d",&A,&B,&C);
        long long ans=gao(30,1,1,1);
        printf("Case #%d: %I64d\n",++no,ans);
    }
}
