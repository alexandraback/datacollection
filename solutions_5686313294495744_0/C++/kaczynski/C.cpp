#include <set>
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 25;

int T, n, dp[1 << 18];
char a[N], b[N];
string A[N], B[N];
set <string> s1[1 << 17];
set <string> s2[1 << 17];

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s %s", a, b);
            A[i] = string(a);
            B[i] = string(b);
        }
        for (int i = 0; i < (1 << n); i++) {
            dp[i] = 0;
            s1[i].clear();
            s2[i].clear();
        }
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    continue;
                }
                int ni = i | (1 << j);
                s1[ni].insert(A[j]);
                s2[ni].insert(B[j]);
                if (s1[i].count(A[j]) != 0 && s2[i].count(B[j]) != 0) {
                    dp[ni] = max(dp[ni], dp[i] + 1);
                } else {
                    dp[ni] = max(dp[ni], dp[i]);
                }
            }
        }
        printf("Case #%d: %d\n", t, dp[(1 << n) - 1]);
    }

    return 0;

}
