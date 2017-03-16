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
    //puts("");
    solve();
  }
}

int n;
double ken[10000];
double naomi[10000];
bool used[10000];

int Normal() {
  int ans = 0;
  MEMSET(used, false);
  REP(i, n) {
    int minIndex = n;
    REP(j, n) {
      if (used[j]) { continue; }
      minIndex = min(j, minIndex);
      if (ken[j] > naomi[i]) {
        used[j] = true;
        goto next;
      }
    }
    assert(minIndex != n);
    used[minIndex] = true;
    ans++;
next:;
  }
  return ans;
}

int Cheated() {
  int ans = 0;
  multiset<double> kens;
  multiset<double> naomis;
  REP(i, n) { kens.insert(ken[i]); }
  REP(i, n) { naomis.insert(naomi[i]); }
  REP(i, n) {
    FORIT(it, naomis) {
      if (*it > *kens.begin()) {
        naomis.erase(it);
        kens.erase(kens.begin());
        ans++;
        goto next;
      } 
    }
    naomis.erase(naomis.begin());
    kens.erase(kens.find(*kens.rbegin()));
next:;
  }
  return ans;
}

void solve() {
  scanf("%d", &n);
  REP(i, n) { scanf("%lf", &naomi[i]); }
  REP(i, n) { scanf("%lf", &ken[i]); }
  sort(ken, ken + n);
  sort(naomi, naomi + n);
  int normal = Normal();
  int cheated = Cheated();
  cout << cheated << " " << normal << endl;
}
