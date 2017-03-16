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
typedef pair <char,char> PCC;
typedef pair <int,char> PIC;

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

map<PCC,PIC> mult;
void init() {
  mult[PCC('1','1')] = PIC(1,'1');
  mult[PCC('1','i')] = PIC(1,'i');
  mult[PCC('1','j')] = PIC(1,'j');
  mult[PCC('1','k')] = PIC(1,'k');
  mult[PCC('i','1')] = PIC(1,'i');
  mult[PCC('j','1')] = PIC(1,'j');
  mult[PCC('k','1')] = PIC(1,'k');

  mult[PCC('i','i')] = PIC(-1,'1');
  mult[PCC('i','j')] = PIC(1,'k');
  mult[PCC('i','k')] = PIC(-1,'j');

  mult[PCC('j','i')] = PIC(-1,'k');
  mult[PCC('j','j')] = PIC(-1,'1');
  mult[PCC('j','k')] = PIC(1,'i');

  mult[PCC('k','i')] = PIC(1,'j');
  mult[PCC('k','j')] = PIC(-1,'i');
  mult[PCC('k','k')] = PIC(-1,'1');

  vector<char> cc{'1','i','j','k'};
  FOR(i, cc.size()) {
    DEBUG("%c ", cc[i]);
    FOR(j, cc.size()) {
      PCC q(cc[i],cc[j]);
      PIC qr = mult[q];
      DEBUG(" %c%c", qr.first==1 ? ' ':'-', qr.second);
    }
    DEBUG("\n");
  }
}

bool find_result(char tofind, int& idx, const string s, int X, bool toend) {
  DEBUG("find_result %c\n", tofind);
  int sign = 1;
  char result = '1';
  while (idx < s.size()*X && (toend || !(result == tofind && sign == 1))) {
    char sc = s[idx%s.size()];
    PCC curr(result, sc);
    assert(mult.find(curr) != mult.end());
    PIC next = mult[curr];
    sign *= next.first;
    result = next.second;
    //DEBUG("idx(%d) char(%c) sing(%d) result(%c)\n",idx, sc, sign, result);
    idx++;
  }
  if (result == tofind && sign == 1) {
    DEBUG("Found %c at idx = %d\n", tofind, idx);
    return true;
  }
  DEBUG("Couldn't find %c. idx = %d, result=%c%c\n", tofind, idx, sign==1?' ':'-', result);
  return false;
}


void solve() {
  i64 L, X64;
  scanf("%lld %lld", &L, &X64);
  DEBUG("L=%lld X=%lld\n", L,X64);

  if(X64>48)
    X64 -= (X64-48)/48*48;

  DEBUG("X'=%lld\n", X64);
  assert(X64<=96);
  int X = (int)X64;

  char buff[10002];
  scanf("%s", buff);
  string s(buff);


  assert(L == s.size());
  int idx = 0;
  if (!find_result('i',idx,s,X,false)) {
    printf("NO\n");
    return;
  }
  if (!find_result('j',idx,s,X,false)) {
    printf("NO\n");
    return;
  }
  if (!find_result('k',idx,s,X,true)) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
}

int main(int argc, char** argv) {
  int TT;
  init();
  scanf("%d", &TT);
  for(int ii = 1; ii <= TT; ii++) {
    fprintf(stderr, "\n\nCase #%d\n", ii);
    printf("Case #%d: ", ii);
    solve();
  }
  return 0;
}
