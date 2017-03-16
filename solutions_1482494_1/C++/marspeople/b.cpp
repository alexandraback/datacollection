#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define REP(i,n) for(int i=0; i<(n); i++)

struct par {
    int a,b;
} v[1010];

bool cmp(par x, par y) {
    return x.b>y.b;
}

int us[10010];

int main() {
    int nt;

    scanf(" %d",&nt);
    for (int ct=1;ct<=nt;ct++) {
        int n;

        scanf("%d",&n);
        REP(i,n)
            scanf("%d%d",&v[i].a,&v[i].b);

        sort(v,v+n,cmp);
        int pt,res=0;

        memset(us,0,sizeof(us));
        for (pt=0;pt<2*n;) {
            int upt=pt;
            res++;
            REP(i,n)
                if (us[i]<2 && v[i].b<=pt) {
                    pt+=2-us[i];
                    us[i]=2;
                    break;
                }
            if (upt!=pt) continue;

            REP(i,n)
                if (us[i]==0 && v[i].a<=pt) {
                    us[i]=1;
                    pt++;
                    break;
                }
            if (upt==pt) break;
        }

        printf("Case #%d:",ct);
        if (pt<2*n) printf(" Too Bad\n");
        else printf(" %d\n",res);
    }
    return 0;
}
