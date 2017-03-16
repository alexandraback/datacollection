#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;

int T, hist[26], digits[10];
char S[4000], nums[10][30] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void remove(int i, int d) {
  digits[i] += d;
  for (char *x = nums[i]; *x; ++x)
    hist[*x - 'A'] -= d;
}

int main() {
  scanf("%d", &T);
  REP (tc, T) {
    scanf("%s", S);
    memset(hist, 0, sizeof hist);
    memset(digits, 0, sizeof digits);
    for (char *x = S; *x; ++x)
      ++hist[*x - 'A'];

    remove(6, hist['X' - 'A']);
    remove(8, hist['G' - 'A']);
    remove(7, hist['S' - 'A']);
    remove(5, hist['V' - 'A']);
    remove(0, hist['Z' - 'A']);
    remove(2, hist['W' - 'A']);
    remove(3, hist['H' - 'A']);
    remove(4, hist['F' - 'A']);
    remove(1, hist['O' - 'A']);
    remove(9, hist['I' - 'A']);

    printf("Case #%d: ", tc);
    FOR (i, 10) FOR (j, digits[i]) printf("%d", i);
    printf("\n");
  }
  return 0;
}
