#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 521196, MAXS = 55;

char s[MAXN][11], a[MAXS];
int c[11][MAXN], f[MAXS];

inline void checkmin(int &x, int y) {
    if (y < x)
        x = y;
}

int main() {
    freopen("garbled_email_dictionary.txt", "r", stdin);
    for (int i = 0; i < MAXN; ++i) {
        gets(s[i]);
        int x = strlen(s[i]);
        c[x][++c[x][0]] = i;
    }
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int cs = 1; cs <= t; ++cs) {
        memset(f, 63, sizeof f);
        scanf("%s", a + 1);
        int n = strlen(a + 1);
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int ed = min(i, 10);
            for (int j = 1; j <= ed; ++j)
                for (int k = 1; k <= c[j][0]; ++k) {
                    bool g = true;
                    int x = c[j][k], d = 0, lst;
                    for (int l = 0; l < j; ++l)
                        if (s[x][l] != a[i - j + l + 1])
                            if (!d) {
                                d = 1;
                                lst = l;
                            }
                            else if (l - lst < 5) {
                                g = false;
                                break;
                            }
                            else {
                                ++d;
                                lst = l;
                            }
                    if (g)
                        checkmin(f[i], f[i - j] + d);
                }
        }
        printf("Case #%d: %d\n", cs, f[n]);
    }
    return 0;
}
