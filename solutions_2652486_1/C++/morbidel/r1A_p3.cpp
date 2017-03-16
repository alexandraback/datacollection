/*
 * Google Code Jam 2013
 * Round 1A - Problem C - Good Luck
 */


#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
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

#define MIN(a, b)           ((a) > (b) ? (b) : (a))
#define MAX(a, b)           ((a) > (b) ? (a) : (b))
#define ABS(x)              ((x) > 0 ? (x) : -(x))
#define SGN(x)              (((x) == 0) ? 0 : ((x) > 0 ? 1 : -1))
#define SZ(a)               ((a).size())
#define FORN(_i, _n)        for (int (_i) = 0; (_i) < (_n); ++(_i))
#define FOR_(_i, _a, _b)    for (int (_i) = (_a); (_i) <= (_b); ++(_i))
#define ALL(stl)            (stl).begin(), (stl).end()
#define INF                 1000000000

using namespace std;


#define OFFICIAL 1

#if OFFICIAL
  #define INPUT_FILE    "C-small-2-attempt1.in"
  #define OUTPUT_FILE   "C-small-2-attempt1.out"
#else
  #define INPUT_FILE    "input.txt"
  #define OUTPUT_FILE   "output.txt"
#endif

int R, N, M, K;
map<long long, set<int> > Map;

void PreGen()
{
  // stuff which executes only once, before reading the input
}

bool Included(set<int> &big, set<int> &subset)
{
  set<int>::iterator it;

  for (it = subset.begin(); it != subset.end(); ++it)
    if (big.find(*it) == big.end())
    {
      return false;
    }
  return true;
}

void GenAllSubsets(vector<int> &x)
{
  int total = 1 << N;
  long long num = 0;

  FORN(i, N)
  {
    num = num * 10 + x[i];
  }

  if (Map.find(num) != Map.end())
  {
    return;
  }

  set<int> s;

  FORN(i, total)
  {
    int prod = 1;

    FORN(j, N)
      if (i & (1 << j))
      {
        prod *= x[j];
      }
    s.insert(prod);
  }

  Map[num] = s;
}

void back(int lev, vector<int> &x)
{
  if (lev == N)
  {
    GenAllSubsets(x);
  }
  else
  for (int i = lev ? x[lev - 1] : 2; i <= M; ++i)
  {
    x[lev] = i;
    back(lev + 1, x);
  }
}

int Solve()
{
  // stuff which is executed for each input
  // expects the output to be printed out

  scanf("%d %d %d %d", &R, &N, &M, &K);

  vector<int> x(N, 2);

  back(0, x);

  FORN(i, R)
  {
    set<int> s;

    FORN(j, K)
    {
      int k;
      scanf("%d", &k);
      s.insert(k);
    }

    bool sol = false;
    map<long long, set<int> >::iterator it;

    for (it = Map.begin(); it != Map.end(); ++it)
    {
      if (Included(it->second, s))
      {
        sol = true;
        printf("%lld\n", it->first);
        break;
      }
    }

    if (!sol)
    {
      // random guess
      printf("222222222222\n");
    }
  }

  return 0;
}

int main()
{
  freopen(INPUT_FILE, "rt", stdin);

#if OFFICIAL
  freopen(OUTPUT_FILE, "wt", stdout);
#endif

  PreGen();

  int T, nt;

  scanf("%d\n", &T);

  for (nt = 1; nt <= T; ++nt)
  {
    printf("Case #%d: ", nt);

    if (Solve())
    {
    }

    printf("\n");
  }

  return 0;
}