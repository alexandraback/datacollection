#include <algorithm>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

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

int N,M,T;
int x,y;  
vector<vector<int> > E;
vector<string> Z;
vector<int> p;

string best;

bool is_edge(int a, int b) {
  REP(i,SIZE(E[a])) if (E[a][i] == b) return true;
  return false;
}

int main(void) {
  cin >> T;
  REP(t,T) {
    cin >> N >> M;
    E.resize(0);
    E.resize(N);
    Z.resize(0);
    Z.resize(N);
    p.resize(0);
    p.resize(N);

    best = string(N*5, '9');

    REP(n,N) { cin >> Z[n]; p[n] = n; }
    REP(m,M) {
      cin >> x >> y;
      --x; --y;
      E[x].push_back(y);
      E[y].push_back(x);
    }
    do {
      stack<int> S;
      S.push(0);
      for(int i = 1; i < SIZE(p); ++i) {
        bool found = false;
        while(!S.empty()) {
          if (is_edge(p[S.top()], p[i])) {
            S.push(i);
            found = true;
            break;
          } else {
            S.pop();
          }
          if (found) continue;
        }
      }
      if (!S.empty()) {
        string s = "";
        REP(i, SIZE(p)) s += Z[p[i]];
        if (s < best) best = s;
      }
    } while(next_permutation(p.begin(), p.end()));

    cout << "Case #" << t + 1 << ": " << best << endl;
  }
  return 0;
}
