#include <bits/stdc++.h>

using namespace std;

int r, c, w;

int solve(int rr, int cc, int ww) {
    if (cc == ww) return c;
    if ((double)ww >= ceil((double)cc/(double)2)) return ww + 1;
    return 1 + solve(rr, cc - ww, ww);
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    scanf("%d", &t);
    for (int z = 1; z <= t; z++) {
        scanf("%d %d %d", &r, &c, &w);
        printf("Case #%d: %d\n", z, solve(r, c, w));
    }


    return 0;
}
