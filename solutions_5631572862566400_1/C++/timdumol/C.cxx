#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <complex>
#include <numeric>
#include <ext/numeric>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <functional>
#include <utility>
#include <vector>
#include <list>
#include <queue>
#include <bitset>

using namespace std;
using namespace __gnu_cxx;

typedef unsigned long long ullong;
typedef long long llong;
typedef list<int> EdgeList;
typedef vector<EdgeList> AdjList;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define FOR_EDGE(adj,v,it) for (EdgeList::iterator it = adj[v].begin(); \
    it != adj[v].end(); ++it)
#define FOR(v, it) for (auto it = v.begin(); it != v.end(); ++it)

int arr[1024];
int n;
int cyc[1024];
int n_cyc;
int cyc_best[1024];
int cyc_2best[1024];
int cyc_len[1024];

int cyc_best_path[1024];
int cyc_2best_path[1024];

int cyc_subid[1024];

int path_id[1024];
int n_paths;

int pred[1024];

void dfs(int v, int p) {
  pred[v] = p;
  if (pred[arr[v]] == -1) {
    if (cyc[v] == -1) {
      dfs(arr[v], v);
    }
  } else {
    // we hit a cycle
    cyc[arr[v]] = n_cyc;

    for (int o = v; o != arr[v]; o = pred[o]) {
      cyc[o] = n_cyc;
    }

    n_cyc += 1;
  }
}

int main() {
  int n_cases;
  scanf("%d", &n_cases);
  for (int ctr = 0; ctr < n_cases; ++ctr) {
    scanf("%d", &n);
    AdjList adj;
    adj.resize(n);

    fill(cyc, cyc+n, -1);
    fill(cyc_best, cyc_best+n, 0);
    fill(cyc_2best, cyc_2best+n, 0);
    fill(cyc_len, cyc_len+n, 0);
    fill(path_id, path_id+n, -1);
    fill(cyc_best_path, cyc_best_path+n, -1);
    fill(cyc_2best_path, cyc_2best_path+n, -1);
    fill(cyc_subid, cyc_subid+n, -1);
    n_paths = 0;
    n_cyc = 0;
    
    for (int i = 0; i < n; ++i) {
      scanf("%d", &arr[i]);
      --arr[i];
    }

    for (int i = 0; i < n; ++i) {
      fill(pred, pred+n, -1);
      dfs(i, -1);
    }

    for (int i = 0; i < n; ++i) {
      if (cyc[i] != -1) {
        cyc_len[cyc[i]] += 1;
      }
    }

    for (int i = 0; i < n_cyc; ++i) {
      int subid = 0;
      for (int j = 0; j < n; ++j) {
        if (cyc[j] == i) {
          cyc_subid[j] = subid++;
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      if (cyc[i] != -1) continue;
      
      fill(pred, pred+n, -1);
      int v = i;
      while (cyc[v] == -1) {
        pred[arr[v]] = v;
        v = arr[v];
      }
      v = pred[v];

      int id;
      if (path_id[v] == -1) {
        id = n_paths;
        path_id[v] = id;
        
        n_paths += 1;
      } else {
        id = path_id[v];
      }

      while (v != i) {
        path_id[v] = id;
        v = pred[v];
      }
      path_id[v] = id;
    }

    #ifdef DEBUG
    puts("path finding");
    #endif
    for (int i = 0; i < n; ++i) {
      if (cyc[i] != -1) continue;
      
      int len = 0;
      int v = i;
      while (cyc[v] == -1) {
        len += 1;
        v = arr[v];
      }
      int subid = cyc_subid[v];
      
      int cycle = cyc[v];
      len += cyc_len[cycle];
      if (cyc_len[cycle] != 2) continue;

      #ifdef DEBUG
      printf("%d: %d %d\n", i, len, cycle);
      #endif

      if (subid == 0) {
        if (len >= cyc_best[cyc[v]]) {
          cyc_best[cyc[v]] = len;
          cyc_best_path[cycle] = path_id[i];
        }
      } else {
        assert(subid==1);
        if (len > cyc_2best[cyc[v]]) {
          cyc_2best[cyc[v]] = len;
          cyc_2best_path[cycle] = path_id[i];
        }
      }

    }

    int opt1 = *max_element(cyc_len, cyc_len + n_cyc);
    int opt2 = 0;
    for (int i = 0; i < n_cyc; ++i) {
      if (cyc_len[i] == 2) {
        if (cyc_best[i] == 0 && cyc_2best[i] == 0) {
          opt2 += 2;
        } else {
          if (cyc_2best[i] == 0) {
            opt2 += cyc_best[i];
          } else if (cyc_best[i] == 0) {
            opt2 += cyc_2best[i];
          } else {
            opt2 += cyc_best[i] + cyc_2best[i] - 2;
          }
        }
      }
    }

    #ifdef DEBUG
    puts("final");
    printf("choices: %d %d\n", opt1, opt2);
    for (int i = 0; i < n; ++i) {
      printf("%d: %d %d\n", i, cyc[i], path_id[i]);
    }
    puts("CYCLES");
    for (int i = 0; i < n_cyc; ++i) {
      printf("%d: %d %d %d %d %d\n", i, cyc_len[i], cyc_best[i], cyc_best_path[i], cyc_2best[i], cyc_2best_path[i]);
    }
    #endif

    printf("Case #%d: %d\n", ctr+1, max(opt1, opt2));
  }
  return 0;
}
