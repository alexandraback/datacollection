/*
 * Google Code Jam 2013
 * Round 1A - Problem B - Manage your Energy
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
  #define INPUT_FILE    "B-small-attempt0.in"
  #define OUTPUT_FILE   "B-small-attempt0.out"
#else
  #define INPUT_FILE    "input.txt"
  #define OUTPUT_FILE   "output.txt"
#endif

int E, R, N, Sol;
vector<int> V;

void PreGen()
{
  // stuff which executes only once, before reading the input
}

void back(int lev, int energy, int gain)
{
  if (lev == N)
  {
    if (gain > Sol)
    {
      Sol = gain;
    }
  }
  else
  for (int i = 0; i <= energy; ++i)
  {
    int new_energy = MIN(energy - i + R, E);
    
    back(lev + 1, new_energy, gain + V[lev] * i);
  }
}

int Solve()
{
  // stuff which is executed for each input
  // expects the output to be printed out

  scanf("%d %d %d", &E, &R, &N);
  V.clear();
  V.resize(N);

  FORN(i, N)
  {
    scanf("%d", &V[i]);
  }

  Sol = 0;

  if (R >= E)
  {
    // make everything
    FORN(i, N)
    {
      Sol += E * V[i];
    }
  }
  else
  {
    back(0, E, 0);
  }

  printf("%d", Sol);

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