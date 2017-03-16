#include <stdio.h>
#include <algorithm>

using namespace std;

int T;
int A, B, K;
int i, j;

int main() {
  
  scanf("%d", &T);
  int c = 0;
  while (T--) {
    c++;
    scanf("%d %d %d", &A, &B, &K);
    
    int res = 0;
    for (i = 0; i < A; i++) {
      for (j = 0; j < B; j++) {
	if ((i&j) < K) res++;
      }
    }
    
    printf("Case #%d: %d\n", c, res);
  }
  
  return 0;
}