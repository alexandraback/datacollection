#include <cstdio>
#include <algorithm>
using namespace std;
int t,tt,r,c,n,i,x,a[2020];
int main() {
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d",&n); r=1000000000;
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    for (x=1; x<=1000; x++) {
      for (c=i=0; i<n; i++) c+=(a[i]-1)/x;
      r=min(r,x+c);
    }
    printf("Case #%d: %d\n",t,r);
  }
  return 0;
}
