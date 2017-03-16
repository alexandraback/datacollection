#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    int T, mat[60][60];
    long long f[60];
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        printf("Case #%d: ", ca);
        memset(mat, 0, sizeof(mat));
        memset(f, 0, sizeof(f));
        long long b, m;
        cin >> b >> m;
        if ((1LL<<(b-2)) < m) {
            printf("IMPOSSIBLE\n");
            continue;
        } else {
            printf("POSSIBLE\n");
        }
        f[0] = 1;
        for (int i = 1; i < b; ++i) {
            long long s = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (s + f[j] <= m) {
                    s += f[j];
                    mat[j][i] = 1;
                }
            }
            f[i] = s;
        }
        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < b; ++j) {
                printf("%d", mat[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
