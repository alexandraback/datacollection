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

int T, N, h, m, r, d;

int main(void) {
  cin >> T;
  REP(t, T) {
    cin >> N;
    vector<int> HP;
    vector<int> HS;
    vector<int> T(2, 0);
    r = 0;
    REP(n, N) {
      cin >> d >> h >> m;
      REP(i, h) {
        HP.push_back(d);
        HS.push_back(m+i);
      }
    }
    int a = 0;
    if (SIZE(HP) > 1) {
      m = 0;
      REP(i,2)
        T[i] = (360 - HP[i]) * HS[i];
      if (T[0] != T[1]) {
        if (T[0] > T[1]) {
          m = 1;
        } 
       T[m] += HS[m] * 360;
       if (T[m] <= T[1-m])
          a = 1;
      }
    }
    else {
      if (SIZE(HP) == 1 && HP[0] % 360 == 0) {
        a = 1;
      }
    }
    cout << "Case #" << (t+1) << ": " << a << endl;
  }
  return 0;
}
