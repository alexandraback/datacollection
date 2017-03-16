#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

int T,n,a[210],b[210];
double r,l,mid,ans[210];
int main() {
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&T);
    for (int tsum=1;tsum<=T;tsum++) {
        scanf("%d",&n);
        int sum=0;
        for (int i=1;i<=n;i++)
            {scanf("%d",&a[i]);b[i]=i;sum+=a[i];}
        for (int i=1;i<n;i++) {
            int p=i;
            for (int j=i+1;j<=n;j++)
                if (a[j]>a[p]) p=j;
            int temp=a[p];a[p]=a[i];a[i]=temp;
            temp=b[p];b[p]=b[i];b[i]=temp;
        }
        for (int i=1;i<=n;i++) {
            l=0;r=1;
            for (int j=1;j<=40;j++) {
                mid=(r+l)/2.0;
                double ss=a[i]+mid*sum;
                double s2=0;
                for (int k=n;a[k]<ss && k>0;k--) s2+=ss-a[k];
                if (s2<sum) l=mid;
                else r=mid;
            }
            ans[b[i]]=l;
        }
        printf("Case #%d:",tsum);
        for (int i=1;i<=n;i++) printf(" %.6lf",ans[i]*100);
        printf("\n");
    }
    return 0;
}
