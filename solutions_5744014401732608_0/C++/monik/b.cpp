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
long long B, M;

int main(void) {
  cin >> T;
  REP(t,T) {
    cin >> B >> M;
    
    int K[B][B];
    memset(K, 0, sizeof(K));
    for(int i=1; i<B; ++i)
      for(int j=i+1; j<B; ++j) K[i][j] = 1;

    cout << "Case #" << t+1 << ": ";

    if (B == 1) {
      if (M == 0)
        cout << "POSSIBLE\n0" << endl;
      else
        cout << "IMPOSSIBLE" << endl;
    }
    if (B > 1) {
      if ( M > (1LL << (B-2)) ) {
        cout << "IMPOSSIBLE" << endl;
      } else {
        for(int i=1;i<B-1;++i) {
          if (M >= (1LL << (B-i-2))) {
            K[0][i] = 1;
            M -= (1LL << (B-i-2));
          }
        }
        if (M > 0) K[0][B-1] = 1;
        cout << "POSSIBLE" << endl;
        REP(i,B) { REP(j,B) cout << K[i][j]; cout << endl; }
      }
    }
  }
  return 0;
}
