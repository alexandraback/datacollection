#include <bits/stdc++.h>

#define SZ 1010

int sum[SZ];
char s[SZ];

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("2.txt", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int n;
        scanf("%d %s", &n, s);

        int ans = 0;
        sum[0] = s[0] - '0';

        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i-1];
            if (s[i] != '0' && sum[i] < i) {
                ans += i - sum[i];
                sum[i] = i;
            }
            sum[i] += s[i] - '0';
        }

        printf("Case #%d: %d\n", cs + 1, ans);
    }

    return 0;
}

