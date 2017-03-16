#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

int main() {/*
    freopen("D:\\B-small-attempt1.in", "r", stdin);
    freopen("D:\\B-small-attempt1.out", "w", stdout);*/
    static int s[105];
    int tc, n, k, p, c = 0;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d%d", &n, &k, &p);
        for (int i = 0; i < n; i++)
            scanf("%d", s + i);
        sort(s, s + n, greater<int>());
        int tot = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] >= p + p - 1 + p - 1 && p > 0 || s[i] >= p + p + p)
                tot++;
            else if (k && s[i] >= p + p - 2 + p - 2 && p >= 2)
                tot++, --k;
            else
                break;
        }
        printf("Case #%d: %d\n", ++c, tot);
    }
    return 0;
}