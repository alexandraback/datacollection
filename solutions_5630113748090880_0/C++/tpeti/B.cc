#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cstring>

using namespace std;

void run() {
  int N;
  scanf("%d",&N);
  vector<int> sum(2501,0);
  for (int i=0;i<2*N-1;++i) {
    int x;
    for (int j=0;j<N;++j) {
      scanf("%d",&x);
      ++sum[x];
    }
  }
  
for (int i=1;i<=2500;++i) if (sum[i]%2) printf(" %d",i);
  printf("\n");
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
