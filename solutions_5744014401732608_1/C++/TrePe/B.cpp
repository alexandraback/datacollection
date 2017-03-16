#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

int T, t, i, j, k, n, r, c;
int B;
long long M, Mb;
int a[50][50];
int cnt[50];

int main() {
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
        printf("Case #%d:", t);
        scanf("%d%lld", &B, &M);
        for (i = 0; i < B; i++) for (j = 0; j < B; j++) a[i][j] = 0;
        for (i = 0; i < B; i++) cnt[i] = 0;
        Mb = M;
        M--;
        for (i = 0; i < B-2; i++) {
            if (M & (1LL << (i))) {
                cnt[i] = 1;
                M -= (1LL << (i));
            }
        }
        if (M > 0) {
            printf(" IMPOSSIBLE\n");
            continue;
        }
        printf(" POSSIBLE\n");
        for (i = 0; i < B-1; i++) {
            for (j = i + 1; j < B-1; j++) a[i][j] = 1;
        }
        a[0][B-1] = 1;
        for (j = 0; j < B-1; j++) a[j+1][B-1] = cnt[j];
        for (i = 0; i < B; i++) {
            for (j = 0; j < B; j++) printf("%d", a[i][j]);
            printf("\n");
        }
    }
    return 0;
}
