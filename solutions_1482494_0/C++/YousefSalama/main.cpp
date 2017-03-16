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
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
using namespace std;
int Cases = 1, T, N, a[1005], b[1005], dp[1 << 10][1 << 10];
int calc(int stars, int msk1, int msk2){
    if(stars == 2 * N)return 0;

    if(dp[msk1][msk2] != -1)return dp[msk1][msk2];

    int ans = 1 << 30;
    for(int i = 0; i < N; i++){
        if(stars >= b[i]){
            if(!(msk1 & (1 << i)))ans = min(ans, calc(stars + 2, msk1 | (1 << i), msk2 | (1 << i)) + 1);
            else if(!(msk2 & (1 << i)))ans = min(ans, calc(stars + 1, msk1, msk2 | (1 << i)) + 1);
        }else if(stars >= a[i]){
            if(!(msk1 & (1 << i)))ans = min(ans, calc(stars + 1, msk1 | (1 << i), msk2) + 1);
        }
    }
    return dp[msk1][msk2] = ans;
}
int main(){
    freopen("a.out", "w", stdout);

    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++)
            cin >> a[i] >> b[i];

        memset(dp, -1, sizeof dp);
        int ans = calc(0, 0, 0);

        if(ans == 1 << 30)printf("Case #%d: Too Bad\n", Cases++);
        else printf("Case #%d: %d\n", Cases++, ans);
    }
    return 0;
}