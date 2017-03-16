#include <algorithm>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
#include <cstring>

#define SIZE(s) ((int)((s).size()))
#define FOREACH(it,vec) for(typeof((vec).begin())it=(vec).begin();it!=(vec).end();++it)
#define REP(i,n) for(int i=0;i<(int)(n);++i)

using namespace std;

int N,T,M,x;
vector<vector<int> > E;

bool search(int from) {
  vector<bool> vis(N,false);
  queue<int> Q;
  Q.push(from);
  vis[from] = true;

  while(!Q.empty()) {
    int v = Q.front(); Q.pop();
    REP(i,SIZE(E[v])) {
      int w = E[v][i];
      if (vis[w]) return true;
      vis[w] = true;
      Q.push(w);
    }
  }
  return false;
}

int main(void) {
  cin >> T;
  REP(t,T) {
    E.resize(0);
    cin >> N;
    E.resize(N);

    REP(n,N) {
      cin >> M;
      set<int> S;
      REP(m,M) {
        cin >> x;
        --x;
        S.insert(x);
      }
      E[n] = vector<int>(S.begin(),S.end());
    }

    bool ok = false;
    REP(i,N) {
      if (search(i)) { ok = true; break; }
    }
    cout << "Case #" << t+1 << ": ";
    if (ok) 
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}
