#include<stdio.h>
#include<string.h>
double p[10100],g[10100];
int a,b;
double ans,t;
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int i;
    int ca,cc=0;
    scanf("%d",&ca);
    while (ca--){
        scanf("%d%d",&a,&b);
        for (i=1;i<=a;i++) scanf("%lf",&p[i]);
        g[0]=1.0;
        for (i=1;i<=a;i++) g[i]=g[i-1]*p[i];
        ans=1e100;
        for (i=a;i>=0;i--){
            t=g[i]*(b-i+1+(a-i))+(1.0-g[i])*(b-i+1+(a-i)+b+1);
            if (ans>t) ans=t;
        }
        if (ans>b+2.0) ans=b+2.0;
        cc++;
        printf("Case #%d: %.6lf\n",cc,ans);
    }
    return 0;
}
