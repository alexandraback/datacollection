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
  srand(4747471);
  int T;
  scanf("%d", &T);

  int R, N, M, K;
  scanf("%d%d%d%d", &R, &N, &M, &K);

  printf("Case #1:\n");

  for (int i = 0; i < R; ++i) {
    VInt p;
    for (int j = 0; j < K; ++j) {
      int a;
      scanf("%d", &a);
      p.PB(a);
    }

    string res = "";
    for (int j = 0; j < N; ++j)
      res += '2' + (rand() % (M-1));

    printf("%s\n", res.c_str());
  }



  return 0;
};
