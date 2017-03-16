#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory.h>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long double Double;
typedef vector<int> VInt;
typedef vector< vector<int> > VVInt;
typedef long long Int;
typedef pair<int, int> PII;

#define FOR(i, n, m) for(i = n; i < m; ++i)
#define RFOR(i, n, m) for(i = (n) - 1; i >= (m); --i)
#define CLEAR(x, y) memset(x, y, sizeof(x))
#define COPY(x, y) memcpy(x, y, sizeof(x))
#define PB push_back
#define MP make_pair
#define SIZE(v) ((int)((v).size()))
#define ALL(v) (v).begin(), (v).end()

int main()
{
  int T, t;
  scanf("%d", &T);
  for (t = 0; t < T; ++t) {
    int X, R, C;
    scanf("%d%d%d", &X, &R, &C);
    bool win = false;
    if (X >= 7) win = true;
    if (X > max(R, C)) win = true;
    if (R*C % X != 0) win = true;
    if (X >= 2 * min(R, C) + 1) win = true;
    if (min(R, C) == 2 && X >= 4) win = true;
    if (min(R, C) == 3) {
      if (X >= 6) win = true;
      if (X == 5 && R*C == 15) win = true;
    }

    printf("Case #%d: %s\n", t+1, win ? "RICHARD" : "GABRIEL");

  }
  return 0;
};
