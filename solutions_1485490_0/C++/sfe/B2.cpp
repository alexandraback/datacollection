#include <assert.h>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string>
#include <list>
#include <stack>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <list>
#define INF 0x3fffffff
#define LINF 0x3fffffffffffffffll
#define DINF 1e100
#define EPS 0.000000000001

typedef long long ll;
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PDD pair<double, double>
#define PIL pair<int, ll>
#define PLI pair<ll, int>
#define PID pair<int, double>
#define PDI pair<double, int>
#define PLD pair<ll, double>
#define PDL pair<double, ll>

#define NUL(x) memset(x, 0, sizeof(x))
#define MINUS(x) memset(x, 0xff, sizeof(x))
#define PQ(x) priority_queue< x >  //highest first
#define PQR(x) priority_queue< x , vector< x > , greater < x > > //lowest first
#define MP make_pair
#define PB push_back
#define IT(x) for (typeof((x).begin()) it = (x).begin() ; it != (x).end() ; it++)
#define IT2(x) for (typeof((x).begin()) it2 = (x).begin() ; it2 != (x).end() ; it2++)
#define FOR(i, a, b) for (int i = (a) ; i< (b) ; i++)
//#define DEB(x...) fprintf(stderr,x)
#define DEB
using namespace std;

struct entry {
  int type;
  ll anz;
};

struct dpentry {
  int lastj;
  int lasti;
  ll used;
  ll val;
};
#define MAXN 105
entry A[MAXN];
entry B[MAXN];
int N,M;

struct tmp {
  int lastj;
  int lasti;
  ll used;
  bool operator<(const tmp o) const {
    return
      lastj<o.lastj ||
      (lastj == o.lastj && lasti<o.lasti) ||
      (lastj == o.lastj && lasti == o.lasti && used < o.used);
  }
};

bool testc(int tc=0)
{
  
  scanf("%i %i ", &N, &M);

  FOR(i,0,N) scanf("%lli %i ", &A[i].anz, &A[i].type);
  FOR(i,0,M) scanf("%lli %i ", &B[i].anz, &B[i].type);

  
  
  vector<dpentry> dp(1, (dpentry){0, -1, 0, 0});

  FOR(i,0,N) {
    int l = dp.size();
    FOR(ind, 0, l) {
      vector<dpentry>::iterator it = dp.begin() + ind;
      assert(it->lasti < i);
      DEB("i=%i load lastj %i lasti %i used %i val %i\n", i, it->lastj, it->lasti, it->used, it->val);

      ll left = A[i].anz;
      ll curval = it->val;
      DEB("typecheck %i %i\n", A[i].type, B[it->lastj].type);
      // use current
      if (A[i].type == B[it->lastj].type && it->used < B[it->lastj].anz) {
        ll v = min(left, B[it->lastj].anz - it->used);
        left -= v;
        curval += v;
        if (v>0) {
          dp.PB((dpentry){it->lastj, i, it->used + v, curval});
          DEB("Add A i=%i lastj %i lasti %i used %i val %i\n", i, it->lastj, i, it->used + v, curval);
        }
      }
      FOR(j,it->lastj + 1, M) if (B[j].type == A[i].type) {
        ll v = min(left, B[j].anz);
        left -= v;
        curval += v;
        if (v>0) {
          dp.PB((dpentry){j, i, v, curval});
          DEB("Add B i=%i lastj %i lasti %i used %i val %i\n", i, j, i, v, curval);
        }
      }
    }
    
    // Clean
    DEB("before clean\n");
    //IT(dp)
    //  DEB("lastj %i lasti %i used %i val %i\n", it->lastj, it->lasti, it->used , it->val);

    map<tmp, ll> mp;
    IT(dp) mp[(tmp){it->lastj, it->lasti, it->used}] = max(mp[(tmp){it->lastj, it->lasti, it->used}], it->val);
    dp.clear();
    IT(mp) dp.PB((dpentry){it->first.lastj, it->first.lasti, it->first.used, it->second});

    DEB("after clean\n");
    //IT(dp)
      //  DEB("lastj %i lasti %i used %i val %i\n", it->lastj, it->lasti, it->used , it->val);
  }

  ll bst = 0;
  IT(dp) if (bst<it->val) bst=it->val;
  printf("Case #%i: %lli\n", tc, bst);  
}


int main()
{
  int t;
  scanf("%i ",&t);
  FOR(i,0,t)
    testc(i+1);

  /*
    while(testc());
  */
  
  return 0;
}
