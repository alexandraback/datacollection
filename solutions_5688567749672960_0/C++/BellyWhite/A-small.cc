#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int f[N];

int reverse(int x) {
    int y = 0;
    while (x) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    return y;
}
int main() {
    for (int i = 0; i < N; ++i) f[i] = i;
    for (int i = 1; i < N - 1; ++i) {
        int j = reverse(i);
        if (j > i && j < N) f[j] = min(f[j], f[i] + 1);
        f[i + 1] = min(f[i + 1], f[i] + 1);
    }
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        int n;
        scanf("%d", &n);
        printf("Case #%d: %d\n", cas, f[n]);
    }
}
