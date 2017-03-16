#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <complex>
#include <string>
#include <stdint.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define rep(i,m,n) for(int i = m; i < (int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALLOF(c) (c).begin(), (c).end()

vector<vector<int> > g;
vector<int> matching;
vector<bool> visited;

bool augment(int left){
  if(left < 0) return true;
  if(visited[left]) return false;
  visited[left] = true;
  REP(i, g[left].size()){
    int right = g[left][i];
    if(augment(matching[right])){
      matching[right] = left;
      return true;
    }
  }
  return false;
}

int main(){
  int T;
  cin >> T;
  REP(i, T){
    int E, Va, Vb;
    cin >> E;
    g.clear();
    g.resize(E * 2);
    map<string, int> a, b;
    REP(j, E){
      string p, q;
      int r, s;
      cin >> p >> q;
      if(a.find(p) == a.end()){
        r = a.size();
        a[p] = r;
      }else{
        r = a[p];
      }
      if(b.find(q) == b.end()){
        s = b.size();
        b[q] = s;
      }else{
        s = b[q];
      }
      g[r].push_back(E + s);
    }
    Va = a.size();
    Vb = b.size();

    int match = 0;
    matching.assign(E * 2, -1);
    REP(j, Va){
      visited.assign(E * 2, false);
      if(augment(j)){
        match++;
      }
    }
    printf("Case #%d: %d\n", i+1, E-Va-Vb+match);
  }

  return 0;
}

