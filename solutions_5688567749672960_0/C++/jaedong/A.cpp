#include <cstdio>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 1e6 + 1;
int dp[MAXN];

int reverse(int i) {
    int r = 0;
    while (i) {
        r = r * 10 + i % 10;
        i /= 10;
    }
    assert(r);
    return r;
}

void pre() {
    dp[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        dp[i] = dp[i - 1] + 1;
        int r = reverse(i);
        if (i % 10 and r < i)
            dp[i] = min(dp[i], dp[r] + 1);
    }
}

int main() {
    pre();
    int cases;
    scanf("%d", &cases);
    for (int cs = 1; cs <= cases; cs++) {
        long long n;
        scanf("%lld", &n);
        printf("Case #%d: %d\n", cs, dp[n]);
    }
}
