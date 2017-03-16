#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;
typedef long long ll;

ll rev(ll x) {
  ll ret=0;
  while (x) {
    ret=10*ret+x%10;
    x/=10;
  }
  return ret;
}

ll s(ll x) {
  int numofdigits=0;
  ll t=1;
  while (x>=t) { ++numofdigits; t*=10; }
  int n2=numofdigits/2;
  ll t2=1;
  for (int i=0;i<n2;++i) t2*=10;
  ll x2=((x-1ll)/t2)*t2+1ll;
  ll gain=0;
  if (x2>t/10) {
    gain=x2-rev(x2)-1ll;
    //    fprintf(stderr,"%lld - %lld = %lld\n",x2,rev(x2),x2-rev(x2));
    if (gain<0ll) gain=0ll;
    //    fprintf(stderr,"gain=%lld\n",gain);
  }
  if (numofdigits>2) {
    t/=10ll;
    gain+=t-s(t-1)-1ll;
  }
  //  fprintf(stderr,"gain=%lld\n",gain);
  return x-gain;
}

void run() {
  ll N;
  scanf("%lld",&N);
  printf("%lld\n",s(N));
}

int main() {
  int T;
  scanf("%d",&T);
  for (int t=1;t<=T;++t) {
    printf("Case #%d: ",t);
    run();
  }
  return 0;
}
