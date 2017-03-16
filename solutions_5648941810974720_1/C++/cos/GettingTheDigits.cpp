#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

void solve();
int main() {
  int test;
  scanf("%d", &test);
  char str[1000];
  fgets(str, 999, stdin);
  int test_case = 0;
  while (test--) {
    test_case++;
    printf("Case #%d: ", test_case);
    // puts("");
    solve();
  }
}

int n;
char str[10000];
int str_cnts[300];
int digit_cnts[300];
string digits[10] = {
  "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};
char key[10] = { 'Z', 'O', 'W', 'R', 'U', 'F', 'X', 'V', 'G', 'E' };
int order[10] = { 0, 2, 4, 5, 6, 7, 8, 3, 1, 9 };
void solve() {
  scanf("%s", str);
  MEMSET(str_cnts, 0);
  MEMSET(digit_cnts, 0);
  n = strlen(str);
  REP(i, n) { str_cnts[(int)str[i]]++; }
  REP(iter, 10) {
    int digit = order[iter];
    int v = str_cnts[(int)key[digit]];
    FORIT(it, digits[digit]) {
      str_cnts[(int)*it] -= v;
    }
    digit_cnts[digit] = v;
  }
  REP(i, 10) {
    REP(j, digit_cnts[i]) {
      putchar('0' + i);
    }
  }
  puts("");
}
