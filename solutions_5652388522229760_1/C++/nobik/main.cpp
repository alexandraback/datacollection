#include <iostream>

using namespace std;

const int maxN = 100000005;

int mask[maxN];

int calc(int x) {
    int result = 0;
    while (x > 0) {
        int last = x % 10;
        result |= (1 << last);
        x /= 10;
    }
    return result;
}

void Solve() {
    int n;
    scanf("%d", &n);
    int result = 0;
    int i;
    for (i = 1; i <= 100; ++i) {
        result |= calc(n * i);
        if (result == 1023) break;
    }
    if (result != 1023) {
        printf("INSOMNIA\n");
    } else {
        printf("%d\n", n * i);
    }
}

int main() {
    for (int i = 0; i < maxN; ++i) {
        mask[i] = calc(i);
    }
    int z; scanf("%d", &z);
    for (int i = 0; i < z; ++i) {
        printf("Case #%d: ", i + 1);
        Solve();
    }
    return 0;
}
