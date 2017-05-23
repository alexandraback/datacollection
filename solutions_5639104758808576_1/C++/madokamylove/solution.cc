#include <cstdio>
#include <algorithm>
using namespace std;

char s[1010];

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas ++) {
        int n;
        scanf("%d%s", &n, s);
        int need = 0, tot = 0;
        for (int i = 0; i <= n; i ++) {
            need = max(need, i - tot);
            tot += s[i] - '0';
        }
        printf("Case #%d: %d\n", cas, need);
        fprintf(stderr, "Case #%d: %d\n", cas, need);
    }
    return 0;
}