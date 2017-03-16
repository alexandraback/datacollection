#include <iostream>

#include <vector>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

#define SZ(a) int((a).size())

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;

class TarjanSCC {
   int N;
   int id;    // DFS depth "counter"

   stack<int> S;
   vector<bool> in_stack;  // flag to indicate if node is in stack S

   VI  low;
   VI  dfs_order;

   void dfs(int u);

public:
   // input: adjacency list of directed graph
   VVI adj;

   // output
   VVI SCC;   // list of strongly connected components
              // each strongly connected component is a list of vertices
   VI  memberSCC;  // strongly connected component id of each vertex

   TarjanSCC(int _N) : N(_N), adj(_N) {}
   void run();
};

void TarjanSCC::run() {
   N  = adj.size();
   id = 0;

   S = stack<int>();
   in_stack  = vector<bool>(N, false);

   low = VI(N);
   dfs_order = VI(N, 0);

   SCC.clear();
   memberSCC = VI(N, 0);

   for (int u = 0; u < N; ++u)
      if (dfs_order[u] == 0)      // not visited
         dfs(u);                  // start dfs at node u
}

void TarjanSCC::dfs(int u) {
   dfs_order[u] = low[u] = ++id;
   S.push(u);
   in_stack[u] = true;
   for (int j = 0; j < (int) adj[u].size(); ++j) {
      int v = adj[u][j];          // v is succesor of u
      if (dfs_order[v] == 0) {    // v is unvisited, tree edge
         dfs(v);
         low[u] = min(low[u], low[v]);
      }
      else
      if (in_stack[v])            // v is back edge
         low[u] = min(low[u], dfs_order[v]);
   }
   if (low[u] == dfs_order[u]) {
      int nSCC = SCC.size();
      SCC.push_back(vector<int>());
      while (true) {
         int v = S.top();
         S.pop();
         in_stack[v] = false;
         SCC[nSCC].push_back(v);
         memberSCC[v] = nSCC;
         if (v == u)
            break;
      }
   }
}

bool trace;
void dfs1(VVI& T, int u, int p, int dist, VI& D) {
   dist++;
   D[u] = dist;
   if (trace)
      cerr << "u: " << u << " dist = " << dist << endl;
   for (int v : T[u]) {
      if (v == p) continue;
      dfs1(T, v, u, dist, D);
   }
}

int solve(int N, VI& F) {
   TarjanSCC scc(N);
   for (int u = 0; u < N; ++u)
      scc.adj[u].push_back(F[u]-1);
   scc.run();

   int res = 0;

   set<II> SS;
   for (int k = 0; k < (int) scc.SCC.size(); ++k) {
      VI& comp = scc.SCC[k];
      res = max(res, SZ(comp));
/*
      cerr << k << ": ";
      for (int u : comp)
         cerr << u+1 << ' ';
      cerr << endl;
*/
      if (SZ(comp) == 2) {
         II p(comp[0], comp[1]);
         SS.insert(p);
      }
   }

   VVI T( N );
   for (int u = 0; u < N; ++u) {
      int u_gid = scc.memberSCC[u];
      if (SZ(scc.SCC[u_gid]) > 1) continue;
      for (int v : scc.adj[u]) {
         int v_gid = scc.memberSCC[v];
         if (u_gid == v_gid) continue;
         if (SZ(scc.SCC[v_gid]) == 1) {
            T[u].push_back(v);
            T[v].push_back(u);
         }
         if (SZ(scc.SCC[v_gid]) == 2) {
         //   II p(scc.SCC[v_gid][0], scc.SCC[v_gid][1]);
            T[v].push_back(u);
         }
      }
   }

   int res2 = 0;
   for (II p : SS) {
      VI D1(N);
      dfs1(T, p.first, -1, 0, D1);
      int max1 = 0;
      for (int u = 0; u < N; ++u)
         max1 = max(max1, D1[u]);

      VI D2(N);
      dfs1(T, p.second, -1, 0, D2);
      int max2 = 0;
      for (int u = 0; u < N; ++u)
         max2 = max(max2, D2[u]);

   //   cerr << p.first+1 << ' ' << p.second+1 << " : " << max1 << " " << max2 << endl;
      res2 += max1 + max2;
   }

   res = max(res, res2);

   return res;
}

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);

   int TC;
   cin >> TC;
   for (int tc = 1; tc <= TC; ++tc) {
      int N;
      cin >> N;
      VI F(N);
      for (int i = 0; i < N; ++i)
         cin >> F[i];
      int res = solve(N, F);
      cout << "Case #" << tc << ": " << res << '\n';
   }

   return 0;
}
