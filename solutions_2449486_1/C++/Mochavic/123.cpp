#include <stdio.h>
#include <algorithm>
using namespace std;
struct abc{
    int x, y, v;
    bool operator < (const abc &a) const{
        return v < a.v;
    }
}a[10010];
int c[110][110];
int cx[110], cy[110];
int n, m;
int main(){
    int T, ri = 1, n, m, i, j, an;
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &n, &m);
        an = 0;
        for (i = 0; i < n; i++) cx[i] = 0;
        for (j = 0; j < m; j++) cy[j] = 0;
        for (i = 0; i < n; i++){
            for (j = 0; j < m; j++){
                scanf("%d", &c[i][j]);
                cx[i] = max(cx[i], c[i][j]);
                cy[j] = max(cy[j], c[i][j]);
                a[an].x = i;
                a[an].y = j;
                a[an++].v = c[i][j];
            }
        }
        sort(a, a + an);
        for (i = 0; i < an; i++){
            if (cx[a[i].x] > a[i].v && cy[a[i].y] > a[i].v) break;
        }
        printf("Case #%d: %s\n", ri++, (i==an)?"YES":"NO");
    }
    return 0;
}
