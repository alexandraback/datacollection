#include<stdio.h>
#include<string.h>
#include<math.h>
#define esp 1e-10
int n;
int a[210],sum;
double ans[210];
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int ca,cc=0;
    int i,j;
    double l,r,mid,t;
    scanf("%d",&ca);
    while (ca--){
        scanf("%d",&n);
        sum=0;
        for (i=0;i<n;i++) {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        for (i=0;i<n;i++){
            l=0.0;r=1.0;
            for (int step=0;step<100;step++){
                mid=(l+r)/2.0;
                t=0;
                for (j=0;j<n;j++) {
                    double tt=((double)(a[i]-a[j])+sum*mid)/(double)sum;
                    if (tt>0) t+=tt;
                }
                if (t<1.0+esp) l=mid;else r=mid;
            }
            ans[i]=r*100.0;
        }
        cc++;
        printf("Case #%d:",cc);
        for (i=0;i<n;i++) printf(" %.6lf",ans[i]);
        printf("\n");
    }
    return 0;
}
