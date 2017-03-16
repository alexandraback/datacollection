#include <iostream>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>
#include <sstream>

using namespace std;

typedef long long ll;

string C, J;
string rC, rJ;
int mincost;

void dfs(int cc, int cj) {
  if(cc < C.size()) {
    if(C[cc] == '?') {
      for(int i = 0; i < 10; ++i) {
        C[cc] = i + '0';
        dfs(cc+1, cj);
      }
      C[cc] = '?';
    }
    else {
      dfs(cc+1, cj);
    }
  }
  else if(cj < J.size()) {
    if(J[cj] == '?') {
      for(int i = 0; i < 10; ++i) {
        J[cj] = i + '0';
        dfs(cc, cj+1);
      }
      J[cj] = '?';
    }
    else {
      dfs(cc, cj+1);
    }
  }
  else {
    istringstream sin(C + " " + J);
    int x , y;
    sin >> x >> y;
    int diff = abs(x - y);
    if(mincost > diff) {
      rC = C;
      rJ = J;
      mincost = diff;
    }
    else if(mincost == diff) {
      if(rC > C) {
        rC = C;
        rJ = J;
      }
      else if(rC == C) {
        rJ = min(rJ, J);
      }
    }
  }
}

int main(void){
  int T;
  cin >> T;
  for(int tt = 0; tt < T; ++tt) {
    cin >> C >> J;

    mincost = INT_MAX;
    dfs(0, 0);

    cout << "Case #" << tt+1 << ": " << rC << " " << rJ << endl;
  }

  return 0;
}
