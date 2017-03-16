#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
  int T;
  int K, C, S;

  scanf("%d", &T);

  for(int caso = 1; caso <= T; caso++) {
    scanf("%d %d %d", &K, &C, &S);

    printf("Case #%d:", caso);

    for(int i = 1; i <= S; i++) {
      printf(" %d", i);
    }

    printf("\n");
  }

  return 0;
}
