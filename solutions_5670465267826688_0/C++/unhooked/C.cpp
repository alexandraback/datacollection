#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int T, n, r, p[10002][10002];
int m[9][9] = {{0, 0, 0, 0}, {0, 1, 2, 3, 4}, {0, 2, -1, 4, -3}, {0, 3, -4, -1, 2}, {0, 4, 3, -2, -1}};
char s[100000005];

int mul(int a, int b) {
    if (a > 0 && b > 0)
        return m[a][b];
    if (a < 0 && b < 0)
        return m[-a][-b];
    if (a < 0)
        return -m[-a][b];
    return -m[a][-b];
}

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        bool f = false;
        scanf("%d %d %s", &n, &r, s);
        for (int i = 1; i < r; i++)
            for (int j = 0; j < n; j++)
                s[n * i + j] = s[j];
        n *= r;
        for (int i = 0; i < n; i++) {
            p[i][i] = s[i] - 'i' + 2;
            for (int j = i + 1; j < n; j++) {
                int k = s[j] - 'i' + 2;
                p[i][j] = mul(p[i][j - 1], k);
            }
        }
        for (int i = 0; i + 1 < n; i++) {
            if (p[0][i] != 2) continue;
            for (int j = n - 1; j - i > 1; j--) {
                int jj = p[j][n - 1];
                int kk = p[i + 1][j - 1];
                if (jj == 4 && kk == 3) {
                    f = true;
                    break;
                }
            }
            if (f) break;
        }
        if (f)
            printf("Case #%d: YES\n", t);
        else
            printf("Case #%d: NO\n", t);
    }

    return 0;

}
