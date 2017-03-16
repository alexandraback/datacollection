#include <stdio.h>
#define MAXN 1001


int main() {
  int n;
  char S[MAXN+1];
  int current, result;

  int T;
  scanf("%d", &T);

for(int ic = 1; ic <= T; ++ic) {
  scanf("%d%s", &n, S);
  result = current = 0;
  for (int i = 0; S[i]; ++i) {
    if (current < i && S[i] != '0') {
      result += i - current;
      current += i - current;
    }
    current += S[i] - '0';
// printf("%d %d %d\n", S[i] - '0', current, result);
  }
  printf("Case #%d: %d\n", ic, result);
}

  return 0;
}
