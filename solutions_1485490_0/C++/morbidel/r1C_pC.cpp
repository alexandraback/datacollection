/*
 * Google Code Jam 2012
 * Round 1C - Problem C - Box Factory
 */

#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <queue>
#include <iostream>
#include <sstream>
#include <functional>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(x) ((x) > 0 ? (x) : -(x))

using namespace std;

#define OFFICIAL 1

#if OFFICIAL
  #define INPUT_FILE    "C-small-attempt1.in"
  #define OUTPUT_FILE   "C-small-attempt1.out"
#else
  #define INPUT_FILE    "input.txt"
#endif

#define MIN(a, b)     ((a) > (b) ? (b) : (a))
#define MAX(a, b)     ((a) > (b) ? (a) : (b))
#define ABS(a)        ((a) > 0 ? (a) : -(a))

int N, M;
vector<int> T1, T2;
vector<__int64> Q1, Q2;

__int64 A[101][101];

__int64 DP(int t1, int t2)
{
  if (t1 >= N || t2 >= M)
  {
    return 0;
  }

  if (T1[t1] == T2[t2])
  {
    __int64 val = MIN(Q1[t1], Q2[t2]);

    if (Q1[t1] > Q2[t2])
    {
      Q1[t1] -= val;
      __int64 ret = val + DP(t1, t2 + 1);
      Q1[t1] += val;

      return ret;
    }
    else if (Q1[t1] < Q2[t2])
    {
      Q2[t2] -= val;
      __int64 ret = val + DP(t1 + 1, t2);
      Q2[t2] += val;

      return ret;
    }
    else
    {
      return val + DP(t1 + 1, t2 + 1);
    }
  } else
  {
    __int64 v1 = DP(t1 + 1, t2);
    __int64 v2 = DP(t1, t2 + 1);

    return MAX(v1, v2);
  }

  return 0;
}

__int64 Solve()
{
  __int64 ans = 0;

  ans = DP(0, 0);

  return ans;
}

int main()
{
  freopen(INPUT_FILE, "rt", stdin);

#if OFFICIAL
  freopen(OUTPUT_FILE, "wt", stdout);
#endif

  int T, nt;

  scanf("%d", &T);

  for (nt = 1; nt <= T; ++nt)
  {
    scanf("%d %d", &N, &M);

    T1.clear();
    T1.resize(N);
    Q1.clear();
    Q1.resize(N);
    for (int i = 0; i < N; ++i)
    {
      scanf("%I64d %d", &Q1[i], &T1[i]);
    }

    T2.clear();
    T2.resize(M);
    Q2.clear();
    Q2.resize(M);
    for (int i = 0; i < M; ++i)
    {
      scanf("%I64d %d", &Q2[i], &T2[i]);
    }

    printf("Case #%d: %I64d\n", nt, Solve());
  }

  return 0;
}