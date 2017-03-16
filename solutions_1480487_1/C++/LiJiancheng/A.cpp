#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=202;
int a[maxn];
double b[maxn],sum;
int n,m,s,t,p;

bool check(double mid){
  int i;
  sum=mid;
  for (i=0;i<n;i++)
    if (i!=p){
    b[i]=(b[p]-a[i])/s*100;
    b[i]=max(0.0,b[i]);
    sum+=b[i];
  }
  if (sum<100) return 1;
  return 0;
}

int main(){
  int i,k;
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);
  double l,r,mid;
  scanf("%d",&t);
  for (k=1;k<=t;k++){
    scanf("%d",&n);
    for (p=s=i=0;i<n;i++){
      scanf("%d",&a[i]);
      s+=a[i];
      if (a[i]<a[p]) p=i;
    }
    l=0;
    r=100;
    while (r-l>1e-7){
      mid=(l+r)/2;
      b[p]=a[p]+s*mid/100;
      if (check(mid)) l=mid;
      else r=mid;
    }
    printf("Case #%d: ",k);
    b[p]=mid;
    for (i=0;i<n-1;i++) printf("%.6f ",b[i]);
    printf("%.6f\n",b[n-1]);
  }
  return 0;
}
