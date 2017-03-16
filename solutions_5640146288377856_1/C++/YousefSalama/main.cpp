//In the name of Allah

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
using namespace std;

int T, R, C, W;

int dp[55];
int one_row(int N){
    if(N == W)return W;
    if(dp[N] != -1)return dp[N];
    
    int res = 1 << 30;
    for(int i = 0; i < N; i++){
        int p1 = i, p2 = N - i - 1;
        
        int cur = 1 << 30;
        if((p1 >= W) || (p2 >= W)){
            if(p2 >= W)cur = min(cur, 1 + p1 / W + one_row(p2));
            if(p1 >= W)cur = min(cur, 1 + p2 / W + one_row(p1));
        }else{
            cur = min(cur, W + 1);
        }
        res = min(res, cur);
    }
    return dp[N] = res;
}
int cnt;
int main(){
    freopen("A.txt", "r", stdin);
    freopen("Aout.txt", "w", stdout);

    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &R, &C, &W);
        
        memset(dp, -1, sizeof dp);
        printf("Case #%d: %d\n", ++cnt, (R - 1) * (C / W) + one_row(C));
    }
    return 0;
}