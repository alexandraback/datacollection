#include <bits/stdc++.h>
using namespace std;

char s[110];

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%s", s);
        int cnt = 0, n = strlen(s);
        for (int i = 0; i < n; i++) {
            if (i == 0 || s[i] != s[i - 1]) {
                cnt++;
            }
        }
        printf("Case #%d: %d\n", cas, s[n - 1] == '+' ? cnt - 1 : cnt);
        fprintf(stderr, "%d\n", s[n - 1] == '+' ? cnt - 1 : cnt);
    }
    return 0;
}