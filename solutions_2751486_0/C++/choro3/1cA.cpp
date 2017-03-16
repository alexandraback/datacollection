#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>
#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <sstream>
using namespace std;

#define REPN(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define RREPN(i, a, b) for(int i = (int)(b); i >= (int)(a); i--)
#define REP(i, n) REPN(i, 0, n)
#define FOR(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;

const int inf = INT_MAX / 3;
const double eps = 1e-8;

bool novow(char c) {
  return !(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o');
}

int main() {

  int T;
  scanf("%d", &T);

  REPN(tc, 1, T + 1) {
    char buf[1000009];
    int N;
    scanf("%s %d", buf, &N);

    int len = strlen(buf);
    int res = 0;
    REP(i, len + 1) REP(j, i) {
      int c = 0, t = 0;
      REPN(k, j, i) {
        t = novow(buf[k]) ? t + 1 : 0;
        c = max(c, t);
      }
      if(c >= N) res++;
    }

    printf("Case #%d: %d\n", tc, res);
  }

  return 0;
}
