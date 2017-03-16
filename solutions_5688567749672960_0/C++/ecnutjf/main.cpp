#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
using namespace std;

const int maxn = 1000005;
const int inf  = 0x3f3f3f3f;
const double eps = 1e-8;
typedef long long ll;
int dp[maxn];

int dfs(int x){
    if(x < 0 || x >= maxn)return 0x3f3f3f3f;
    if(dp[x] != -1)return dp[x];
    int xx = x, xxx = 0;
    while(xx){
        xxx = xxx * 10 + xx%10;
        xx = xx / 10;
    }
    //printf("%d %d\n", x, xxx);
    int ans = dfs(x-1) + 1;
    if(x % 10 != 0 && x > xxx)ans = min(ans, dfs(xxx-1)+2);
    dp[x] = ans;
    return ans;
}
void init() {
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    for(int i=0;i<maxn;i++){
        if(dp[i] == -1)dfs(i);
        //printf("%d %d\n", i, dp[i]);
    }
}
int main() {
    int T;
    freopen("in.txt","r",stdin);
    freopen("codejam.txt", "w", stdout);
    init();
    cin >> T;
    int cas = 1;
    while(T --) {
        int n;
        cin >> n;
        printf("Case #%d: %d\n",cas++, dp[n]);
    }
}
