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

SI get_sums(SI denoms, int V) {
  static SI tmp0={0};
  if (denoms.size() == 0) {
    return tmp0;
  }
  SI::iterator b = denoms.begin();
  int nom = *b;
  denoms.erase(b);
  SI r1 = get_sums(denoms, V);
  SI result = r1;
  FORI(sit,r1) {
    int sum = *sit+nom;
    if (sum <= V)
      result.insert(sum);
  }
  return result;
}
  

void solve() {
  int C,D,V;
  scanf("%d %d %d", &C, &D, &V);

  SI noms;
  FOR(i,D) {
    int nom;
    scanf("%d", &nom);
    noms.insert(nom);
  }
  SI sums = get_sums(noms,V);
  for (; sums.size() != V+1; sums = get_sums(noms,V)) {
    FOR(s,V+1) {
      if (sums.find(s) == sums.end()) {
        DEBUG("Inserting %d\n",s);
        noms.insert(s);
        break;
      }
    }
    sums = get_sums(noms,V);
  }
  int result = noms.size() - D;
  printf("%d\n", result);
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
