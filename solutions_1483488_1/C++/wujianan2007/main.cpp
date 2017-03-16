#include <iostream>
#include <cstdio>
using namespace std;
int a, b;

int dig(int x) {
    int ret = 1;
    while (x >= 10) {
        x /= 10;
        ret *= 10;
    }
    return ret;
}

int calc(int x) {
    int cur = x, ret = 0;
    while (1) {
        cur = (cur / 10) + dig(x)*(cur % 10);
        if (cur == x) break;
        if (cur <= b && cur >= a) ret++;
    }
    return ret;
}

int main() {
    int cas;
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    scanf("%d", &cas);
    for (int cc = 1; cc <= cas; cc++) {
        int ans = 0;
        scanf("%d%d", &a, &b);
        for (int i = a; i <= b; i++)
            ans += calc(i);
        printf("Case #%d: %d\n", cc, ans / 2);
    }
    return 0;
}