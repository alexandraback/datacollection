#include <bits/stdc++.h>

using namespace std;

int t;
int n;
char a[25][25], b[25][25];
bool fake[25];

int main() {
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small.out", "w", stdout);

    scanf("%d", &t);
    for (int tp=1; tp<=t; tp++) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%s", a[i]);
            scanf("%s", b[i]);
        }
        int sol = 0;

        for (int mask=0; mask<(1<<n); mask++) {
            int num = 0;
            for (int i=0; i<n; i++) {
                if (mask & (1<<i)) {
                    fake[i] = true;
                    num++;
                }
                else fake[i] = false;
            }
            if (num <= sol) continue;
            bool ok = true;
            bool first, second;
            for (int i=0; i<n; i++) {
                if (!fake[i]) continue;
                first = second = false;
                for (int j=0; j<n; j++) {
                    if (fake[j]) continue;
                    if (strcmp(a[i], a[j]) == 0) first = true;
                    if (strcmp(b[i], b[j]) == 0) second = true;
                    if (first && second) break;
                }
                if (!first || !second) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                sol = num;
            }
        }
        printf("Case #%d: ", tp);
        printf("%d\n", sol);
    }


    return 0;
}
