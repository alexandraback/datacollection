#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i = 0; i < (n); ++i)
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define FORE(it, V) for (__typeof(V.begin()) it = V.begin(); it != V.end(); ++it)

#define PB push_back
#define FI first
#define SE second
#define MP make_pair

typedef long long LL;

const int MAXN = 100005;
double prob[MAXN];
double mnoz[MAXN];

void testcase() {
  int a, b;
  scanf("%d%d", &a, &b);
  REP(i,a) {
    scanf("%lf", prob+i);
  }
  mnoz[0] = prob[0];
  FOR(i,1,a-1) mnoz[i] = mnoz[i-1] * prob[i];
  // zero wywalonych
  double best = (2.0 + b + b - a)*(1.0 - mnoz[a-1]) + (b-a+1)*mnoz[a-1];
  // enter
  best = min(best, 2.0 + b);
  // do ktorego
  FORD(i,a-1,0) {
    // od 1..i wlacznie
    double back = a-i;
    double reszta = 1.0;
    if (i) {
      reszta = mnoz[i-1];
    }
    best = min(best, back + reszta * (b - a + back + 1.0) + (1.0 - reszta) * (b - a + back + 2.0 + b));
  }
  printf("%lf\n", best);
}

int main() {
  int t;
  scanf("%d", &t);
  FOR(i,1,t) {
    printf("Case #%d: ", i);
    testcase();
  }
}
