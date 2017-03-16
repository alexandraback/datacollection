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

int T, N;
string s;

int main(void) {
  cin >> T;
  REP(t, T) {
    cin >> N;
    vector<string> S(N);
    vector<string> T(N);
    REP(i,N) {
      cin >> S[i];
      cin >> T[i];
    }
    int ide = 0;
    REP(i, 1<<N) {
      set<string> S1, T1;
      int cnt = 0;
      REP(j, N) 
        if ((i&(1<<j)) != 0) {
          S1.insert(S[j]);
          T1.insert(T[j]);
        }
        else {
          ++cnt;
        }
      bool ok = true;
      REP(j, N) {
        if (S1.find(S[j]) == S1.end() || T1.find(T[j]) == T1.end()) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ide = max(ide, cnt);
      }
    }
    cout << "Case #" << t+1 << ": " << ide << endl;

  }
  return 0;
}
