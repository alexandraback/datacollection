#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

int T,n,a[505];
int t[1000010];
int main() {
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&T);
    for (int tsum=1;tsum<=T;tsum++) {
        scanf("%d",&n);
        printf("Case #%d:\n",tsum);
        bool ov=false;
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int i=1;i<=1000005;i++) t[i]=0;
        for (int i=1;i<=2097151;i++) {
            int ss=0;
            int w=i;
            for (int j=1;j<=20;j++) {
                if (w & 1==1) ss+=a[j];
                w>>=1;
            }
            if (t[ss]!=0) {
                w=t[ss]; int aa=0;
                for (int j=1;j<=20;j++) {
                    if (w & 1==1)
                    {
                        if (aa==0) {printf("%d",a[j]);aa=1;}
                        else printf(" %d",a[j]);
                    }
                    w>>=1;
                }
                printf("\n");
                w=i;
                aa=0;
                for (int j=1;j<=20;j++) {
                    if (w & 1==1)
                    {
                        if (aa==0) {printf("%d",a[j]);aa=1;}
                        else printf(" %d",a[j]);
                    }
                    w>>=1;
                }
                printf("\n");
                ov=true;   
                break;
            } else t[ss]=i;
        }
        if (ov!=true) printf("Impossible\n");
    }
    return 0;
}
