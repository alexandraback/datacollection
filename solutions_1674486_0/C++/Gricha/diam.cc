#include <algorithm>
#include <cassert>
#include <cstdio>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define ASSERT_ for (;;) {}
#define PII pair<int, int>

#define REP(i,n)    for(int i=0; i<(n); ++i)
#define FOR(i,p,k)  for(int i=(p); i<=(k); ++i)
#define FORD(i,p,k) for(int i=(p); i>=(k); --i)
using namespace std;

#define N_MAX 1000000

int n;
vector<int> neigh[N_MAX];

int DFS(int x){
  set<int> visited;
  stack<int> magazine;
  REP(j, neigh[x].size())
    magazine.push(neigh[x][j]);
  visited.insert(x);
  while (!magazine.empty()){
    int where = magazine.top();
    magazine.pop();
    if (visited.count(where) > 0)
      return 1;
    visited.insert(where);
    REP(j,neigh[where].size())
      magazine.push(neigh[where][j]);
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  int ntestcase;
  cin >> ntestcase;
  for (int test_id = 1; test_id <= ntestcase; test_id++) {
    cin >> n;
    REP(i,n) neigh[i].clear();
    int k, dummy;
    REP(i,n){
      cin >> k;
      REP(j,k){
        cin >> dummy;
        --dummy;
        neigh[i].push_back(dummy);
      }
    }
    int retval = 0;
    REP(i,n)
      retval += DFS(i);
    if (retval)
    printf("Case #%d: Yes\n", test_id);
    else
    printf("Case #%d: No\n", test_id);

  }

  return 0;
}
