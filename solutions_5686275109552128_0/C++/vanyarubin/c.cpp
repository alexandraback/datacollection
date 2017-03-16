#define DEBUG_BUILD

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

int min_time(VI pi) {
  sort(all(pi));
  reverse(all(pi));
  //DEBUG("min time: ");
  //DEBUG_VI(pi);
  int maxpi = pi[0];
  if(maxpi <= 3) {
    //DEBUG("  Trivial - 2\n");
    return maxpi;
  }

  VI pi2(pi);
  pi2[0] -= maxpi/2;
  pi2.push_back(maxpi/2);
  int rmin2 = min_time(pi2) + 1;

  VI pi3(pi);
  pi3[0] -= maxpi/3;
  pi3.push_back(maxpi/3);
  int rmin3 = min_time(pi3) + 1;

  int result = min(maxpi,min(rmin2,rmin3));

  //DEBUG("  time %d ", maxpi);
  //DEBUG_VI(pi);
  return result;
}

void solve() {
  int D;
  scanf("%d", &D);
  DEBUG("D=%d\n", D);

  VI pi(D);
  FOR(i,D)
    scanf("%d", &pi[i]);

  int time = min_time(pi);

  DEBUG("%d\n", time);

  printf("%d\n", time);
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
