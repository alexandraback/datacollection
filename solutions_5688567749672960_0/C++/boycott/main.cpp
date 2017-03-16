#include <assert.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <climits>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

long long dp[1100000];

long long rev(long long x) {
    long long ret = 0;
    while(x > 0) {
        ret = ret * 10 + x % 10;
        x /= 10;
    }
    return ret;
}
 
int main() {
    int cases;
    long long n;
    cin >> cases;
    for (int t = 1; t <= cases; t++)
    {
        cin >> n;
        dp[1] = 1;
        for (long long i = 2; i <= n; i++) {
            if (i % 10 == 0 || rev(i) >= i) dp[i] = dp[i-1] + 1;
            else dp[i] = min(dp[i-1], dp[rev(i)]) + 1;
        }
        printf("Case #%d: %lld\n", t, dp[n]);
    }
    return 0;
}