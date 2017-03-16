#include <iostream>
#include <cstdio>
using namespace std;

int cas, A, B, N;
long long res;

int main() {
  scanf("%d",&cas);
  for (int k=1; k<=cas; ++k) {
    scanf("%d %d %d",&A, &B, &N);
    res=0;
    for (int i=0; i<A; ++i)
    for (int j=0; j<B; ++j)
      if ((i&j)<N) ++res;

    printf("Case #%d: %lld\n",k,res);
  }
  return 0;
}
