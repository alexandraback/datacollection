#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;
int t,n,a;
long long dp[1000010];
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    dp[1] = 1;
    for(int i = 0; i <= 1000000; i++) dp[i] = i;
    for(int i = 1; i <= 1000000; i++){
        dp[i] = min(dp[i],dp[i-1]+1);
        stringstream ss;
        ss << i;
        string s = ss.str();
        reverse(s.begin(),s.end());
        sscanf(s.c_str(),"%lld",&a);
        dp[a] = min(dp[a],dp[i]+1);
    }
    scanf("%d",&t);
    for(int i = 1; i <= t; i++){
        scanf("%d",&n);
        printf("Case #%d: %lld\n",i,dp[n]);
    }
}