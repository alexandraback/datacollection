#include <bits/stdc++.h>

using namespace std;

#define INF 10000000

int dp[1000001];

int reverse(int n){
    int r = 0;
    while(n){
        r = r*10 + n%10;
        n /= 10;
    }
    return r;
}

void init(){
    fill(dp, dp+1000001, INF);
    dp[1] = 1;
    for(int i=2; i<1000001; i++) {
        dp[i] = min(dp[i-1]+1, dp[i]);
        int r = reverse(i);
        if(r >= 1 && r < 1000001){
            dp[r] = min(dp[r], dp[i]+1);
        }
    }
}

int main(){
    
    init();
    int T, n;
    scanf("%d", &T);
    
    for(int qq = 1; qq <= T; qq++) {
        scanf("%d", &n);
        printf("Case #%d: %d\n", qq, dp[n]);
    }
    
    return 0;
}