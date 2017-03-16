#include <cstdio>
#include <iostream>
#include <vector>

bool check(int &msk, int val) {
    for (; val; val /= 10) {
        msk |= 1 << (val % 10);
    }
    if (msk == (1 << 10) - 1) {
        return true;
    }
    return false;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        int v;
        scanf("%d", &v);
        if (v == 0) {
            printf("Case #%d: INSOMNIA", i);
        } else {
            for (int j = v, k = 0; ; j += v) {
                if (check(k, j)) {
                    printf("Case #%d: %d", i, j);
                    break;
                }
            }
        }
        if (i + 1 <= t) {
            printf("\n");
        }
    }
    return 0;
}
