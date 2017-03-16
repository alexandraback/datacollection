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
typedef vector <VB > VVB;
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

void DE_M(VVB& s) {
#ifdef DE_BUILD
  FOR(i,s.size()) {
    FOR(j,s[i].size()) {
      DE("%d", s[i][j] ? 1:0);
    }
    DE("\n");
  }
#endif
}


bool find_path_num(VVB& s,int B,int M) {
  bool result;
  MII node2num;
  SI Q;
  FOR(i,B) {
    node2num[i] = 0;
  }
  node2num[0]  = 1;
  
  int idx;
  for(idx=0;idx<B*B+1;idx++) {
    //DE("idx = %d\n", idx);
    bool canrelax = false;
    FOR(i,B) {
      int ncount = 0;
      FOR(j,B) {
        if (s[j][i]) {
          ncount += node2num[j];
        }
      }
      //DE("%d: %d <=? %d\n", i, node2num[i], ncount);
      assert(i == 0 || node2num[i] <= ncount);
      if (node2num[i] < ncount) {
        node2num[i] = ncount;
        canrelax = true;
        //DE("Update[%d] = %d\n", i, ncount);
      }
      if (ncount > B) {
        return false; // loop
      }
    }
    if(!canrelax) break;
    if(node2num[B-1]>M) return false;
  }
  assert(idx<=B*B);
  return node2num[B-1] == M;
}

int B, M;
bool check_forward(VVB s, int idx) {
  if(idx == B-1) {
    //DE("Checking matrix [%d]: \n", idx);DE_M(s);
    if(find_path_num(s, B, M)) {
      printf("POSSIBLE\n");
      FOR(i,B) {
        FOR(j,B) {
          printf("%d",s[i][j] ? 1:0);
          DE("%d",s[i][j] ? 1:0);
        }
        printf("\n");
        DE("\n");
      }
      return true;
    }
    return false;
  }
  i64 max = 1 << B-idx;
  //DE("max = %lld\n", max);
  for (u64 p = 0; p< max; p++) {
    //DE("  Try p %d\n", p);
    u64 pp = p;
    for(int j = idx+1; j<B; j++) {
      //DE("    s[%d][%d] = %d\n", idx,j,pp%2==1? true:false);
      s[idx][j] = pp%2==1? true:false; pp/=2;
    }
    if(s[idx][idx] == 1) continue;
    if(check_forward(s, idx+1)) return true;
  }
  return false;
}
  
void solve() {
  scanf("%d %d", &B,&M);
  fprintf(stderr, "B,M = %d,%d\n",B,M);

  VVB s(B);
  FOR(i,B) {s[i].resize(B);}
  FOR(i,B) {s[B-1][i] = false; }
  bool found = check_forward(s,0);
  if(!found) {
    printf("IMPOSSIBLE\n");
    return;
  }
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
