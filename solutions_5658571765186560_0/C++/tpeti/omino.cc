#include <cstdio>
#include <vector>

using namespace std;
int main() {
  int T;
  scanf("%d",&T);
  for (int n=1;n<=T;++n) {
    printf("Case #%d: ",n);
    int X,R,C;
    scanf("%d%d%d",&X,&R,&C);
    if (R>C) swap(R,C);
    if (R*C%X || X>C || X>6
	|| (X>2 && R==1)
	|| (X>3 && R==2)) {
      printf("RICHARD\n");
      continue;
    }
    printf("GABRIEL\n");
  }
  return 0;
}
