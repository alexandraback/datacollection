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
    int N;
    scanf("%d", &N);
    VInt v;
    int K = N*N*2 - N;

    for (int i = 0; i < K; ++i) {
      int x;
      scanf("%d", &x);
      v.PB(x);
    }
    sort(ALL(v));
    VInt res;
    int i = 0;
    while (i < K) {
      int j = i;
      while (j < K && v[i] == v[j])
	++j;
      if ((j-i)&1)
	res.PB(v[i]);
      i = j;
    }
    printf("Case #%d:", t+1);
    for (int i = 0; i < N; ++i)
      printf(" %d", res[i]);
    printf("\n");
  }

  return 0;
};
