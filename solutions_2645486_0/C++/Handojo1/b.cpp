#include<cstring>
#include<cstdio>
#include<iostream>

using namespace std;

int dp[2][10],nilai[20],energi,regen,banyak,kasus;

int main() {
    scanf("%d",&kasus);
    for (int l=1;l<=kasus;++l) {
        scanf("%d %d %d",&energi,&regen,&banyak);
        for (int i=1;i<=banyak;++i) scanf("%d",&nilai[i]);
        
        int z = 0;
        for (int i=energi;i>-1;--i) dp[z][i] = nilai[banyak]*i;
        
        for (int i=banyak-1;i>0;--i) {
            dp[1-z][0] = dp[z][min(energi,regen)];
            for (int j=1;j<=energi;++j) {
                int sem = min(energi,j+regen);
                dp[1-z][j] = max(dp[1-z][j-1]+nilai[i],dp[z][sem]);
            }
            z = 1-z;
        }
        
        printf("Case #%d: %d\n",l,dp[z][energi]);
    }
    return 0;
}
