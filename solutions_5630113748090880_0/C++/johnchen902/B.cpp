#include <stdio.h>
#include <algorithm>

bool yes[2500];

void solve() {
    std::fill_n(yes, 2500, false);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n * (2 * n - 1); i++) {
        int x;
        scanf("%d", &x);
        yes[x - 1] ^= true;
    }
    for(int i = 0; i < 2500; i++)
        if(yes[i])
            printf(" %d", i + 1);
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        printf("Case #%d:", i);
        solve();
        printf("\n");
    }
}

