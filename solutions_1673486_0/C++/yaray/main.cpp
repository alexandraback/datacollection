#include <algorithm>
#include <cstdio>
#include <functional>
#include <numeric>
using namespace std;

double p[100001], dp[100001];

int main()
{
    int T, A, B;
    scanf("%d\n", &T);
    for (int tt = 1; tt <= T; ++tt) {
        scanf("%d%d", &A, &B);
        for (int i = 0; i < A; ++i)
            scanf("%lf", &p[i]);
        dp[0] = B+1;
        double ac = 1;
        for (int i = 1; i <= A; ++i) {
            ac *= p[i-1];
            dp[i] = B+2; // enter
            dp[i] = min(dp[i], ac * (1+B-i) + (1-ac) * (1+B-i + 1+B)); // keep
            dp[i] = min(dp[i], 1 + dp[i-1]); // backspace
        }
        printf("Case #%d: %lf\n", tt, dp[A]);
    }
}
