#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int f[1000005];

int N;

int reverse(int k) {
    int ret = 0;
    while (k) {
        ret = ret * 10 + (k % 10);
        k /= 10;
    }
    return ret;
}

void dp() {
    memset(f, 0, sizeof(f));
    for (int i = 0; i <= 9; ++ i)
        f[i] = i;
    for (int i = 10; i <= 1000000; ++ i) {
        if (f[i] == 0 || f[i - 1] + 1 < f[i])
            f[i] = f[i - 1] + 1;
        int k = reverse(i);
        if (k <= 1000000 && k > i)
            f[k] = f[i] + 1;
    }
}

int main() {
    int T;
    dp();
    scanf("%d", &T);
    for (int test = 1; test <= T; ++ test) {
        scanf("%d", &N);
        printf("Case #%d: %d\n", test, f[N]);
    }
    return 0;
}
