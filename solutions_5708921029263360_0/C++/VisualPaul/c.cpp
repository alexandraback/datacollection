#include <bits/stdc++.h>

int l[3][100][100];

void solve() {
    std::vector<std::array<int, 3>> res;
    int j, p, s, k;
    scanf("%d%d%d%d", &j, &p, &s, &k);
    printf("%d\n", j * p * std::min(k, s));
    for (int i = 0; i < k && i < s; ++i) {
        for (int a = 1; a <= j; ++a) {
            int shift = ((a - 1) + i) % s;
            for (int b = 1; b <= p; ++b) {
                int c = (b - 1 + shift) % s + 1;
                printf("%d %d %d\n", a, b, c);
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
    }
}
