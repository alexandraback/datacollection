#include <cstdio>
#include <algorithm>
using namespace std;
int t,tt,i,j,k,c,d,n;
double a[1010],b[1010];
int main() {
  freopen("Dl.in","r",stdin);
  freopen("Dl.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d",&n);
    for (i=0; i<n; i++) scanf("%lf",&a[i]);
    for (i=0; i<n; i++) scanf("%lf",&b[i]);
    sort(a,a+n);
    sort(b,b+n);
    for (i=c=d=0; i<n; i++) if (a[i]>b[d]) d++;
    for (j=k=n-1; j>=0; j--) if (b[k]>a[j]) k--; else c++;
    printf("Case #%d: %d %d\n",t,d,c);
  }
  return 0;
}
