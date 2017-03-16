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

char buf[100];

bool isPal(Int x) {
  sprintf(buf, "%lld", x);
  int L = strlen(buf);
  for (int i = L-1; i >= 0; --i)
    if (buf[i] != buf[L-1-i])
      return false;
  return true;
}

int main()
{
  vector<Int> res;
  for (Int x = 1; x <= 10000000; ++x)
    if (isPal(x) && isPal(x*x)) {
      res.PB(x*x);
    }

  int T, t;
  scanf("%d", &T);
  for (t = 0; t < T; ++t) {
    Int a, b;
    scanf("%lld%lld", &a, &b);

    int r = 0;
    for (int i = 0; i < res.size(); ++i)
      if (res[i] >= a && res[i] <= b)
	++r;
    printf("Case #%d: %d\n", t+1, r);
  }


  return 0;
};
