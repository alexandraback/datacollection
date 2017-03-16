#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int T, N; // SHOULD BE LONG LONG IN LARGE CASE
int best[1010101];

int reverse(int x) {
    int rev = 0;
    while (x) {
        rev = 10 * rev + x % 10;
        x /= 10;
    }
    return rev;
}

int main() {
    for (int i = 0; i <= 1000000; ++i) {
        if (best[i + 1] == 0) {
            best[i + 1] = best[i] + 1;
        } else {
            best[i + 1] = min(best[i + 1], best[i] + 1);
        }

        int rev = reverse(i);
        if (rev > i && best[rev] == 0) {
            best[rev] = best[i] + 1;
        } else if (rev > i) {
            best[rev] = min(best[rev], best[i] + 1);
        }
    }

    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d", &N);
        printf("Case #%d: %d\n", t, best[N]);
    }

    return 0;
}
