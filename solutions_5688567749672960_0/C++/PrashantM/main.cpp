#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <cstring>
#include <iomanip>
#include <cctype>
#include <map>

using namespace std;

int dp[1000005];

int rv(int n) {
    int a = 0;
    while(n > 0) {
        a = a * 10 + (n % 10);
        n/=10;
    }
    return a;
}
void solve(int t) {
    dp[1] = 1;
    int n; cin>>n;
    for(int i = 2;i <= n;i++) {
        dp[i] = dp[i - 1] + 1;
        if(i % 10 == 0) continue;
        int r = rv(i);
        if(r < i) dp[i] = min(dp[i],dp[r] + 1);
    }
    printf("Case #%d: %d\n",t,dp[n]);
    
}

int main() {
    freopen("/Users/administrator/Desktop/A-small-attempt0.in","r",stdin);
    freopen("/Users/administrator/Desktop/gcjoutput.txt","w",stdout);
    int t; cin>>t;
    for(int i = 1;i <= t;i++) {
        solve(i);
    }
    
}