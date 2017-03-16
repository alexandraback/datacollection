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
  char str[100];
  fgets(str, 99, stdin);
  int test_case = 0;
  while (test--) {
    test_case++;
    printf("Case #%d: ", test_case);
    solve();
    puts("");
  }
}

char str[1000];
char mapto[200];
void solve() {
  REP(i, 200) { mapto[i] = i; }
  mapto['a'] = 'y';
  mapto['b'] = 'h';
  mapto['c'] = 'e';
  mapto['d'] = 's';
  mapto['e'] = 'o';
  mapto['f'] = 'c';
  mapto['g'] = 'v';
  mapto['h'] = 'x';
  mapto['i'] = 'd';
  mapto['j'] = 'u';
  mapto['k'] = 'i';
  mapto['l'] = 'g';
  mapto['m'] = 'l';
  mapto['n'] = 'b';
  mapto['o'] = 'k';
  mapto['p'] = 'r';
  mapto['q'] = 'z';
  mapto['r'] = 't';
  mapto['s'] = 'n';
  mapto['t'] = 'w';
  mapto['u'] = 'j';
  mapto['v'] = 'p';
  mapto['w'] = 'f';
  mapto['x'] = 'm';
  mapto['y'] = 'a';
  mapto['z'] = 'q';
  gets(str);
  int pos = 0;
  while (str[pos]) { putchar(mapto[(int)str[pos++]]); }
}
