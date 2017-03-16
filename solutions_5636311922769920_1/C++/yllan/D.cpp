#include <cstdio>
#include <algorithm>

using namespace std;

void solve(int k, int c, int s, int t)
{
    if (c * s < k) {
        printf("Case #%d: IMPOSSIBLE\n", t);
    } else {
        printf("Case #%d:", t);
        for (long long x = 0; x < k; x += c) {
            long long sum = 0LL;
            long long power[100];
            power[0] = 1LL;
            for (int i = 1; i < c; i++) {
                power[i] = power[i - 1] * k;
            }
            for (long long w = 0; w < c && x + w < k; w++) {
                sum += (x + w) * power[c - w - 1];
            }
            printf(" %lld", sum + 1LL);
        }
        puts("");
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int k, c, s;
        scanf("%d %d %d", &k, &c, &s);
        solve(k, c, s, t);
    }    
}