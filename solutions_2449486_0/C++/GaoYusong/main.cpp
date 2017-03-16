#include <cstdio>

using namespace std;

int aa[110][110];

bool gao(int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            bool ok1 = true;
            for (int k = 0; k < n; k++) {
                if (aa[k][j] > aa[i][j]) {
                    ok1 = false;
                    break;
                }
            }
            bool ok2 = true;
            for (int k = 0; k < m; k++) {
                if (aa[i][k] > aa[i][j]) {
                    ok2 = false;
                    break;
                }
            }
            //printf("(%d, %d) ", ok1, ok2);
            if (!ok1 && !ok2) {
                return false;
            }

        }
        //printf("\n");
    }

    return true;
}

int main()
{
    int T;
    int cn = 0;

    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);

    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &aa[i][j]);
            }
        }
        printf("Case #%d: %s\n", ++cn, gao(n, m) ? "YES" : "NO");

    }
    return 0;
}
