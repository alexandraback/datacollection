#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

void run() {
  int N,J;
  scanf("%d%d",&N,&J);
  assert(N%2==0);
  int d=(N/2)-1;
  assert((1<<d)>=J);
  for (int i=0;i<J;++i) {
    printf("1");
    for (int j=0;j<d;++j) {
      int dig=(i>>j)&1;
      printf("%d%d",dig,dig);
    }
    printf("1 3 2 5 2 7 2 9 2 11\n");
  }
}

int main() {
  int T;
  scanf("%d",&T);
  for (int t=1;t<=T;++t) {
    printf("Case #%d:\n",t);
    run();
  }
  return 0;
}
