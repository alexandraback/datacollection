#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    int s[1010];
    for (int t = 1; t <= T; ++t) {
        int n;
        scanf("%d", &n);
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &s[i]);
            if (s[i] > mx) mx = s[i];
        }
        int ans = mx;
        for (int eat = 1; eat <= mx; eat++) {
            int cur = eat;
            for (int i = 0; i < n; ++i) {
                int t = (s[i]-1) / eat;
                cur += t;
            }
            if (cur < ans) ans = cur;
        }
        printf("Case #%d: %d\n", t, ans);
    }
}
