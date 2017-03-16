#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <iomanip>
#include <assert.h>
#define MP make_pair
#define PB push_back
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#ifdef LOCAL
#define debug(x) {cerr <<#x <<" = " <<x <<"\n"; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(x)
#define debugv(x)
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
using namespace std;
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}

const int N = 55;
vector<int> slo[N];
int zip[N], vis[N];
int is_forb[N];
int n;

void dfs1(int v) {
  vis[v] = 1;
  for (int nei : slo[v]) {
    if (vis[nei] || is_forb[nei] == 1) {
      continue;
    }
    dfs1(nei);
  }
}
bool try_removing(vector<int> forb) {
  RE (i, n) {
    vis[i] = 0;
  }
  for (int a : forb) {
    is_forb[a] = 1;
  }
  int comps = 0;
  RE (i, n) {
    if (is_forb[i] == 0 && vis[i] == 0) {
      dfs1(i);
      comps++;
    }
  }
  for (int a : forb) {
    is_forb[a] = 0;
  }
  return comps <= 1;
}
vector<int> act_stack;
int on_stack[N];
int dfs2(int v) {
  act_stack.PB(v);
  on_stack[v] = 1;
  cout<<zip[v];
  while (1) {
    int smallest_zip = int(1e7), where_smallest_zip = -1, from = -1;
    vector<int> to_rewind;
    for (int stack_pos = int(act_stack.size()) - 1; stack_pos >= 0; stack_pos--) {
      int act_v = act_stack[stack_pos];
      for (int nei : slo[act_v]) {
        if (is_forb[nei] || on_stack[nei]) {
          continue;
        }
        if (smallest_zip > zip[nei]) {
          smallest_zip = zip[nei];
          where_smallest_zip = nei;
          from = act_v;
        }
      }
      to_rewind.PB(act_v);
      if (!try_removing(to_rewind)) {
        //debugv(to_rewind);
        break;
      }
    }
//     cerr<<endl;
//     debug(v);
//     debug(from);
//     debug(where_smallest_zip);
    if (from != v) {
      act_stack.pop_back();
      is_forb[v] = 1;
      on_stack[v] = 0;
      return from;
    } else {
      int h = dfs2(where_smallest_zip);
      if (h != v) {
        act_stack.pop_back();
        is_forb[v] = 1;
        on_stack[v] = 0;
        return h;
      }
    }
  }
}
  
    
int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  make(int, ttt);
  RE (tt, ttt) {
    cout<<"Case #"<<tt<<": ";
    cin>>n;
    make(int, m);
    int smallest_zip = int(1e6), where_smallest_zip = 0;
    RE (i, n) {
      cin>>zip[i];
      slo[i].clear();
      if (zip[i] < smallest_zip) {
        smallest_zip = zip[i];
        where_smallest_zip = i;
      }
      is_forb[i] = 0;
    }
    RE (i, m) {
      make2(int, a, b);
      slo[a].PB(b);
      slo[b].PB(a);
    }
    dfs2(where_smallest_zip);
    cout<<endl;
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  // nie zapomnij o ll
  return 0;
}
