#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

void run() {
  int N;
  scanf("%d",&N);
  if (N==0) {
      printf("INSOMNIA\n");
      return;
  }
  int digits=0,x=N;
  for(;;) {
    int y=x;
    do {
      int d=y%10;
      digits|=(1<<d);
      y/=10;
    } while (y>0);
    if (digits==1023) {
      printf("%d\n", x);
      return;
    }
    x+=N;
  }
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
