#include <cstdio>
#include <vector>

#define MAX(a,b) (a) > (b) ? (a) : (b)

using namespace std;

int main(int argc, char* argv[]) {
  FILE* f = fopen(argv[1], "r");
  int cnt, n, m, t;
  fscanf(f, "%d", &cnt);
  for(int q = 0; q < cnt; ++q) {
    fscanf(f, "%d %d", &n, &m);
    vector<vector<int> > data;
    vector<int> maxR(n, 0), maxC(m, 0);
    for(int i = 0; i < n; ++i) {
      data.push_back(vector<int>());
      for(int j = 0; j < m; ++j) {
        fscanf(f, "%d", &t);
        data[i].push_back(t);
        maxR[i] = MAX(maxR[i], t);
        maxC[j] = MAX(maxC[j], t);
      }
    }
    bool ok = true;
    for(int i = 0; i < n && ok; ++i) {
      for(int j = 0; j < m && ok; ++j) {
        ok = data[i][j] == maxR[i] || data[i][j] == maxC[j];
      }
    }
    printf("Case #%d: %s\n", q + 1, ok ? "YES" : "NO");
  }
}

