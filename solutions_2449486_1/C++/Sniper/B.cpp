#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int h[110][110];
int n, m;
int tar[110][110];

int main() {
    int T;
    scanf("%d", &T);
    for (int ti = 1; ti <= T; ++ ti) {
        scanf("%d%d", &n, &m);
        int H = 1;
        for (int i = 0; i < n; ++ i) for (int j = 0; j < m; ++ j) {
            scanf("%d", &tar[i][j]);
            H = max(H, tar[i][j]);
            h[i][j] = 100;
        }
        for (; H >= 1; -- H) {
            for (int i = 0; i < n; ++ i) {
                bool cut = true;
                for (int j = 0; j < m; ++ j) {
                    if (tar[i][j] > H) {
                        cut = false;
                        break;
                    }
                }
                if (cut) {
                    //printf("cut H=%d, row=%d\n", H, i);
                    for (int j = 0; j < m; ++ j) {
                        h[i][j] = H;
                    }
                }
            }

            for (int j = 0; j < m; ++ j) {
                bool cut = true;
                for (int i = 0; i < n; ++ i) {
                    if (tar[i][j] > H) {
                        cut = false;
                        break;
                    }
                }
                if (cut) {
                    //printf("cut H=%d, col=%d\n", H, j);
                    for (int i = 0; i < n; ++ i) {
                        h[i][j] = H;
                    }
                }
            }
        }

        bool same = true;
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                if (h[i][j] != tar[i][j]) {
                    same = false;
                }
                //printf("%d ", h[i][j]);
            }
            //printf("\n");
        }
        printf("Case #%d: %s\n", ti, same ? "YES" : "NO");
    }
}

