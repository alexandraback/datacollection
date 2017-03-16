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

int getMask(Int x) {
  int res = 0;
  while (x > 0) {
    res |= (1 << (x%10));
    x /= 10;
  }
  return res;
}

Int F(Int x) {
  if (x == 0)
    return -1;
  Int num = x;
  int mask = getMask(x);
  int all = (1<<10) - 1;
  while (mask != all) {
    num += x;
    mask |= getMask(num);
  }
  return num;
}

int main()
{
  int T, t;
  scanf("%d", &T);
  for (t = 0; t < T; ++t) {
    int N;
    scanf("%d", &N);
    Int res = F(N);
    printf("Case #%d: ", t+1);
    if (res == -1)
      printf("INSOMNIA\n");
    else
      printf("%lld\n", res);
  }
  
  return 0;
};
