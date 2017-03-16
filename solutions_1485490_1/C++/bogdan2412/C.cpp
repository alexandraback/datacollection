#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100;

int N, M;
long long bst[MAXN + 1][MAXN + 1];
int A[MAXN], B[MAXN];
long long a[MAXN], b[MAXN];

int main() {
    int T;
    assert(scanf("%d", &T) == 1);
    for (int t = 1; t <= T; t++) {
        assert(scanf("%d %d", &N, &M) == 2);
        for (int i = 0; i < N; i++) {
            assert(scanf("%lld %d", a + i, A + i) == 2);
        }
        for (int i = 0; i < M; i++) {
            assert(scanf("%lld %d", b + i, B + i) == 2);
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                bst[i][j] = max(bst[i - 1][j], bst[i][j - 1]);
                if (A[i - 1] == B[j - 1]) {
                    long long Acur = 0, Bcur = 0;
                    for (int k = i - 1; k >= 0; k--) {
                        if (A[k] == A[i - 1]) {
                            Acur += a[k];
                        }
                        Bcur = 0;
                        for (int l = j - 1; l >= 0; l--) {
                            if (B[l] == B[j - 1]) {
                                Bcur += b[l];
                            }
                            bst[i][j] = max(
                                bst[i][j], bst[k][l] + min(Acur, Bcur));
                        }
                    }
                }
            }
        }

        printf("Case #%d: %lld\n", t, bst[N][M]);
    }
    return 0;
}
