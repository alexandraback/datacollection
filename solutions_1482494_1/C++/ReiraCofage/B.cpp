#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int T, C=1, n;
int a[1024], b[1024];
bool tenho1[1024], tenho2[1024];
typedef pair<int,int> ii;
ii v[1024];

bool cmp(ii a, ii b) {
    return a > b;
}

int main() {

    for(scanf("%d",&T);T--;) {
        printf("Case #%d: ",C++);
        scanf("%d",&n);
        for (int i=0;i<n;i++) {
            int x, y;
            scanf("%d %d",&x,&y);
            v[i] = ii(y,x);
        }
        sort(v,v+n,cmp);
        for (int i=0;i<n;i++) {
            a[i] = v[i].second;
            b[i] = v[i].first;
        }

        for (int i=0;i<n;i++)
            tenho1[i] = tenho2[i] = false;

        int estr = 0, tot = 0;
        while (1) {
            // tem 2 direto?
            bool ok=false;
            for (int i=0;i<n;i++) if (!tenho1[i] and !tenho2[i] and estr >= b[i]) {
                tot++;
                estr += 2;
                tenho1[i] = tenho2[i] = true;
                ok = true;
                break;
            }
            if (ok) continue;

            // tem 2 indireto?
            for (int i=0;i<n;i++) if (tenho1[i] and !tenho2[i] and estr >= b[i]) {
                tot++;
                estr++;
                tenho2[i] = true;
                ok = true;
                break;
            }
            if (ok) continue;

            // tem 1?
            for (int i=0;i<n;i++) if (!tenho1[i] and estr >= a[i]) {
                tot++;
                estr++;
                tenho1[i] = true;
                ok = true;
                break;
            }
            if (!ok) break;
        }
        if (estr != 2*n)
            printf("Too Bad\n");
        else
            printf("%d\n",tot);


    }

    return 0;
}
