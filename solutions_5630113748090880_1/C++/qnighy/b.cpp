// C++ 11
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
  int T; scanf("%d", &T);
  for(int ti = 0; ti < T; ++ti) {
    int N; scanf("%d", &N);
    int heights[2501]; fill(heights, heights+2501, 0);
    for(int i = 0; i < 2*N*N-N; ++i) {
      int x; scanf("%d", &x);
      heights[x]++;
    }
    printf("Case #%d:", ti+1);
    for(int i = 0; i <= 2500; ++i) {
      if(heights[i]&1) printf(" %d", i);
    }
    printf("\n");
  }
  return 0;
}

