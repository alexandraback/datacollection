#include <stdio.h>

int palindrome(int n) {
  int digits[15];
  int pos = 0;
  while (n > 0) {
    digits[pos++] = n % 10;
    n /= 10;
  }
  int i;
  for (i = 0; i < pos/2; i++)
    if (digits[i] != digits[pos - 1 - i])
      return 0;
  return 1;
}

int main() {
  int T, ncase;
  scanf("%d", &T);
  for (ncase = 0; ncase < T; ncase++) {
    printf("Case #%d: ", ncase+1);
    int A, B;
    scanf("%d", &A);
    scanf("%d", &B);
    int i;
    int n = 0;
    for (i = 0; i <= B; i++) {
      int sq = i*i;
      if (sq < A)
        continue;
      if (sq > B)
        break;
      if (palindrome(i) && palindrome(sq))
        n++;
    }
    printf("%d\n", n);
  }
  return 0;
}

