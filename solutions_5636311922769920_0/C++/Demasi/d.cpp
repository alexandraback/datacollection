#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <vector>

using namespace std;

int main() {
  int T, K, C, S;

  scanf("%d", &T);
  for(int caso = 1; caso <= T; caso++) {
    printf("Case #%d:", caso);
    scanf("%d %d %d", &K, &C, &S);
    for(int i = 0; i < K; i++) {
      printf(" %d", i+1);
    }
    printf("\n");
  }
  return 0;
}

