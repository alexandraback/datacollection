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

VI idx2cnt(1000002);

i64 reverti(i64 i) {
  char buff[18];
  sprintf(buff, "%lld", i);
  string istr(buff);
  string istr_revert(istr);
  reverse(all(istr_revert));
  i64 result;
  sscanf(istr_revert.c_str(),"%lld", &result);
  return result;
}

void init() {
  idx2cnt[1] = 1;
  for(i64 i=2; i<idx2cnt.size(); i++) {
    i64 irev = reverti(i);
    i64 irevrev = reverti(irev);
    idx2cnt[i] = idx2cnt[i-1] + 1;
    if (irev < i && irevrev == i && idx2cnt[i] > idx2cnt[irev] + 1) {
      idx2cnt[i] = idx2cnt[irev] + 1;
    }
    assert(idx2cnt[i] <= i);
    if (i < 1000)
      DEBUG("i=%d cnt=%d\n", i, idx2cnt[i]);
  }
}

void solve() {
  i64 N;
  scanf("%lld", &N);
  DEBUG("N=%lld\n", N);
  i64 result = idx2cnt[N];
  assert(result <= N);
  DEBUG("%lld\n", result);
  printf("%lld\n", result);
}

int main(int argc, char** argv) {
  int TT;
  scanf("%d", &TT);
  init();
  for(int ii = 1; ii <= TT; ii++) {
    fprintf(stderr, "\n\nCase #%d\n", ii);
    printf("Case #%d: ", ii);
    solve();
  }
  return 0;
}
