#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#define esp 1e-10
using namespace std;
double ans;
int n,su,po;
struct che{
    double s,p;
}a[55],b[55];
int la,lb,flag;
int cmp(che x,che y){
    return x.p<y.p;
}
void solve(){
    int i,j;
    while (1){
        sort(a,a+la,cmp);
        sort(b,b+lb,cmp);
        double mn=1e100;
        int w=-1,fw=0;
        for (i=1;i<la;i++){
            if (a[i-1].s<=a[i].s) continue;
            double t=(a[i].p-a[i-1].p-5.0)/(a[i-1].s-a[i].s+0.0);
            if (t<mn){
                mn=t;w=i;
            }
        }
        for (i=1;i<lb;i++){
            if (b[i-1].s<=b[i].s) continue;
            double t=(b[i].p-b[i-1].p-5.0)/(b[i-1].s-b[i].s+0.0);
            if (t<mn){
                mn=t;w=i;fw=1;
            }
        }
        if (w<0) {flag=1;break;}
        int can=1;
        ans+=mn;
        for (i=0;i<la;i++) a[i].p+=a[i].s*mn;
        for (i=0;i<lb;i++) b[i].p+=b[i].s*mn;
        if (fw==0){
            for (i=0;i<lb;i++){
                if (fabs(b[i].p-a[w].p)<=5.0+esp) {can=0;break;}
            }
            if (!can){
                can=1;
                for (i=0;i<lb;i++){
                    if (fabs(b[i].p-a[w-1].p)<=5.0+esp) {can=0;break;}
                }
                if (can) w=w-1;
            }
            if (!can) break;
            b[lb].p=a[w].p;b[lb].s=a[w].s;lb++;
            for (i=w;i<la-1;i++) {a[i].p=a[i+1].p;a[i].s=a[i+1].s;}
            la--;
        }else{
            for (i=0;i<la;i++){
                if (fabs(a[i].p-b[w].p)<5.0) {can=0;break;}
            }
            if (!can){
                can=1;
                for (i=0;i<la;i++){
                    if (fabs(a[i].p-b[w-1].p)<5.0) {can=0;break;}
                }
                if (can) w=w-1;
            }
            if (!can) break;
            a[la].p=b[w].p;a[la].s=b[w].s;la++;
            for (i=w;i<lb-1;i++) {b[i].p=b[i+1].p;b[i].s=b[i+1].s;}
            lb--;
        }
    }
}
            
int main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int i;
    int ca,cc=0;
    char c;
    scanf("%d",&ca);
    while (ca--){
        scanf("%d",&n);
        la=lb=0;
        for (i=1;i<=n;i++){
            scanf("\n%c %d %d",&c,&su,&po);
            if (c=='L'){
                a[la].s=su;a[la].p=po;
                la++;
            }else{
                b[lb].s=su;b[lb].p=po;
                lb++;
            }
        }
        flag=0;ans=0;
        solve();
        cc++;
        if (flag) printf("Case #%d: Possible\n",cc);
        else printf("Case #%d: %.10lf\n",cc,ans);        
    }
    return 0;
}
