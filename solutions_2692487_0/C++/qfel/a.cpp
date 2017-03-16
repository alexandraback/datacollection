#include <stdio.h>
#include <algorithm>

int solve() {
    static int T[100];
    int n;
    long long a;
    scanf("%lld %d", &a, &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &T[i]);
    if (a == 1)
        return n;

    std::sort(T, T + n);
    int w = n, c = 0;
    for (int i = 0; i < n; i++) {
        w = std::min(w, c + n - i);
        while (T[i] >= a) {
            a += a - 1;
            c++;
        }
        a += T[i];
    }

    return std::min(w, c);
}

int main() {
    int n;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++)
        printf("Case #%d: %d\n", i, solve());
    return 0;
}
