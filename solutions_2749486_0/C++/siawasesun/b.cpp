#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <inttypes.h>
#include <gmpxx.h>

#ifdef LOCAL_BUILD
#include "cout.h"
#endif

typedef mpz_class bigint;

using namespace std;

#define mp make_pair
#define ALL(a) (a).begin(), (a).end()

// Forward declarations.
void CommonInit();
void Input();
void Solve();

int main() {
  int T;
  scanf("%d", &T);

  CommonInit();

  for (int testCase = 1; testCase <= T; ++testCase) {
    printf("Case #%d: ", testCase);

    Input();
    Solve();

    printf("\n");
  }

  return 0;
}


int X, Y;
bool finished = false;

void CommonInit() {
}

void Input() {
  finished = false;
  scanf("%d %d", &X, &Y);
}

typedef pair<int, int> P;

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, -1, 0, 1 };
const char D[] = { 'E', 'S', 'W', 'N' };

int dp[1010][1010][50];

void Solve() {
  priority_queue<pair<pair<int, P>, string> > q;
  q.push(mp(mp(- abs(X) - abs(Y), P(0, 0)), ""));

  memset(dp, -1, sizeof(dp));

  while (!q.empty()) {
    pair<pair<int, P>, string> t = q.top(); q.pop();
    int goal_distance = t.first.first;
    const P& cur = t.first.second;
    const string& S = t.second;
    int count = S.length() + 1;

    int x2 = cur.first;
    int y2 = cur.second;

    if (abs(x2) > 300 || abs(y2) > 300 ||
        dp[500 + x2][500 + y2][count] != -1) continue;
    dp[500 + x2][500 + y2][count] = 1;

    if (x2 == X && y2 == Y) {
      // goal.
      printf("%s", S.c_str());
      break;
    }

    for (int d = 0; d < 4; d++) {
      int nx = x2 + count * dx[d], ny = y2 + count * dy[d];
      q.push(mp(mp(- abs(X - nx) - abs(Y - ny), P(nx, ny)), S + D[d]));
    }
  }
}
