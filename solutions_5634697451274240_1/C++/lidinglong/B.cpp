#include <bits/stdc++.h>
#define MAXN 110

using namespace std;

char st[MAXN];

int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        printf("Case #%d: ", ca);
        scanf("%s", st);
        int len = strlen(st);
        int lim = len - 1;
        for (; st[lim] == '+' && lim >= 0; --lim);
        if (lim < 0) {
            printf("0\n");
            continue;
        }
        char flag = st[0];
        int ans = 1;
        for (int i = 1; i <= lim; ++i) {
            if (st[i] != flag) ans++;
            flag = st[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}