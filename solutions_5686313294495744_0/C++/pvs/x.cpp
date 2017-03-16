#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> p_t;

int f(vector<p_t> v) {
  int w = v.size();
  int maxm = 1 << w;
  int r = w;

  int lo[32]={0}, hi[32]={0};
  for (const auto &p : v) { lo[p.first]=1; hi[p.second]=1; }
  
  for (int m=1; m<maxm; ++m) {
    int tlo[32], thi[32];
    memcpy(tlo, lo, sizeof(lo));
    memcpy(thi, hi, sizeof(hi));
    int bc = 0;
    for (int i=0; i<w; ++i) {
      if ((1<<i) & m) {
        ++bc;
        tlo[v[i].first]=0;
        thi[v[i].second]=0;
      }
    }
    for (int i=0; i<32; ++i) if (tlo[i]) goto nxt;
    for (int i=0; i<32; ++i) if (thi[i]) goto nxt;
    if (bc < r) r=bc;
    nxt:;
  }
  return w-r;
}

int main() {
  int n; scanf("%d\n", &n);
  for (int i=0; i<n; ++i) {
    int m; scanf("%d\n", &m);
    vector<p_t> v;
    map<string, int> x;
    for (int j=0; j<m; ++j) {
      char a[21], b[21];
      scanf("%s\n", a); scanf("%s\n", b);
      if (x.find(a) == x.end()) { int sz = x.size(); x[a] = sz; }
      if (x.find(b) == x.end()) { int sz = x.size(); x[b] = sz; }
      v.push_back(p_t(x[a], x[b]));
    }
    printf("Case #%d: %d\n", i+1, f(v));
  }
}
