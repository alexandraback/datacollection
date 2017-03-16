#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
typedef long long LL;

int ans, n, na;
struct Attack{
    int d,w,e,s;
    Attack(){}
    Attack(int d,int w,int e,int s):d(d),w(w),e(e),s(s){}
    bool operator < (const Attack &a)const{ return d<a.d; }
} a[1010000];

int up[40000], w[40000];
int base;

int main(){
    int ca; scanf("%d",&ca);
    for (int tt=1; tt<=ca; tt++){
        scanf("%d",&n);
        na = 0;
        base = 0;
        for (int i=0; i<n; i++){
            int s, w,e,d,m, dd, dp, ds;
            scanf("%d%d%d%d%d%d%d%d", &d, &m, &w, &e, &s, &dd, &dp, &ds);
            for (int j=0; j<m; j++){
                a[na++] = Attack(d,w,e-1,s);
                base = max(base, -e) + 10;
                base = max(base, e) + 10;
                if (base > 20000) fprintf(stderr, "WTF!\n");
                d += dd;
                w += dp;
                e += dp;
                s += ds;
            }
        }
        sort(a,a+na);
        memset(up, 0, sizeof(up));
        memset(w, 0, sizeof(w));
        ans = 0;
        for (int i=0; i<na; i++){
//            printf("day=%d (%d,%d) s=%d\n", a[i].d,a[i].w,a[i].e,a[i].s);
 //           for (int j=a[i].w; j<=a[i].e; j++) printf("%d ",w[j]); puts("");
            if (i>0 && a[i].d!=a[i-1].d){
                for (int j=-base; j<base; j++) w[j+base]=up[j+base];
                for (int j=-base; j<base; j++) up[j+base]=w[j+base];
            }
            bool ok=false;
            for (int j=a[i].w; j<=a[i].e; j++){
                if (w[j+base] < a[i].s) ok=true;
            }
            ans += ok;
            for (int j=a[i].w; j<=a[i].e; j++){
                up[j+base] = max(up[j+base], a[i].s);
            }
        }
        printf("Case #%d: %d\n", tt, ans);
    }
    return 0;
}
