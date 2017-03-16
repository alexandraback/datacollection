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

u64 basek_mod_div(int base, int k, u64 div) {
  // base^k mod div = base^(k-1) * (base mod div)
  //DEBUG("    basek_mod_div base=%d k=%d div=%llu = ", base, k, div);
  u64 mod = 1;
  FOR(i,k) {
    mod = (mod*base)%div;
  }
  //DEBUG("%llu\n", mod);
  return mod;
}

bool is_prime_base(const VI& digits, int base, u64 *divisors) {
  // iterate over ?primes?, simplify base^k mod div, sum results, mod i
  DEBUG("  prime base base=%d\n", base);
  #ifdef DEBUG_BUILD
  u64 num = 0;
  u64 mult = 1;
  FOR(k,digits.size()) {
    num += mult*digits[k];
    mult *= base;
  }
  DEBUG("    number = %llu\n", num);
  #endif
  // 1000 should be enough
  for (u64 div = 2; div <= 1000; div++) {
    u64 sum = 0;
    FOR(k,digits.size()) {
      if (digits[k]) {
        sum += basek_mod_div(base, k, div);
      }
    }
    if(sum % div == 0) {
      divisors[base] = div;
      DEBUG("  divisor found %llu\n", div);
      return false;
    }
  }
  divisors[base] = ULLONG_MAX;
  DEBUG("  looks like primary\n");
  return true;
}

void solve() {
  int N, J;
  scanf("%d %d", &N, &J);
  DEBUG("N=%d J=%d\n", N, J);

  for(u64 jamdigits=0; jamdigits<(1<<N-2); jamdigits++) {
    VI digits(N);
    FOR(j,N) { digits[j] = 0; }
    digits[N-1] = digits[0] = 1;
    u64 curr = jamdigits;
    DEBUG("jamdigits = %x\n", jamdigits);
    for(int j=1; curr > 0; j++, curr/=2) {
      assert(j<N-1);
      digits[j] = curr%2;
    }
    DEBUG("Jamcoin candidate: ");
    FORD(i,digits.size())
      DEBUG("%d", digits[i]);
    DEBUG("\n");
    bool is_jam = true;
    u64 divisors[11];
    for(int base = 2; base <= 10; base++) {
      if(is_prime_base(digits,base,divisors)) {
        is_jam = false;
        break;
      }
    }
    if(is_jam) {
      DEBUG("Jamcoin found!!!");
      FORD(i,digits.size()) {
        DEBUG("%d", digits[i]);
        printf("%d", digits[i]);
      }
      for(int base = 2; base <= 10; base++) {
        DEBUG(" %llu", divisors[base]);
        printf(" %llu", divisors[base]);
      }
      DEBUG("\n");
      printf("\n");
      J--;
      if(J==0) return;
    }
  }
  DEBUG("Couldn't find enough jamcoins. %d are missing !!!\n", J);
  exit(-1);
}

int main(int argc, char** argv) {
  int TT;
  scanf("%d", &TT);
  for(int ii = 1; ii <= TT; ii++) {
    fprintf(stderr, "\n\nCase #%d\n", ii);
    printf("Case #%d:\n", ii);
    solve();
  }
  return 0;
}
