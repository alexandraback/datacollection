#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <bitset>
#include <complex>
#include <algorithm>

#include <sstream>
#include <fstream>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <climits>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef set <int> si;
typedef pair< int,int > pii;
typedef pair< int, pii > pip;
typedef vector< pii > vii;
typedef vector < vii > vvii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector<string> vs;
typedef vector<double> vd;

#define REP(i,n)       FOR(i,0,n)
#define FOR(i,a,b)     for(int i = a; i < b; i++)
#define ROF(i,a,b)     for(int i=a;i>b;i--)
#define s(n)          scanf("%d",&n)
#define sl(n)         scanf("%lld",&n)
#define sf(n)         scanf("%lf",&n)
#define pb 	          push_back
#define mp 	          make_pair
#define MOD 	        1000000007
#define INF	          (int)1e9
#define EPS	          1e-9
#define TR(a,it)      for(typeof((a).begin()) it = (a).begin(); it!=(a).end(); ++it)
#define ALL(a)	      (a).begin(),(a).end()
#define rALL(a)       (a).rbegin(),(a).rend()

#define WHITE 7
#define BLACK 8
#define GREY  9

struct Node
{
       int data;
       int weight;
};

class Graph
{
      public:
        bool directed;
        int nVertices, nEdges;
        vector< vector<Node> > adj_list;
        vector<int> deg, in_deg, out_deg;
        vector<int> color, level, pred, arr, dep;
};

void DFS_VISIT(Graph &g, int start);

void initialize_graph(Graph &g) {
     g.adj_list.resize(g.nVertices + 1);
     //g.deg.resize(g.nVertices + 1);           g.deg.assign(g.nVertices + 1, 0);
     //g.in_deg.resize(g.nVertices + 1);        g.in_deg.assign(g.nVertices + 1, 0);
     //g.out_deg.resize(g.nVertices + 1);       g.out_deg.assign(g.nVertices + 1, 0);

     g.arr.resize(g.nVertices + 1);
     g.dep.resize(g.nVertices + 1);
}

void insert_edge(Graph &g, int x, int y, bool directed) {
     Node v;
     v.data = y;
     v.weight = 1;     //For Unweighted graph
     g.adj_list[x].pb(v);

     //g.deg[x]++;
     //g.out_deg[x]++;
     //g.in_deg[y]++;

     if (directed == false)
           insert_edge(g, y, x, true);
}

void read_graph(Graph &g)
{
     g.directed = true;
     scanf("%d", &(g.nVertices));

     initialize_graph(g);

     int x, y, edges;
     for (int i=1; i<=g.nVertices; i++) {
           scanf("%d", &edges);

           for (int j=0; j<edges; j++) {
               scanf("%d", &y);
               insert_edge(g, i, y, g.directed);
           }
     }
}

void print_graph(Graph &g)
{
     for (int i=1; i <= g.nVertices; i++) {
         printf("%d : ", i);
         TR (g.adj_list[i], it)
              printf("%d ", it -> data);
         printf("\n");
     }
}

int t = 0;    //time...
bool DiamondInheritance = false;
void DFS(Graph &g, int start)
{
     t = 0;
     g.color.assign(g.nVertices + 1, WHITE);
     g.level.assign(g.nVertices + 1, 0);
     g.pred.assign(g.nVertices + 1, -1);

     //printf("DFS from %d\n", start);
     DFS_VISIT(g, start);

     //for (int i=1; i <= g.nVertices; i++) {
     //       if (g.color[i] == WHITE)
     //           DFS_VISIT(g, i);
     //}
}

void DFS_VISIT(Graph &g, int start)
{
     g.color[start] = GREY;
     g.arr[start] = ++t;

     //cout << "Visiting " << start << endl;
     TR (g.adj_list[start], it) {

          if (g.color[it -> data] == WHITE) {
              g.level[it -> data] = g.level[start] + 1;
              g.pred[it -> data] = start;
              DFS_VISIT(g, it -> data);
          }
          else if (g.color[it -> data] != WHITE) {
              DiamondInheritance = true;
          }
     }

     g.dep[start] = ++t;
     g.color[start] = BLACK;
}

int main()
{
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);

      int T, t = 0;
      scanf("%d", &T);
      while (T--) {
          DiamondInheritance = false;
          Graph g;
          read_graph(g);
          //print_graph(g);

          for (int i=1; i<=g.nVertices; i++)
              DFS(g, i);

          if (DiamondInheritance)
            printf("Case #%d: Yes\n", ++t);
        else
            printf("Case #%d: No\n", ++t);
      }
      return 0;
}
