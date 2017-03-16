#include <bits/stdc++.h>
using namespace std;

int r, c, w;

int calc(int &len) {
    int cnt = 0;
    while (len > 2 * w - 1) {
        len -= w;
        cnt++;
    }
    cnt++;
    return (cnt - 1) + cnt * (r - 1);
}

void solve(int ca) {
    printf("Case #%d: ", ca);
    scanf("%d %d %d", &r, &c, &w);
    int len = c;
    int res = calc(len);
    if (len == w) res += w;
    else res += w + 1;
    printf("%d\n", res);
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) solve(i + 1);
    return 0;
}
