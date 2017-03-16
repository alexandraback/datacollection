#include <cmath>
#include <cstdio>

using namespace std;

const int maxn = 10000000+ 5;

int E, R, N;

long long arr[maxn];
long long* dp1;
long long* dp2;

long long max(long long a, long long b) {
    return a > b ? a : b;
}

long long solve() {
    int n = N - 1;
    // for arr[n]
    for (int e = 0; e <= E; ++e) {
        dp2[e] = e * arr[n];
    }
    while (--n >= 0) {
        long long* tmp = dp2;
        dp2 = dp1;
        dp1 = tmp;
        for (int e = 0; e <= E; ++e) {
            dp2[e] = 0;
            int x = e + R - E;
            if (x < 0) x = 0;
            if (x > e) x = e;
            for (; x <= e; ++x) {
                dp2[e] = max(dp2[e], x * arr[n] + dp1[e - x + R]);
            }
        }
    }
    return dp2[E];
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B.txt", "w", stdout);

    int T;
    int cs = 1;

    dp1 = new long long[maxn];
    dp2 = new long long[maxn];

    scanf("%d", &T);
    while (T--){
        scanf("%d%d%d", &E, &R, &N);
        for (int i = 0; i < N; ++i){
            scanf("%lld", &arr[i]);
        }
        printf("Case #%d: %lld\n", cs++, solve());
    }

    delete dp1;
    delete dp2;

    return 0;
}
