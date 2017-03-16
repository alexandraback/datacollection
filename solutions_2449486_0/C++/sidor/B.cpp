#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int,int> PI;

int ntc;

const int MN = 200; 
const int MV = 100;
char x[MN][MN];


bool fp(PI a, PI b) {
  return x[a.first][a.second] < x[b.first][b.second];
}

void solve(int c) {
  int n,m;
  scanf("%d%d", &n,&m);
  vector<PI> pos;
  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      scanf("%d", &x[i][j]);
      pos.push_back(PI(i,j));
    }
  }
  sort(pos.begin(), pos.end(), fp);
  bool canwe = true;
  for(int i=0; i< pos.size() && canwe; ++i) {
    int a=pos[i].first, b = pos[i].second;
    if(x[a][b] == -1) continue;
    int v = x[a][b];
    bool okH = true, okV = true;
    for(int i=0; i<m; ++i) {
      if (x[a][i] != -1 && x[a][i] != v) okH = false;
    }
    for(int i=0; i<n; ++i) {
      if (x[i][b] != -1 && x[i][b] != v) okV = false;
    }
    if(!okH && !okV) {
      canwe = false;
      break;
    } else if(okH) {
      for(int i=0; i <m; ++i) x[a][i] = -1;
    } else if(okV) {
      for(int i=0; i<n; ++i) x[i][b] = -1;
    }
  }

  printf("Case #%d: %s\n", c, canwe ? "YES" : "NO" );
}



int main() {
  scanf("%d", &ntc);
  for(int i=1; i<=ntc; ++i) {
    solve(i);
  }
}
