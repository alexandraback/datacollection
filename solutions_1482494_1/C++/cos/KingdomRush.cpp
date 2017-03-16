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
    //puts("");
    solve();
  }
}

int n;
int a[2000];
int b[2000];

void GetStar(int i, int &sum, int &ans) {
  if (b[i] <= sum) { sum++; b[i] = 1e+9; }
  if (a[i] <= sum) { sum++; a[i] = 1e+9; }
  ans++;
}
void solve() {
  scanf("%d", &n);
  REP(i, n) { scanf("%d %d", &a[i], &b[i]); }
  int ans = 0;
  int sum = 0;
  while (sum != n * 2) {
    int maxValue = 0;
    int maxIndex = -1;
    REP(i, n) {
      if (b[i] <= sum) { GetStar(i, sum, ans); goto next; }
    }
    REP(i, n) {
      if (a[i] <= sum && maxValue < b[i]) {
        maxValue = b[i];
        maxIndex = i;
      }
    }
    if (maxIndex == -1) { break; }
    GetStar(maxIndex, sum, ans);
next:;
  }
  
  if (sum != n * 2) {
    puts("Too Bad");
  } else {
    printf("%d\n", ans);
  }
}
