#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

int T;
int n, m;

struct node {
    LL type, cnt;
} box[110], toy[110];

LL f[110][110];

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("out.out", "w", stdout);
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            cin >> box[i].cnt >> box[i].type;
        for (int i = 1; i <= m; ++i)
            cin >> toy[i].cnt >> toy[i].type;

        memset(f, 0, sizeof (f));

        LL ans = 0;
        LL sumup[110], sumdown[110];

        box[0].cnt = 0, box[0].type = 0;
        toy[0].cnt = 0, toy[0].type = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = max(ans, f[i][j]);
                memset(sumup, 0, sizeof (sumup));
                for (int k = i + 1; k <= n; ++k) {
                    sumup[box[k].type] += box[k].cnt;

                    memset(sumdown, 0, sizeof (sumdown));
                    for (int l = j + 1; l <= m; ++l) {
                        sumdown[toy[l].type] += toy[l].cnt;
                        f[k][l] = max(0ll + f[k][l],
                                0ll + f[i][j] +
                                min(sumup[box[k].type], sumdown[box[k].type]));
                        ans = max(ans, f[k][l]);
                    }
                }
            }
        }
        printf("Case #%d: ", cas);
        cout << ans << endl;
    }
    return 0;
}