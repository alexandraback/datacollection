#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <set>

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

ll n;
void solve() {
  ll ans = -1;
  scanf("%lld", &n);
  set<char> opens;
  FOR(i, 1, 10000) {
    char temp[100];
    snprintf(temp, 99, "%lld", i * n);
    REP(j, strlen(temp)) {
      opens.insert(temp[j]);
    }
    if (opens.size() == 10) {
      ans = i * n;
      break;
    }
  }
  if (ans != -1) {
    printf("%lld\n", ans);
  } else {
    puts("INSOMNIA");
  }
}
