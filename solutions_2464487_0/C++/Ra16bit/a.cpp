#include <cstdio>
#include <cmath>
using namespace std;
const double pi=acos(-1.0);
int t,tt,i;
long long r,v,e;
long double sqr(long double x) { return x*x; }
int main() {
  freopen("As.in","r",stdin);
  freopen("As.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
	scanf("%I64d%I64d",&r,&v);
	for (e=i=0; ; i++) {
	  e+=sqr(r+i*2+1)-sqr(r+i*2);
	  if (e>v) break;
	}
    printf("Case #%d: %d\n",t,i);
  }
  return 0;
}
