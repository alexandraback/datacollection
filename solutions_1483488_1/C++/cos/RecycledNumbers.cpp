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
int lens[2000010];
int main() {
  REP(i, 2000010) {
    char str[20];
    sprintf(str, "%d", i);
    lens[i] = strlen(str);
  }
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

int A, B;
char str[1000];
bool exist[2000010];
void solve() {
  ll ans = 0;
  MEMSET(exist, false);
  scanf("%d %d", &A, &B);
  FOREQ(i, A, B) { exist[i] = true; }
  FOREQ(i, A, B) {
    sprintf(str, "%d", i);
    int len = strlen(str);
    set<int> open;
    REP(iter, len) {
      int v = atoi(str);
      if (v <= B && i < v && exist[v] && lens[i] == lens[v]) {
        open.insert(v);
      }
      rotate(str, str + 1, str + len);
    }
    ans += open.size();
  }
  printf("%lld\n", ans);
}
