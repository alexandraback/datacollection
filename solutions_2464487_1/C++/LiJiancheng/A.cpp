#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef unsigned long long ll;
int t,tt;
ll r,m,n;

int main(){
  int i,j;
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);
  scanf("%d",&t);
  for (tt=1;tt<=t;tt++){
    scanf("%lld%lld",&r,&m);
    r=2*r-1;
    n=(ll)((sqrt((long double)r*r+8*m)-r)/4)-1;
    for (;2*n*n+r*n<=m;n++);
    printf("Case #%d: %llu\n",tt,n-1);
  }
  return 0;
}
