#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

int T, t, i, j, k, n, r, c;
int B;
long long M;
int a[50][50], in[50];
int mm, m;
int cnt[50];
queue<int> q;

int main() {
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
        printf("Case #%d:", t);
        scanf("%d%lld", &B, &M);
        for (i = 0; i < B; i++) for (j = 0; j < B; j++) a[i][j] = 0;
        mm = 0;
        for (i = 0; i < B-1; i++) {
            mm += B - i - 1;
        }
        for (m = 0; m < (1 << mm); m++) {
            for (i = 0; i < B; i++) cnt[i] = in[i] = 0;
            r = 0;
            c = 1;
            for (i = 0; i < mm; i++) {
                if (m & (1 << i)) {
                    a[r][c] = 1;
                    in[c]++;
                } else {
                    a[r][c] = 0;
                }
                c++;
                if (c >= B) {
                    r++;
                    c = r + 1;
                }
            }
            cnt[0] = 1;
            q.push(0);
            while (!q.empty()) {
                j = q.front();
                q.pop();
                for (i = j + 1; i < B; i++) {
                    if (a[j][i] == 1) {
                        cnt[i] += cnt[j];
                        in[i]--;
                        if (in[i] == 0) q.push(i);
                    }
                }
            }
            if (cnt[B-1] == M) {
                printf(" POSSIBLE\n");
                for (i = 0; i < B; i++) {
                    for (j = 0; j < B; j++) {
                        printf("%d", a[i][j]);
                    }
                    printf("\n");
                }
                break;
            }
        }
        if (m < (1 << mm)) continue;
        printf(" IMPOSSIBLE\n");
    }
    return 0;
}
