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

int T;
string C, J;

bool ok(int v, string V) {
  for(int i=SIZE(V)-1; i>=0; --i) {
    if ( (V[i] != '?') && (V[i]-'0' != (v%10))) return false;
    v /= 10;
  }
  if (v > 0) return false;
  return true;
}

int main(void) {
  cin >> T;
  REP(t, T) {
    cin >> C >> J;
    int diff = 100000;
    int bc, bj;
    REP(c, 1000)
      REP(j, 1000) {
        if (!ok(c, C) || !ok(j, J)) continue;
        if (abs(c-j) < diff) {
          diff = abs(c-j);
          bc = c;
          bj = j;
        }
      }
    for(int i=SIZE(C)-1; i>=0; --i) {
      C[i] = bc % 10 + '0';
      bc /= 10;
    }
    for(int i=SIZE(J)-1; i>=0; --i) {
      J[i] = bj % 10 + '0';
      bj /= 10;
    }
    cout << "Case #" << t+1 << ": " << C << " " << J << endl;
  }
  return 0;
}
