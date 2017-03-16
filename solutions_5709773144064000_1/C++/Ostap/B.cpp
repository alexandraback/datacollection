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
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    double C, F, X;
    scanf("%lf%lf%lf", &C, &F, &X);
    double res = X/2;
    double sp = 2;
    double ct = 0;
    for (int i = 0; i < 200000; ++i) {
      double dt = C/sp;
      ct += dt;
      sp += F;
      res = min(res, ct + X/sp);
    }
    printf("Case #%d: %.10lf\n", t+1, res);
  }

  return 0;
};
