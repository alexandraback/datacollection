#include <stdio.h>
#include <iostream>

int main() {
  int T;
  scanf("%d\n", &T);
  for (int t = 1; t <= T; t++) {
    long long K, C, S;
    std::cin >> K >> C >> S;
    if (S*C < K) { printf("Case #%d: IMPOSSIBLE\n", t); continue; }
    int c = C;
    long long number = 0;
    printf("Case #%d:", t);
    for (long long i = 0; i < K; i++) {
      if (c == 0) {
        std::cout << " " << (number + (long long)1L);
        number = 0;
        c = C;
      }
      number = number * K + i;
      c--;
    }
    std::cout << " " << (number + (long long)1L);
    printf("\n");
  }
  return 0;
}
