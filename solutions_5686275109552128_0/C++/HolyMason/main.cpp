#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <bitset>
#define INF 0x3f3f3f3f
#define eps 1e-8
#define FI first
#define SE second
using namespace std;
typedef long long LL;
int n, a[1005];

int solve(int maxp) {
    int res = maxp;
    for(int i = 0; i < n; ++i) {
        if(a[i] <= maxp) continue;
        res += (a[i] - 1) / maxp;
    }
    return res;
}

int main() {
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%d", a + i);
        int maxp = 0;
        for(int i = 0; i < n; ++i) maxp = max(maxp, a[i]);
        int ans = INF;
        for(int i = maxp; i >= 1; --i) ans = min(ans, solve(i));
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}
