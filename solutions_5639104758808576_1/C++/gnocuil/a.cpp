#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    char s[1010];
    for (int t = 1; t <= T; ++t) {
        int m;
        scanf("%d %s\n", &m, s);
        int ans = 0;
        int tot = 0;
        for (int i = 0; i <= m; ++i) {
            if (tot < i) {
                int delta = i - tot;
                tot += delta;
                ans += delta;
            }
            tot += s[i] - '0';
        }
        printf("Case #%d: %d\n", t, ans);
    }
}
