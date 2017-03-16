#include <stdio.h>

bool digit[200];
int N;

void swap(int i, int j) {
  if (i > j) return;
  bool tmp = digit[i];
  digit[i] = !digit[j];
  digit[j] = !tmp;
  swap(i+1, j-1);
}

int firstMinus(int i) {
  if (i == N || !digit[i]) return i;
  return firstMinus(i+1);
}

int firstPlus(int i) {
  if (i == N || digit[i]) return i;
  return firstPlus(i+1);
}

int firstMinusR(int i) {
  if (i == -1 || !digit[i]) return i;
  return firstMinusR(i-1);
}

int firstPlusR(int i) {
  if (i == -1 || digit[i]) return i;
  return firstPlusR(i-1);
}

int main() {
  int T;
  scanf("%d\n", &T);
  for (int t = 1; t <= T; t++) {
    N = 0;
    char c = getchar();
    while (c == '-' || c == '+') {
      digit[N++] = c == '+';
      c = getchar();
    }
    int ans = 0;
    while (firstMinus(0) != N) {
      ans++;
      if (digit[0]) swap(0, firstMinus(1) - 1);
      else swap(0, firstMinusR(N - 1));
    }
    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
