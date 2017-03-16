#define DE_BUILD

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
#include <boost/regex.hpp>
#include <boost/tokenizer.hpp>

using namespace std; using namespace boost;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define found(x,e) (x.find(e) != x.end())
#define FOR(i, n) for(int i=0; i<(int)(n); i++)
#define FORD(i, n) for(int i=(n)-1; i>=0; i--)
#define FORI(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

#ifdef DE_BUILD
#  define DE(...) fprintf(stderr, __VA_ARGS__)
#  define DI FOR(indenti,indent) DE("  ")
#else
#  define DE(...) do {} while (0)
#  define DI do {} while (0)
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
typedef set <PII> SPII;
typedef vector < VI > VVI;
typedef vector<SI> G;
void DE_VI(VI v) {
#ifdef DE_BUILD
  FORI(it,v) DE(" %d", *it); DE("\n");
#endif
}

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;
const i64 IMAX = LLONG_MAX;
const u64 UMAX = ULLONG_MAX;
//#include "lib.cpp"

int main(int argc, char** argv);

bool match(int i, string s) {
  //DE("%d and %s match??\n", i, s.c_str());
  int idx = s.size() - 1;
  while(i>0) {
    int d = i%10;
    i/=10;
    //DE("idx = %d Compare %c %c\n",idx, d+'0', s[idx]); 
    if(s[idx] != '?' && d+'0' != s[idx]) return false;
    idx--;
    //DE("i=%d\n",i);
  }
  while(idx >= 0) {
    //DE("leftover %c\n", s[idx]); 
    if(s[idx] != '0' && s[idx] != '?') return false;
    idx--;
  }
  //DE("%d and %s match\n", i, s.c_str());
  return true;
}

void solve() {
  const size_t BUFF_SIZE = 2001;
  char buff[BUFF_SIZE];
  scanf("%s", buff);
  string s1(buff);
  scanf("%s", buff);
  string s2(buff);
  DE("s1,s2=%s %s\n",s1.c_str(),s2.c_str());

  assert(match(10,"1?"));
  assert(!match(1,"1?"));


  int r1=0, r2=999;
  int p = pow(10,s1.size());
  FOR(i1,p) {
    FOR(i2,p) {
      //DE("Try %d %d for %s %s match??\n", i1,i2, s1.c_str(), s2.c_str());
      if(match(i1,s1) && match(i2,s2)) {
        if(abs(i1-i2) < abs(r1-r2) ||
           (abs(i1-i2) == abs(r1-r2) && 
            (i1<r1 || i1==r1 && i2<r2))) {
          DE("best result %d and %d\n", i1,i2);
          r1 = i1; r2 = i2;
        }
      }
    }
  }
  char form[BUFF_SIZE];
  sprintf(form, "%%0%dd %%0%dd\n", s1.size(), s1.size());
  DE("p = %d, form = %s\n",p,form);
  fprintf(stderr, form, r1,r2);
  printf(form, r1,r2);
  return;
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
