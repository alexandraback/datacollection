/*
 * Google Code Jam 2012
 * Round 1C - Problem A - Diamond Inheritance
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
  #define INPUT_FILE    "A-small-attempt0.in"
  #define OUTPUT_FILE   "A-small-attempt0.out"
#else
  #define INPUT_FILE    "input.txt"
#endif

#define MIN(a, b)     ((a) > (b) ? (b) : (a))
#define MAX(a, b)     ((a) > (b) ? (a) : (b))
#define ABS(a)        ((a) > 0 ? (a) : -(a))

int N;
bool A[1001][1001];
vector<int> Flag;


void DF(int nod)
{
  int i;

  for (i = 0; i < N; ++i)
    if (A[nod][i])
    {
      ++Flag[i];
      DF(i);
    }
}

int Solve()
{
  int i, j;

  for (i = 0; i < N; ++i)
  {
    Flag.clear();
    Flag.resize(N, 0);

    DF(i);

    for (j = 0; j < N; ++j)
      if (Flag[j] >= 2)
      {
        // i si j sunt solutii
        return 1;
      }
  };

  return 0;
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
    printf("Case #%d: ", nt);

    scanf("%d", &N);

    memset(A, false, sizeof(A));
    
    int i, j, k, x;

    for (i = 0; i < N; ++i)
    {
      scanf("%d", &x);

      for (j = 0; j < x; ++j)
      {
        scanf("%d", &k);
        A[i][k - 1] = true;
      }
    }

    if (Solve())
    {
      printf("Yes");
    }
    else
    {
      printf("No");
    }

    printf("\n");
  }

  return 0;
}