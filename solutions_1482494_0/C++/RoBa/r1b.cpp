#include <cstdio>
#include <cstring>

const int INF = 1000000000;
const int MAXN = 1024;
int a[MAXN], b[MAXN];
int tk[MAXN], ta[MAXN];

int main() {
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B-small-attempt2.out","w",stdout);
    int T, ca, i, n;
    scanf("%d",&T);
    for (ca = 1 ; ca <= T ; ++ca) {
        scanf("%d",&n);
        for (i = 0 ; i < n ; i++)
            scanf("%d%d",&a[i],&b[i]);
        int cur = 0, cnt = 0;
        memset(tk, 0, sizeof(tk));
        memset(ta, 0, sizeof(ta));
        int flg = 1, ans = 0;
        while (cnt < n) {
            int maxb = -1, maxa = -1, mini = -1;
            for (i = 0 ; i < n ; i++) {
                if (tk[i]) continue;
                if (b[i] > cur) continue;
                if (b[i] > maxb) {maxb = b[i]; mini = i;}
            }
            if (mini != -1) {
                if (ta[mini]) ++cur;
                else cur += 2;
                tk[mini] = 1;
                ++cnt;
                ++ans;
                continue;
            }
            mini = -1; maxb = -1;
            for (i = 0 ; i < n ; i++) {
                if (ta[i] || tk[i]) continue;
                if (a[i] > cur) continue;
                if (b[i] > maxb) {maxb = b[i]; mini = i;}
            }
            if (mini != -1) {
                ta[mini] = 1;
                ++cur;
                ++ans;
                continue;
            }
            flg = 0; break;
        }
        printf("Case #%d: ", ca);
        if (!flg) printf("Too Bad\n");
        else printf("%d\n",ans);
    }
    return 0;
}
