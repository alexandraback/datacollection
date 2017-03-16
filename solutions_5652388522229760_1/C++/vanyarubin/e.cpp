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

void DEBUG_DIGITS (int digits[10]) {
  FOR(j,10) {
    if(digits[j]!=0) {
      DEBUG(" %d",j);
    }
  }
  DEBUG("\n");
}

void solve() {
  i64 N;
  scanf("%lld", &N);
  DEBUG("N=%lld\n", N);

  if (N==0) {
    printf("INSOMNIA\n");
    return;
  }

  int digits[10];
  FOR(j,10) { digits[j] = 0; }
  int digits_num = 0;
  for(int i=1;i<1000;i++) {
    i64 curr = N*i;
    if (curr < 0) {
      DEBUG("OVERFLOW!!! %lld, %d\n", N, i);
      exit(1);
    }
    i64 curr_digits = curr;
    while(curr_digits > 0) {
      int digit = curr_digits%10;
      curr_digits /= 10;
      if(digits[digit] == 0) {
        digits[digit] = 1;
        digits_num++;
      }
    }
    if (digits_num == 10) {
      printf("%lld\n", curr);
      return;
    }
    DEBUG("N*%d = %lld :", i, curr);
    DEBUG_DIGITS(digits);  
  }
  DEBUG("Failed to alldigitize %lld:", N);
  DEBUG_DIGITS(digits);
  exit(1);
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
