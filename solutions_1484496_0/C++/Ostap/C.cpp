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

int A[1000];
int K[2000010] = {0};

int main()
{
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
      scanf("%d", &A[i]);

    int sum = -1;

    for (int mask = 1; mask < (1<<N); ++mask) {
      int s = 0;
      for (int i = 0; i < N; ++i)
        if (mask & (1<<i))
          s += A[i];
      if (K[s] == t+1) {
        sum = s;
        break;
      } else {
        K[s] = t+1;
      }
    }

    printf("Case #%d:\n", t+1);

    int cnt = 0;

    for (int mask = 1; mask < (1<<N); ++mask) {
      int s = 0;
      for (int i = 0; i < N; ++i)
        if (mask & (1<<i))
          s += A[i];
      int kk = 0;
      if (s == sum) {
        for (int i = 0; i < N; ++i)
          if (mask & (1<<i)) {
            printf("%s%d", kk ? " " : "", A[i]);
            ++kk;
          }
        printf("\n");
        ++cnt;
        if (cnt == 2)
          break;
      }
    }

  }

  return 0;
};
