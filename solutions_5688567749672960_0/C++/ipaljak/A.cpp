#include <algorithm>
#include <cstdio>


typedef long long llint;

using namespace std;

int T;

llint N;
llint dp[1000010];

llint rev_dig(llint x) {

    int ret = 0;
    while (x > 0) {
        ret *= 10; ret += x % 10;
        x /= 10;
    }

    return ret;

}

void solve(int t) {

    scanf("%lld", &N);

    dp[1] = 1;
    for (int i = 2; i <= N; ++i) {
        int rev_i = (int) rev_dig(i);
        dp[i] = dp[i - 1] + 1;
        if (rev_i < i && (int) rev_dig(rev_i) == i) dp[i] = min(dp[i], dp[rev_i] + 1);
    }

    printf("Case #%d: %lld\n", t, dp[N]);

}

int main(void) {

    scanf("%d", &T);
    for (int i = 0; i < T; ++i) solve(i + 1);

    return 0;

}
