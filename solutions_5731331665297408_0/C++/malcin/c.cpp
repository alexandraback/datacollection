#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>
#include <cmath>
using namespace std;

typedef vector <int > VI;
typedef vector < VI > VVI;
typedef long long LL;
typedef vector < LL > VLL;
typedef vector < double > VD;
typedef vector < string > VS;
typedef pair<int,int> PII;
typedef vector <PII> VPII;
typedef istringstream ISS;

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(var,pocz,koniec) for (int var=(pocz); var<=(koniec); ++var)
#define FORD(var,pocz,koniec) for (int var=(pocz); var>=(koniec); --var)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define SIZE(x) (int)x.size()

int n,m;
vector<int> g[60];
int mapa[60];

VI ret;
int vis[60],vis2[60];

void dfs(int x){
  vis2[x]=1;
  FOREACH(it,g[x])
    if (!vis2[*it])
      dfs(*it);
}

VI stos;
const int INF = 100001;

bool zalej(void){
  REP(i,n) vis2[i] = 0;
  REP(i,n) if (vis[i] == 1) vis2[i] = 1;
  REP(i,n) if (vis[i] == 2 && !vis2[i]) dfs(i);
  REP(i,n) if (vis2[i] == 0) return false;
  return true;
}

int find_besciak(void){
  if (!zalej() || SIZE(stos)==0) return INF;
  int x = stos.back();
  stos.pop_back();
  vis[x] = 1;
  int besciak = find_besciak();
  vis[x] = 2;
  stos.PB(x);
  FOREACH(it,g[x])
    if (!vis[*it])
      if (besciak > *it) besciak = *it;
  return besciak;
}

void rob(void){
  stos.PB(0);
  ret.PB(0);
  vis[0] = 2;
  while(SIZE(stos) > 0){
    int b = find_besciak();
    int x = stos.back();
    bool in = false;
    FOREACH(it,g[x])
      if (*it == b){
        stos.PB(b);
        ret.PB(b);
        vis[b] = 2;
        in = true;
        break;
      }
    if (!in){
      stos.pop_back();
      vis[x] = 1;
    }
  }
}

int main(){
  int te; scanf("%d", &te);
  FOR(ii,1,te){
    printf("Case #%d: ", ii);
    scanf("%d%d",&n,&m);
    VPII kody;
    REP(i,n){
      int x; scanf("%d",&x);
      kody.PB(MP(x,i));
    }
    sort(ALL(kody));
    REP(i,n) mapa[kody[i].ND] = i;
    REP(i,m){
      int a,b; scanf("%d%d",&a,&b); --a; --b;
      a=mapa[a];
      b=mapa[b];
      g[a].PB(b); g[b].PB(a);
    }
    REP(i,n) sort(ALL(g[i]));
    rob();
    FOREACH(it,ret)
      printf("%d", kody[*it].ST);
    printf("\n");
    REP(i,n) vis[i] = 0;
    ret.clear();
    stos.clear();
    REP(i,n) g[i].clear();
  }
	return 0;
}
