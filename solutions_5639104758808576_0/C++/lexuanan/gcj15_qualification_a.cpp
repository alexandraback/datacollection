#include <bits/stdc++.h>

char s[1005];

int main() {
    //freopen("A-small-attempt0.in", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int ct;
    scanf("%d", &ct);
    for (int nt = 1; nt <= ct; nt++) {
        int n;
        scanf("%d", &n);
        scanf("%s", s);
        int res = 0;
        int tmp = 0;
        for (int i = 0; i <= n; i++) {
            if (tmp < i) {
                res += i-tmp;
                tmp = i;
            }
            tmp += s[i]-'0';
        }
        printf("Case #%d: %d\n", nt, res);
    }
    return 0;
}
