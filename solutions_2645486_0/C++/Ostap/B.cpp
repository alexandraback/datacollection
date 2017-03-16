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

Int V[11000];

int main()
{
  int T, t;
  scanf("%d", &T);
  for (t = 0 ; t < T; ++t) {
    Int E, R;
    int N;
    scanf("%lld%lld%d", &E, &R, &N);
    for (int i = 0 ;i < N; ++i)
      scanf("%lld", &V[i]);

    Int res = 0;
    Int x = E;

    for (int i = 0; i < N; ++i) {
      int next = -1;
      for (int j = i+1; j < N; ++j)
	if (V[j] > V[i]) {
	  next = j;
	  break;
	}
      if (next == -1) {
	res += x * V[i];
	x = 0;
      } else {
	Int use = x + (next-i)*R - E;
	if (use > x)
	  use = x;
	if (use > 0) {
	  res += use * V[i];
	  x -= use;
	}
      }

      x += R;
    }

    printf("Case #%d: %lld\n", t+1, res);
    fprintf(stderr, "Case #%d: %lld\n", t+1, res);
  }

  return 0;
};
