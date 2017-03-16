#include <cstdlib>
#include <cstdio>

int B[101][101];
int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int H, W;
        scanf("%d%d", &H, &W);
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                scanf("%d", &B[i][j]);
            }
        }
        bool ok = true;
        for (int y = 0; y < H && ok; ++y) {
            for (int x = 0; x < W && ok; ++x) {
                bool vposs = true;
                bool hposs = true;
                for (int yy = 0; yy < H; ++yy) {
                    if (B[yy][x] > B[y][x]) {
                        vposs = false;
                        break;
                    }
                }
                for (int xx = 0; xx < W; ++xx) {
                    if (B[y][xx] > B[y][x]) {
                        hposs = false;
                        break;
                    }
                }
                if (!vposs && !hposs) {
                    ok = false;
                }
            }
        }
        printf("Case #%d: %s\n", t, ok ? "YES" : "NO");
    }
    return 0;
}
