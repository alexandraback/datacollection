#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int n; char s[1005];
        scanf("%d%s", &n, s);
        int ans = 0, sum = 0;
        for (int i = 0; i <= n; i++) {
            if (sum < i) {
                ans += i - sum;
                sum = i;
            }
            sum += s[i] - '0';
        }
        printf("Case #%d: %d\n", cas, ans);
    }
}
