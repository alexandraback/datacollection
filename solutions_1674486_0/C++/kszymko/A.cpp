#ifndef INCLUDES

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <unistd.h>
#include <utility>
#include <vector>
using namespace std;

#endif

#ifndef MACROS

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define SZ(c) ((int)(c).size())
#define CLR(c,v) memset(c, v, sizeof(c))
#define REP(i,e) for(int i = 0; i < (signed)(e); ++i)
#define REPS(i,c) for(int i = 0; i < (int) (c).size(); ++i)
#define FORU(i,b,e) for(__typeof(b) i = (b); i != (e); ++i)
#define FORD(i,b,e) for(__typeof(b) i = (b); i != (e); --i)
#define FORC(i,c) FORU(i,c.begin(),c.end())
typedef vector<int> vi; typedef long long Int;

#endif

#ifndef TOOLS

const int INF = 0x7FFFFFFF;

struct E { int reverse; int vis; E(int vis) : vis(vis) {} E () {} };
struct V { int visited; int dist, prev; };
struct Edge : E { int u, v; Edge (E p, int u, int v) : E(p), u(u), v(v) {} };
struct Vertex : V, vector<Edge> { };

struct DirectedGraph {
 int N; // #vertexes
 vector<Vertex> G;

 DirectedGraph (int n = 0) : G(n) { N = n; }

 void edgeD (int b, int e, E d = E()) {
   G[b].PB(Edge(d,b,e));
 }

 vector<Edge*> getAllEdges() {
   vector<Edge*> edges;
   REP(x,N) REP(e,G[x].size()) {
     edges.PB(&G[x][e]);
   }
   return edges;
 }

 void show () {
   REP(x,N) {
     printf("%d:",x);
     FORU(it,G[x].begin(),G[x].end()) {
       printf(" %d(%d)",it->v,it->vis);
     } printf("\n");
   }
 }

 void clearEdges () {
   REP(x,N) {
     FORU(it,G[x].begin(),G[x].end()) {
       it->vis = 0;
     }
   }
 }
 
 bool dfs (int at, int finish) {
  // cout << at << " " << finish << endl;
  if (at == finish) return true;  
  bool res = false;
  
  FORU(it,G[at].begin(),G[at].end()) if (it->vis == 0) { 
    it->vis = 1;
    res = dfs(it->v, finish);
    if (res) break;  
    it->vis = 0;       
  }
  return res;
} 
 
};

#endif

int T, N, M, v;

int main(int argc, char *argv[]) {
  cerr.precision(15);
  cout.precision(15);

  scanf("%d\n",&T);
  REP(testcase,T) {
    scanf("%d\n",&N);    
    DirectedGraph G(N);
    
    REP(i,N) {
      scanf("%d",&M);  
      REP(j,M) {
        scanf("%d",&v); 
        G.edgeD(i,v-1,0);
      }
    }         
    
    bool found = false;
    REP(u,N) {      
      REP(v,N) if (u != v) {
        G.clearEdges();
        //cout << "Try: " << u << " -> " << v << endl;
        //G.show(); cout << endl;
        bool path1 = G.dfs(u, v);
        //cout << "res: " << path1 << endl;
        //G.show(); cout << endl;
        bool path2 = G.dfs(u, v);
        //cout << "res: " << path2 << endl;
        if (path1 && path2) {
          found = true; break; 
        }         
      }
      if (found) break;
    }
    
    if (found) {
      printf("Case #%d: Yes\n",testcase+1);    
    } else {
      printf("Case #%d: No\n",testcase+1); 
    }
  }

  return 0;
}