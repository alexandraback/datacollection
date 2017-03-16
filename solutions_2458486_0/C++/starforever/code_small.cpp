#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <cassert>
using namespace std;

#define max2(a,b) (((a) > (b)) ? (a) : (b))
#define min2(a,b) (((a) < (b)) ? (a) : (b))

#define debug(x) cout << (#x) << ": " << (x) << endl
#define echo(x) cout << (#x) << endl
#define TIMER_A(timer) int timer = clock()
#define TIMER_B(timer) cerr << (#timer) << ": " << (double)(clock() - timer) / CLOCKS_PER_SEC << endl

typedef long long LL;
const double eps = 1e-9;
const double pi = M_PI;
const int inf = 2000000000; // 2e9
const LL inf64 = 9000000000000000000LL; // 9e18

const int maxN = 20;
const int maxK = 40;

typedef vector<int> VI;
typedef map<int, int> MII;

int TN, TC;

int N;
char mem[1 << maxN];

int chestKey[maxN];

VI chestInside[maxN];

MII keySet;

int oON;
int openOrder[maxN];

bool search (int chestMask)
{
  if (chestMask == 0)
    return true;
  if (mem[chestMask] != '?')
    return mem[chestMask] == 'Y';
  for (int i = 0; i < N; ++i)
    if (chestMask & 1 << i && keySet[chestKey[i]] > 0)
    {
      for (VI::iterator it = chestInside[i].begin(); it != chestInside[i].end(); ++it)
        ++keySet[*it];
      --keySet[chestKey[i]];
      openOrder[oON++] = i;
      bool r = search(chestMask ^ 1 << i);
      --oON;
      ++keySet[chestKey[i]];
      for (VI::iterator it = chestInside[i].begin(); it != chestInside[i].end(); ++it)
        --keySet[*it];
      if (r)
        return mem[chestMask] = true;
    }
  return mem[chestMask] = false;
}

int main ()
{
  scanf("%d", &TN);
  for (TC = 1; TC <= TN; ++TC)
  {
    int NK, k;
    scanf("%d%d", &NK, &N);

    keySet.clear();
    for (int i = 0; i < NK; ++i)
    {
      scanf("%d", &k);
      ++keySet[k];
    }

    for (int i = 0; i < N; ++i)
    {
      scanf("%d%d", &chestKey[i], &NK);
      chestInside[i].clear();
      for (int j = 0; j < NK; ++j)
      {
        scanf("%d", &k);
        chestInside[i].push_back(k);
      }
    }

    memset(mem, '?', 1 << N);
    oON = 0;
    bool r = search((1 << N) - 1);

    printf("Case #%d: ", TC);
    if (r)
    {
      for (int i = 0; i < N; ++i)
        printf("%d%c", openOrder[i] + 1, i < N - 1 ? ' ' : '\n');
    }
    else
    {
      printf("IMPOSSIBLE\n");
    }
  }
}
