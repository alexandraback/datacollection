#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{

  int T;
  scanf("%d", &T);

  for (int Ti = 1; Ti <= T; Ti++) {
    int A, B, K;
    scanf("%d %d %d", &A, &B, &K);

    long long count = 0;
    for (int i = 0; i < A; i++) {
      for (int j = 0; j < B; j++) {
        int x = i & j;
        if (x < K) {
          count++;
        }
      }
    }
    printf("Case #%d: %lld\n", Ti, count);
  }
  return 0;
}
