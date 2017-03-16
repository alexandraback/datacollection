#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

int K, C, S;

int main() {
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; ++tc) {
        printf("Case #%d:", tc);
        scanf("%d%d%d", &K, &C, &S);
        int x = K / C;
        if (K % C != 0) x++;
        if (x > S) {
            printf(" IMPOSSIBLE\n");
            continue;
        }
        for (int i = 0; i < K; i += C) {
            long long tmp = 1;
            for (int j = 1; j <= C; ++j) {
                tmp = (tmp - 1) * K + min(i + j, K);
            }
            printf(" %lld", tmp);
        }
        printf("\n");
    }
}