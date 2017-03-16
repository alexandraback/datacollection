#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void Solve(int test_num) {
    printf("Case #%d: ", test_num);
    int k, c, s; scanf("%d%d%d", &k, &c, &s);
    if (c * s < k) {
        printf("IMPOSSIBLE\n");
        return;
    }
    for (int i = 0; i < k;) {
        ll num = 0;
        for (int j = 0; j < c; ++j, ++i) {
            num *= k;
            num += min(i, k - 1);
        }
        printf("%Ld ", num + 1);
    }
    printf("\n");
}

int main() {
    freopen("D.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solve(i);
}
