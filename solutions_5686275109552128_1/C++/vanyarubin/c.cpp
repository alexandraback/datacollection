//#define DEBUG_BUILD

#include <stdio.h>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <assert.h>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define FOR(i, n) for(int i=0; i<(int)(n); i++)
#define FORD(i, n) for(int i=(n)-1; i>=0; i--)
#define FORI(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

#ifdef DEBUG_BUILD
#  define DEBUG(...) fprintf(stderr, __VA_ARGS__)
#else
#  define DEBUG(...) do {} while (0)
#endif

typedef long double ld;
typedef signed   long long i64;
typedef unsigned long long u64;

// Types
typedef set < int > SI;
typedef vector < ld > VD;
typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < string > VS;
typedef map < string, int > MSI;
typedef map < int, int > MII;
typedef pair < int, int > PII;
typedef vector < VI > VII;

void DEBUG_VI(VI v) {
#ifdef DEBUG_BUILD
  FORI(it,v)
    DEBUG(" %d", *it);
  DEBUG("\n");
#endif
}

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

int main(int argc, char** argv);

void solve() {
  int D;
  scanf("%d", &D);
  DEBUG("D=%d\n", D);

  MII pankakes;
  FOR(i,D) {
    int k;
    scanf("%d", &k);
    if(pankakes.find(k) == pankakes.end())
       pankakes[k] = 0;
    pankakes[k]++;
  }

  MII::iterator maxit = pankakes.end();
  maxit--;
  int max = maxit->first;
  int mintime = max;

  for(int eat=1; eat<max; eat++) {
    DEBUG("Eat = %d\n", eat);
    MII p(pankakes);
    int time = eat;
    while (!p.empty()) {
      DEBUG("p.size = %d\n", p.size());
      FORI(it,p) {
        DEBUG("  p[%d]=[%d]\n", it->first, it->second);
      }
      MII::iterator pmaxit = p.end();
      pmaxit--;
      assert(pmaxit != p.end());
      int pmax = pmaxit->first;
      int maxcnt = pmaxit->second;
      if (pmax > eat) {
        time += pmaxit->second;
        int split = eat;
        while(split*2<pmax)
          split *= 2;
        int split2 = pmax-split;
        DEBUG("Splitting %d to %d,%d\n", pmax, split,split2);
        if(p.find(split) == p.end()) p[split] = 0;
        p[split] += maxcnt;
        if(p.find(split2) == p.end()) p[split2] = 0;
        p[split2] += maxcnt;
      }
      p.erase(pmaxit);
    }
    DEBUG("Time for eat=%d is %d\n", time);
    if (mintime > time) {
      DEBUG("Updating mintime to %d", time);
      mintime = time;
    }
  }

  DEBUG("%d\n", mintime);
  printf("%d\n", mintime);
}

int main(int argc, char** argv) {
  int TT;
  scanf("%d", &TT);
  for(int ii = 1; ii <= TT; ii++) {
    fprintf(stderr, "\n\nCase #%d\n", ii);
    printf("Case #%d: ", ii);
    solve();
  }
  return 0;
}
