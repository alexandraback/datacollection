#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=100+5;
int a[N][N], n, m, f[N], g[N];

int main() {
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int total, tt=0;
    scanf("%d", &total);
    while (total--) {
        scanf("%d%d", &n, &m);
        memset(f, 0, sizeof (f));
        memset(g, 0, sizeof (g));
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++) {
                scanf("%d", &a[i][j]);
                f[i]=max(f[i], a[i][j]);
                g[j]=max(g[j], a[i][j]);
            }
        bool ok=true;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++) {
                if (a[i][j]<f[i]&&a[i][j]<g[j]) {
                    ok=false;
                }
                //printf("(%d,%d,%d)", a[i][j], f[i], g[j]);
            }
        printf("Case #%d: ", ++tt);
        if (ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}