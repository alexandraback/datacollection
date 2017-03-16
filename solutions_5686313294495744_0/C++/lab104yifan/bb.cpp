#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T, n;
char str[105][2][105];

int main() {
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small-attempt1.out", "w", stdout);
    int cas = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 2; j++)
            scanf("%s", str[i][j]);
        for (int i = 0; i < (1<<n); i++) {
            int cnt = 0;
            int flag = 0;
            for (int j = 0; j < n; j++) {
                if (i&(1<<j)) {
                    for (int x = 0; x < n; x++) {
                        if (i&(1<<x)) continue;
                        for (int y = 0; y < n; y++) {
                            if (i&(1<<y)) continue;
                            if (strcmp(str[j][0], str[x][0]) == 0 && strcmp(str[j][1], str[y][1]) == 0) {
                                flag = 1;
                            }
                        }
                    }
                    cnt++;
                }
            }
            if (flag) ans = max(ans, cnt);
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}
