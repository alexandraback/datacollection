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
  int X,R,C;
  scanf("%d %d %d", &X, &R, &C);
  if (R>C) {
    swap(R,C);
  }
  DEBUG("X=%d R=%d C=%d\n", X,R,C);
  if (X >= 7) {
    DEBUG("No way 7 or more\n");
    printf("RICHARD\n");
    return;
  }
  if(R*C%X != 0) {
    DEBUG("No way - doesn't divide\n");
    printf("RICHARD\n");
    return;
  }

  if((X+1)/2 > R) {
    DEBUG("No way - too narrow\n");
    printf("RICHARD\n");
    return;
  }
  if(X > C) {
    DEBUG("No way - too short\n");
    printf("RICHARD\n");
    return;
  }
  if(X==4 && R<=2) {
    DEBUG("No way - special 4\n"); // 2etil-propan - leaves odd on side
    printf("RICHARD\n");
    return;
  }
  if(X==5 && R<=3 && C <=10) {
    DEBUG("No way - special 5\n"); // zigzag - need at least 15-wide field
    printf("RICHARD\n");
    return;
  }
  if(X==6 && R<=3) {
    DEBUG("No way - special 6\n"); // 4x4 square with 2 fishtail-like cells - leaves odd
    printf("RICHARD\n");
    return;
  }
  DEBUG("Possible\n");
  printf("GABRIEL\n");
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
