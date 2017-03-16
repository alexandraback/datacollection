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
    int K, C, S;
    scanf("%d%d%d", &K, &C, &S);
    vector<Int> res;
    Int num = 0;
    int digs = 0;
    for (int i = 0; i < K; ++i) {
      num = num*K + i;
      ++digs;
      if (digs == C) {
	res.PB(num);
	num = 0;
	digs = 0;
      }
    }
    if (digs) {
      while (digs < C) {
	num = num*K + K - 1;
	++digs;
      }
      res.PB(num);
    }
    printf("Case #%d:", t+1);
    if (res.size() > S)
      printf(" IMPOSSIBLE\n");
    else {
      for (int i = 0; i < res.size(); ++i)
	printf(" %lld", res[i]+1);
      printf("\n");
    }    
  }
  return 0;
};
