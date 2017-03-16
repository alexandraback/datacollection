#include <bits/stdc++.h>

int d[1005];

int main() {
    //freopen("B-small-attempt0.in", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int ct;
    scanf("%d", &ct);
    for (int nt = 1; nt <= ct; nt++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", d+i);
        int res = 1000;
        for (int i = 1; i <= 1000; i++) {
            int tmp = i;
            for (int j = 0; j < n; j++) {
                if (d[j] % i == 0) tmp += (d[j]/i-1);
                else tmp += d[j]/i;
            }
            if (tmp < res) res = tmp;
        }
        printf("Case #%d: %d\n", nt, res);
    }
    return 0;
}
