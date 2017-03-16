#include <cstdio>
using namespace std;
int t,tt;
long long x;
long long rev(long long x) {
  long long y;
  for (y=0; x>0; x/=10) y=y*10+x%10;
  return y;
}
long long pw10len(long long x) {
  long long r=1;
  for (int y=1; x>0; x/=10, y^=1) if (y) r*=10;
  return r;
}
long long solve(long long x) {
  if (x<21) return x;
  long long y=pw10len(x);
  long long z=(x/y)*y+1;
  if (z>x) return 1+solve(x-1);
  long long re=rev(z);
  if (re<z) return x-z+1+solve(re);
  if (x==z) return 1+solve(x-1);
  return x-z+solve(z);
}
int main() {
  freopen("Al.in","r",stdin);
  freopen("Al.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%I64d",&x);
    printf("Case #%d: %I64d\n",t,solve(x));
  }
  return 0;
}
