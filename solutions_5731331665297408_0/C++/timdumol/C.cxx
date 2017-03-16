#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <complex>
#include <numeric>
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

typedef unsigned long long ullong;
typedef long long llong;
typedef list<int> EdgeList;
typedef vector<EdgeList> AdjList;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define FOR_EDGE(adj,v,it) for (EdgeList::iterator it = adj[v].begin(); \
    it != adj[v].end(); ++it)

AdjList adj;

int main() {
  int n_cases;
  scanf("%d", &n_cases);
  vector<string> arr;
  int mat[64][64];
  char str[1024];
  for (int ctr = 0; ctr < n_cases; ++ctr) {
    memset(mat, 0, sizeof(mat));
    int n, m;
    scanf("%d %d", &n, &m);
    arr.clear();
    for (int i = 0; i < n; ++i) {
      scanf("%s", str);
      arr.push_back(string(str));
    }
    adj.clear();
    adj.resize(n);
    for (int j = 0; j < m; ++j) {
      int a, b;
      scanf("%d %d", &a, &b);
      --a; --b;
      mat[a][b] = mat[b][a] = 1;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    int perm[32];
    for (int i = 0; i < n; ++i) perm[i] = i;
    string best;
    do {
      list<int> st;
      string curr = arr[perm[0]];
      bool ok = true;
      st.push_back(perm[0]);
      for (int i = 1; i < n; ++i) {
        int u = st.back();
        while (st.size() > 1 && !mat[u][perm[i]]) {
          //printf("<%d> Popping %d\n", i, u);
          st.pop_back();
          u = st.back();
        }
        //printf("<%d> Trying %d\n", i, u);
        if (mat[u][perm[i]]) {
          st.push_back(perm[i]);
          curr += arr[perm[i]];
        } else {
          ok = false;
          break;
        }
      }
      if (ok) {
        if (best == "") best = curr;
        else if (curr < best) {
          best = curr;
        }
      }
    } while (next_permutation(perm, perm+n));
    printf("Case #%d: %s\n", ctr+1, best.c_str());
  }
  return 0;
}
