#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

double a[1000];
int T,n;
double tot,ori;

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&T);
    for (int Case=1;Case<=T;Case++){
        scanf("%d",&n);
        tot=0;
        for (int i=1;i<=n;i++) scanf("%lf",&a[i]),tot+=a[i];
        double st=0,ed=2*tot;
        while (st<ed-0.000000001){
              double sum=0;
              double mid=(st+ed)/2;
              for (int i=1;i<=n;i++) if (a[i]<mid) sum+=mid-a[i];
              if (sum-tot<-0.00000001) st=mid;else ed=mid;
        }
        printf("Case #%d:",Case);
        for (int i=1;i<=n;i++) printf(" %lf",((st-a[i])/tot*100)>0?((st-a[i])/tot*100):0);printf("\n");
    }
}