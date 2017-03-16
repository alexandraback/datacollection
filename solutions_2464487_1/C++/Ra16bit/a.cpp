#include <cstdio>
#include <cmath>
using namespace std;
const double pi=acos(-1.0);
int t,tt,i;
long long r,v,e,l,res,h;
double z;
long double sqr(long double x) { return x*x; }
int main() {
  freopen("Al.in","r",stdin);
  freopen("Al.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
	scanf("%I64d%I64d",&r,&v);
	l=1; res=1000000000;
	while (l<res) {
	  h=(l+res)/2+1;
	  z=double(h);
	  z*=2.*r+2.*h-1.;
	  if (z>5e18) { res=h-1; continue; }
	  e=h*(2*r+2*h-1);
	  if (e<=v) l=h; else res=h-1;
	}
    printf("Case #%d: %I64d\n",t,res);
  }
  return 0;
}
