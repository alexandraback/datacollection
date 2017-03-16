#include <cstdio>
#include <algorithm>

using namespace std;

const int maxd = 1e3 + 5;

int cases, d, p[maxd];

int solve(int limit) {
    int ret = 0;
    for (int i = 0; i < d; i++) {
        int x = p[i];
        while (x > limit) {
            ret++;
            x -= limit;
        }
    }
    return ret;
}

int main() {
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("B-small-attempt2.out", "w", stdout);

    scanf("%d", &cases);
    int counter = 0;
    while (cases--) {
        counter++;

        int l = 1, r = 0;

        scanf("%d", &d);
        for (int i = 0; i < d; i++) {
            scanf("%d", &p[i]);
            r = max(r, p[i]);
        }

        // assume maximum plate and calculate how many splitting is needed
        // to achieve that maximum
        int sol = r;
        for (int i = l; i < r; i++)
            sol = min(sol, solve(i) + i);

        printf("Case #%d: %d\n", counter, sol);
    }

    return 0;
}
