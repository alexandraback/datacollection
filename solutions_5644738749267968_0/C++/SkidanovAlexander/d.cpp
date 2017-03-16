#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
double a[105], b[105];

int main() {
    int t = 1, tt;
    for (scanf("%d", &tt); t <= tt; ++ t) {
        scanf("%d", &n);

        int war = 0, dwar=  0;
        for (int i = 0; i < n; ++ i) {
            scanf("%lf", &a[i]);
        }
        for (int i = 0; i < n; ++ i) {
            scanf("%lf", &b[i]);
        }
        sort(a, a + n);
        sort(b, b + n);
        int idx = 0;
        for (int i = 0; i < n; ++ i) {
            if (a[i] > b[idx]) { ++ dwar; ++ idx; }
        }

        for (int i = 0; i < n; ++ i) {
            int cand = 0;
            for (int j = 0; j < n; ++ j) {
                if (b[cand] == -1 || (b[cand] < a[i] && b[j] > a[i])) {
                    cand = j;
                }
            }
            if (b[cand] < a[i]) ++ war;
            b[cand] = -1;
        }

        printf("Case #%d: ", t);
        printf("%d %d\n", dwar, war);
        printf("\n");
    }
    return 0;
}

