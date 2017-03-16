#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 1005;

void solve() {
    int n;
    int a[MAX_N];
    int b[MAX_N];
    int have[MAX_N] = {};

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }

    int stars = 0;
    int rounds = 0;
    for (int _ = 0; _ < 2*n; _++) {
        int c = -1;
        int crew = -1;
        for (int i = 0; i < n; i++) {
            if (b[i] <= stars && have[i] < 2) {
                int rew = 2 - have[i];

                if (rew > crew) {
                    // printf(">> Trying %d %d for lvl %d vs clvl %d of %d %d\n", a[i], b[i], lvl, clvl, a[c], b[c]);
                    c = i;
                    crew = rew;
                }
            }
        }

        if (c != -1) {
            // printf("Using lvl %d of %d %d for %d stars\n", have[c] + crew, a[c], b[c], crew);
            stars += crew;
            have[c] = 2;
            rounds++;
            continue;
        }

        for (int i = 0; i < n; i++) {
            if (a[i] <= stars && have[i] == 0) {
                // printf(">> Trying %d %d for lvl %d vs clvl %d of %d %d\n", a[i], b[i], lvl, clvl, a[c], b[c]);
                if (c == -1 || b[c] < b[i]) {
                    c = i;
                    crew = 1;
                }
            }
        }

        if (c == -1) {
            break;
        }
        // printf("Using lvl %d of %d %d for %d stars\n", have[c] + crew, a[c], b[c], crew);
        stars += crew;
        have[c] = 1;
        rounds++;
    }

    if (stars == 2*n) {
        printf("%d\n", rounds);
    } else {
        printf("Too Bad\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Case #%d: ", i+1);
        solve();
    }

    return 0;
}
