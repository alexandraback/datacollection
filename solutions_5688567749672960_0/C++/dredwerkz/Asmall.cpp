#define DBG 1

#include <cstring>
#include <map>
#include <unordered_map>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> pii;

int gi() {
    int a;
    scanf("%d", &a);
    return a;
}

ll gli() {
    ll a;
    scanf("%lld", &a);
    return a;
}

int rev(int n) {
    int r = 0;
    while (n) {
        r *= 10;
        r += n%10;
        n /= 10;
    }
    return r;
}

#define SINGLELINE 1
int dp[1000004];

void sett(int i, int v) {
    if (dp[i] == -1) {
        dp[i] = v;
        return;
    }
    dp[i] = MIN(dp[i], v);
}

void solve() {
    int n = gi();
    memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    for (int i = 1; i < n; i++) {
        sett(i+1, dp[i]+1);
        sett(rev(i), dp[i]+1);
    }
    printf("%d\n", dp[n]);
}

int main() {
    int t = gi();

    for (int i = 1; i <= t; i++) {
        printf("Case #%d:%c", i, (SINGLELINE ? ' ' : '\n'));
        solve();
    }

    return 0;
}
