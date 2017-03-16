
#include <cassert>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <limits>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
using namespace std;
typedef long long ll;

// (左側の種類数 + 右側の種類数 - 最大マッチングの大きさ) が fakeでないのの最小数

// 0 <= vL < nL
// 0 <= vR < nR

class Matching {
private:
  int nL, nR;
  vector<vector<int> > g; // g[vL][i] = vR
  vector<int> matching, dist;
  bool dfs(int vL) {
    REP(i, g[vL].size()){
      int vR = g[vL][i];
      int nextL = matching[vR];
      if(nextL == -1 || (dist[nextL] == dist[vL] + 1 && dfs(nextL))){
        matching[vR] = vL;
        matching[vL] = vR;
        return true;
      }
    }
    dist[vL] = -3;
    return false;
  }
  bool bfs() {
    bool res = false;
    queue<int> q;
    dist.assign(nL, -3);
    REP(vL, nL)
      if(matching[vL] == -1)
        q.push(vL), dist[vL] = 0;
    while(!q.empty()){
      int vL = q.front(); q.pop();
      REP(i, g[vL].size()){
        int nextL = matching[g[vL][i]];
        if(nextL == -1)
          res = true;
        else if(dist[nextL] == -3)
          q.push(nextL), dist[nextL] = dist[vL]+1;
      }
    }
    return res;
  }
public:
  Matching(int nL, int nR) : nL(nL), nR(nR), g(nL) {}
  void addEdge(int vL, int vR) { g[vL].push_back(nL+vR); }
  int match() {
    int res = 0;
    for(matching.assign(nL+nR, -1); bfs(); )
      REP(vL, nL)
        res += matching[vL] == -1 && dfs(vL);
    return res;
  }
  int partner(int vR) { return matching[nL+vR]; }
};



char buf[2][50];
int es[2000][2];

int main(void) {
  
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase) {
    int nEdge;
    scanf("%d", &nEdge);
    map<string, int> name2id[2];
    REP(iEdge, nEdge) {
      scanf("%s%s", buf[0], buf[1]);
      REP(i, 2) {
        string s(buf[i]);
        if(name2id[i].count(s) == 0) {
          int size = name2id[i].size();
          name2id[i][s] = size;
        }
        es[iEdge][i] = name2id[i][buf[i]];
      }
    }
    Matching m(name2id[0].size(), name2id[1].size());
    REP(iEdge, nEdge) {
      m.addEdge(es[iEdge][0], es[iEdge][1]);
    }
    int res = nEdge - (name2id[0].size() + name2id[1].size() - m.match());
    printf("Case #%d: %d\n", iCase+1, res);
  }
  return 0;
}
