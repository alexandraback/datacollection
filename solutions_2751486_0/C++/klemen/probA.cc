#include <stdio.h>
#include <string.h>

#define MAXL 1001000

int L = 0, N = 0;
char input[MAXL];
int cons[MAXL];

bool isVowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void makeCons() {
  int cur = 0;
  for (int i = L - 1; i >= 0; i--) {
    if (!isVowel(input[i])) {
      cur++;
    }
    else {
      cur = 0;
    }
    cons[i] = cur;
  }
}

long long solve() {
  long long prev = 0, cur = 0;
  long long rv = 0;
  for (int i = L - 1; i >= 0; i--) {
    if (cons[i] >= N) {
      cur = L - i - N + 1;
    }
    else {
      cur = prev;
    }
    rv += cur;
    prev = cur;
  }
  return rv;
}

int main() {
  int T = 0;
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%s %d", input, &N);
    L = strlen(input);
    makeCons();
    printf("Case #%d: %lld\n", t + 1, solve());
  }
}
