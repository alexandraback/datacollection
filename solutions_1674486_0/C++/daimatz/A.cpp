#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
#include <complex>
#include <set>
#define DEBUG(x) cerr<<"line:"<<__LINE__<<", "<<#x" == "<<(x)<<endl;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(it,s) for(__typeof(s.begin()) it=s.begin();it!=s.end();it++)
#define ALLOF(a) a.begin(),a.end()
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

bool solve(vector<vector<int>> P, int start, int end) {
  bool flag = false;
  {
    set<int> visited;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
      int p = q.front(); q.pop();
      visited.insert(p);
      //DEBUG(p);
      for (int i = 0; i < (int)P[p].size(); i++) {
        if (P[p][i] != 0 && visited.find(P[p][i]) == visited.end()) {
          if (P[p][i] == end) {
            flag = true;
            P[p][i] = 0;
            break;
          }
          q.push(P[p][i]);
        }
      }
      if (flag) break;
    }
  }

  if (!flag) return false;

  {
    set<int> visited;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
      int p = q.front(); q.pop();
      visited.insert(p);
      for (int i = 0; i < (int)P[p].size(); i++) {
        if (P[p][i] != 0 && visited.find(P[p][i]) == visited.end()) {
          if (P[p][i] == end) {
            return true;
          }
          q.push(P[p][i]);
        }
      }
    }
    return false;
  }
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    int N;
    scanf("%d", &N);
    vector<int> M(N+1);
    vector<vector<int>> P(N+1);
    for (int i = 0; i < N; i++) {
      int M;
      scanf("%d", &M);
      vector<int> tmp(M);
      for (int j = 0; j < M; j++) {
        scanf("%d", &tmp[j]);
      }
      P[i+1] = tmp;
    }
    //DEBUG(P[1][0]); DEBUG(P[2][0]); break;
    bool flag = false;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (i != j && solve(P, i, j)) {
          flag = true;
          break;
        }
      }
      if (flag) break;
    }
    printf("Case #%d: ", t);
    if (flag) printf("Yes\n");
    else printf("No\n");
  }
  return 0;
}
