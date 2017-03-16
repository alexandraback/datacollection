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
typedef __int128_t LInt;
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

#define MAX 2000000000000000001LL

LInt longMult(LInt a, LInt b) {
  LInt m = MAX*(LInt)MAX;
  if (b == 0)
    return 0;
  if (a > m/b)
    return m;
  else
    return a*b;
}

LInt S(LInt n) {
  LInt m = MAX*(LInt)MAX;
  if (n <= 0)
    return 0;
  LInt r = longMult(longMult(n, n+1), 2*n+1);
  if (r < m)
    r /= 6;
  return r;
}

LInt S2(LInt n) {
  LInt m = MAX*(LInt)MAX;
  if (n <= 0)
    return 0;
  LInt r = longMult(longMult(n, 2*n-1), 2*n+1);
  if (r < m)
    r /= 3;
  return r;
}

Int F(Int r, Int k) {
  LInt total = longMult(2*r, k);
  if (total < MAX) {
    LInt tmp = S2(k) - (S(2*(k-1)) - S2(k-1));
    if (tmp > 0)
      total += tmp;
  }
  if (total > MAX)
    return MAX;
  return total;
}

int main()
{


  int T, t;
  scanf("%d", &T);
  for (t = 0; t < T; ++t) {
    long long r, p;
    scanf("%lld%lld", &r, &p);

    long long ub, lb, cb;
    lb = 0;
    ub = 10000000000000001LL;
    while (ub - lb > 1) {
      cb = ((ub+lb) >> 1);

      Int total = F(r, cb);

      if (total <= p)
	lb = cb;
      else
	ub = cb;
    }

    printf("Case #%d: %lld\n", t+1, lb);
  }
  

  return 0;
};
