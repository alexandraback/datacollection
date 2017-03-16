#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int map[110][110];
int cnt[110];
int have[110];
int vish[110], visl[110];

int gao(int i, int j) {
    if (map[i - 1][j] == map[i][j] && map[i + 1][j] == map[i][j])
        return 1;
    if (map[i][j - 1] == map[i][j] && map[i][j + 1] == map[i][j])
        return 1;
    return 0;
}

int main() {
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T, m, t, n, i, j, tot;
    scanf("%d", &T);
    for (t = 1; t <= T; ++t) {
        memset(cnt, 0, sizeof (cnt));
        scanf("%d%d", &m, &n);
        tot = 0;
        for (i = 1; i <= m; ++i) {
            for (j = 1; j <= n; ++j) {
                scanf("%d", &map[i][j]);
                if (!cnt[map[i][j]])
                    have[tot++] = map[i][j];
                cnt[map[i][j]]++;
            }
        }
        sort(have, have + tot);
        //    for (i = 0; i < tot; ++i)
        //      printf("i=%d ha=%d cnt=%d\n", i, have[i], cnt[have[i]]);

        int ok = 1, p = 0, v, sum;
        memset(vish, 0, sizeof (vish));
        memset(visl, 0, sizeof (visl));
        while (p < tot) {
            //      printf("p=%d\n",p);
            for (i = 1; i <= m; ++i) {
                if (vish[i])
                    continue;
                v = 1;
                sum = 0;
                for (j = 1; j <= n; ++j) {
                    if (visl[j])
                        continue;
                    if (map[i][j] != have[p]) {
                        v = 0;
                        break;
                    }
                    //    printf("i=%d j=%d havp=%d map=%d\n",i,j,have[p],map[i][j]);
                    ++sum;
                }
                //    printf("sssssshang\n");
                if (v) {
                    cnt[have[p]] -= sum;
                    if (cnt[have[p]] == 0)
                        ++p;
                    vish[i] = 1;
                    goto L;
                }
            }
            for (i = 1; i <= n; ++i) {
                if (visl[i])
                    continue;
                v = 1;
                sum = 0;
                for (j = 1; j <= m; ++j) {
                    if (vish[j])
                        continue;
                    if (map[j][i] != have[p]) {
                        v = 0;
                        break;
                    }
                    ++sum;
                }
                if (v) {
                    cnt[have[p]] -= sum;
                    if (cnt[have[p]] == 0)
                        ++p;
                    visl[i] = 1;
                    goto L;
                }
            }
            ok = 0;
            break;
L:
            ;
        }
        printf("Case #%d: %s\n", t, ok ? "YES" : "NO");
    }
    return 0;
}