#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

void run() {
  int K,C,S;
  scanf("%d%d%d",&K,&C,&S);
  if (S*C<K) {
    printf(" IMPOSSIBLE\n");
    return;
  }
  long long d=0,Kl=K;
  for (int a=0;a<S;++a) {
    long long x=0;
    for (int b=0;b<C;++b) {
      x=x*Kl+d;
      if (++d==Kl) {
	printf(" %lld\n",x+1ll);
	return;
      }
    }
    printf(" %lld",x+1ll);
  }
  assert(false);
}

int main() {
  int T;
  scanf("%d",&T);
  for (int t=1;t<=T;++t) {
    printf("Case #%d:",t);
    run();
  }
  return 0;
}
