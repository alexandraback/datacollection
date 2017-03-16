#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

int T, t, i, j, k, n, r, c, p, s, m;
int J, P, S, K;
int jj[27], pp[27], ss[27];
int jp[3][3], js[3][3], ps[3][3];

int main() {
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        scanf("%d%d%d%d", &J, &P, &S, &K);
        int n = 0;
        for (j = 1; j <= J; j++) {
            for (p = 1; p <= P; p++) {
                for (s = 1; s <= S; s++) {
                    jj[n] = j-1;
                    pp[n] = p-1;
                    ss[n] = s-1;
                    n++;
                }
            }
        }
        int bestm = 0;
        int best = 0;
        for (m = 0; m < (1 << n); m++) {
            for (i = 0; i < 3; i++) for (j = 0; j < 3; j++) jp[i][j] = js[i][j] = ps[i][j] = 0;
            int cnt = 0;
            for (i = 0; i < n; i++) {
                if (m & (1 << i)) {
                    cnt++;
                    if (++jp[jj[i]][pp[i]] > K) break;
                    if (++js[jj[i]][ss[i]] > K) break;
                    if (++ps[pp[i]][ss[i]] > K) break;
                }
            }
            if (i >= n && cnt > best) {
                bestm = m;
                best = cnt;
            }
        }
        printf("%d\n", best);
        for (i = 0; i < n; i++) {
            if (bestm & (1 << i)) {
                printf("%d %d %d\n", jj[i]+1, pp[i]+1, ss[i]+1);
            }
        }
    }
    return 0;
}
