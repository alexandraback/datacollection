#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <set>
#include <map>

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

struct Person {
  int start;
  ll minute;
  double goal;
  Person() {;}
  Person(int start, ll minute, double goal) : start(start), minute(minute), goal(goal) {;}
  bool operator<(const Person &rhs) const {
    return goal < rhs.goal;
  }
};

int n;
Person persons[500010];
void solve() {
  n = 0;
  int m;
  scanf("%d", &m);
  int index = 0;
  REP(i, m) {
    int degree;
    ll h, minute;
    scanf("%d %lld %lld", &degree, &h, &minute);
    n += h;
    REP(i, h) {
      persons[index++] = Person(degree, minute + i, (minute + i) * (360 - degree) / 360.0 );
      // cout << persons[index - 1].goal << " " << persons[index - 1].goal + persons[index - 1].minute << endl;
    }
  }
  sort(persons, persons + n);
  reverse(persons, persons + n);
  int left = 0;
  int right = n;
  while (left != right) {
    int mid = (left + right) / 2;
    double t = persons[mid].goal;
    bool ok = true;
    // cout << mid << " " << t << endl;
    FOR(i, mid, n) {
      if (fabs(persons[i].goal - t) < EPS) { continue; }
      double ngoal = persons[i].goal + persons[i].minute;
      if (fabs(ngoal - t) < EPS || ngoal < t) {
        ok = false;
        break;
      }
    }
    if (ok) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  printf("%d\n", left);
}
