#include <cstdio>

using namespace std;

int lawn[100][100];
int colmax[100];
int rowmax[100];
int N, M;

int main() {
    int T; scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d %d", &N, &M);

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                scanf("%d", lawn[y]+x);

                if (x == 0)
                    rowmax[y] = lawn[y][x];
                if (y == 0)
                    colmax[x] = lawn[y][x];

                if (lawn[y][x] > rowmax[y])
                    rowmax[y] = lawn[y][x];
                if (lawn[y][x] > colmax[x])
                    colmax[x] = lawn[y][x];
            }
        }

        int failed = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (lawn[y][x] < rowmax[y] && lawn[y][x] < colmax[x]) {
                    failed = 1;
                    break;
                }
            }
        }

        printf("Case #%d: %s\n", i+1, failed ? "NO" : "YES");
    }

    return 0;
}
