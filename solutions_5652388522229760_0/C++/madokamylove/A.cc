#include <bits/stdc++.h>
using namespace std;

int res[1000010];

void setDigit(int &s, int cur) {
    while (cur > 0) {
        s |= 1 << (cur % 10);
        cur /= 10;
    }
}

void init() {
    res[0] = -1;
    for (int i = 1; i <= 1000000; i++) {
        int s = 0;
        int cur = i;
        while (true) {
            setDigit(s, cur);
            if (s == (1 << 10) - 1) {
                break;
            }
            cur += i;
        }
        res[i] = cur;
    }
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    init();
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int n;
        scanf("%d", &n);
        if (res[n] == -1) {
            printf("Case #%d: INSOMNIA\n", cas);
            fprintf(stderr, "INSOMNIA\n");
        } else {
            printf("Case #%d: %d\n", cas, res[n]);
            fprintf(stderr, "%d\n", res[n]);
        }
    }
    return 0;
}