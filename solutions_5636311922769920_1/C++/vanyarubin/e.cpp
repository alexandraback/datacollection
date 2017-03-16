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

void solve() {
  int K, C, S;
  scanf("%d %d %d", &K, &C, &S);
  DEBUG("K=%d C=%d S=%d\n", K,C,S);
  // With K=10 (10 initial tiles) the question becomes intuitive
  // Numering tiles in artwork in base K, we get C digits for each tile in artwork
  // Those digits for artwork tile signify the tile indexes of original sequence that would cause this one to become gold.
  // With example of C=3, try the following tiles (+1): 009,876,543,210
  if (S*C < K) {
    printf(" IMPOSSIBLE\n");
    return;
  }
  for(int k=0;k<K;k+=C) {
    u64 num = 0;
    u64 mult = 1;
    FOR(c,C) {
      int digit = k+c;
      if (digit >= K)
        digit = 0;
      DEBUG("%d.", digit);
      num += digit*mult;
      mult *= K;
    }
    DEBUG("\n");
    DEBUG(" = %llu\n", num);
    assert(num < pow(K,C));
    printf(" %llu", num+1);
  }
  printf("\n");
}

int main(int argc, char** argv) {
  int TT;
  scanf("%d", &TT);
  for(int ii = 1; ii <= TT; ii++) {
    fprintf(stderr, "\n\nCase #%d\n", ii);
    printf("Case #%d:", ii);
    solve();
  }
  return 0;
}
