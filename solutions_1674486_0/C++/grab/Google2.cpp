#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;
FILE *inf;
FILE *of;
int N;
vector<vector<int> > v;
vector<int> used;
int r = 0;
 
void dfs(int k, int p = -1) {
  used[k] = 1;
  for (int i = 0; i < v[k].size(); ++i) {
    
   
    if (used[v[k][i]] == 1) {
      if (p != v[k][i]) {
          r = 1;
          return;
      }
    }
    if (used[v[k][i]] == 0) {
      dfs(v[k][i], k);
    }
  }
}


int main() {
 inf = fopen("i.in", "r");
 of = fopen("o.out", "w");
 int num_tests, M;
 fscanf(inf, "%d", &num_tests);

 for (int t = 1; t <= num_tests; ++t) {
   r = 0;
   fscanf(inf, "%d", &N);
   v.clear();
   v.resize(N+1);
   used.clear();
   used.resize(N+1);
      for (int i = 1; i <= N; ++i) {
        fscanf(inf, "%d", &M);
        int a;
        for (int j = 1; j <= M; ++j) {
          fscanf(inf, "%d", &a);
          v[i].push_back(a);
          //v[a].push_back(i);
        }
      }
      for (int k = 1; k <= N; ++k) {
        used.clear();
        used.resize(N+1);
        dfs(k);
      } 

       fprintf(of, "Case #%d: ", t);
       if (r == 1) fprintf(of, "Yes\n");
       if (r == 0) fprintf(of, "No\n");

}
  fclose(inf);
  fclose(of);
  return 0;
}