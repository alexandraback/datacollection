#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
#include <string>
using namespace std;
const int MAXN = 1010;
int uN, vN; // u, v数目，要初始化！！！
bool g[MAXN][MAXN]; // g[i][j] 表示xi与yj相连
int xM[MAXN], yM[MAXN]; // 输出量
bool chk[MAXN]; // 辅助量检查某轮y[v]是否被check

bool SearchPath(int u){
  int v;
  for(v = 0; v < vN; v++)
  if(g[u][v] && !chk[v]) {
    chk[v] = true;
    if(yM[v] == -1 || SearchPath(yM[v])) {
      yM[v] = u; xM[u] = v;
      return true ;
    }
  }
  return false ;
}

int MaxMatch(){
  int u, ret = 0 ;
  memset(xM, -1, sizeof (xM));
  memset(yM, -1, sizeof (yM));
  for(u = 0; u < uN; u++)
  if(xM[u] == -1){
    memset(chk, false, sizeof (chk));
    if(SearchPath(u)) ret++;
  }
  return ret;
}

char stra[1000], strb[1000];
int main() {
  int T, tmp;
  scanf("%d", &T);

  for (int I = 1; I <= T; ++I) {
    int xx;
    scanf("%d", &xx);
    vector<string> va, vb;
    set<string> ca, cb;
    map<string, int> da, db;
    for (int i = 0; i < xx; ++i) {
      scanf("%s%s", stra, strb);
      va.push_back(stra);
      vb.push_back(strb);
      ca.insert(stra);
      cb.insert(strb);
    }
    int ii = -1;
    for (auto i: ca) da[i] = ++ii;
    ii = -1;
    for (auto i: cb) db[i] = ++ii;

    uN = da.size();
    vN = db.size();
    memset(g, 0, sizeof(g));
    // printf("==%d %d\n", uN, vN);
    for (int i = 0; i < xx; ++i) {
      g[da[va[i]]][db[vb[i]]] = 1;
      // printf("--%d %d\n", da[va[i]], db[vb[i]]);
    }
  
    printf("Case #%d: ", I);
    int ans = uN + vN - MaxMatch();
    printf(" %d", xx - ans);
    printf("\n");
  }
}
