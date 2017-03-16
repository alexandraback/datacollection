#include <cstdio>
using namespace std;

const int maxn = 128;

int A[maxn][maxn];
int N, M;

bool canDoit() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &A[i][j]);
        }
    }
    for (int height = 100; height >= 1; --height) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (A[i][j] <= height) {
                    int k;
                    for (k = 0; k < N; ++k) {
                        if (A[k][j] > height) {
                            break;
                        }
                    }
                    if (k == N) continue;
                    for (k = 0; k < M; ++k) {
                        if (A[i][k] > height) {
                            break;
                        }
                    }
                    if (k == M) continue;
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    freopen("B-large.in", "r", stdin);
    //freopen("B-small-attempt0.in", "r", stdin);
    //freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);

    int testCount;
    scanf("%d", &testCount);
    for (int testID = 1; testID <= testCount; ++testID) {
        printf("Case #%d: ", testID);
        puts(canDoit() ? "YES" : "NO");
    }
}
