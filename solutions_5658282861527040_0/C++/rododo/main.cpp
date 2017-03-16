#include <cstdio>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T, TC;
    scanf("%d", &T);
    TC = T;
    while (TC--) {
        int A, B, K;
        long long ans = 0;
        scanf("%d%d%d", &A, &B, &K);
        for (int i = 0; i < A; i++)
            for (int j = 0; j < B; j++)
                if ((i & j) < K)
                    ans++;
        printf("Case #%d: %lld\n", T - TC, ans);
    }
}