#include <bits/stdc++.h>

#define REP(i,n)    for(int i=0;i<(n);++i)

using namespace std;
using ld = long double;

int main() {
  int t;
  cin>>t;
  REP(cnt,t) {
    vector<ld> v(26);
    string s;
    cin>>s;
    REP(i,s.size()) {
      ++v[s[i] - 'A'];
    }
    vector<vector<ld>> vnum(26,vector<ld>(10));
    vector<string> numstr = {
      "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
    };
    REP(i,10){
      REP(j,numstr[i].size()) {
        ++vnum[numstr[i][j] - 'A'][i];
      }
    }
    REP(i,10) {
      ld mx = 0;
      int mxj = i;
      for (int j = i; j < 26; ++j) {
        if (abs(vnum[j][i]) > mx) {
          mx = abs(vnum[j][i]);
          mxj = j;
        }
      }
      if (mxj != i) {
        swap(vnum[i], vnum[mxj]);
        swap(v[i], v[mxj]);
      }
      ld div = vnum[i][i];
      for (int j = i; j < 10; ++j) {
        vnum[i][j] /= div;
      }
      v[i] /= div;
      for (int j = 0; j < 26; ++j) {
        if (i == j) continue;
        ld coeff = vnum[j][i];
        for (int k = i; k < 10; ++k) {
          vnum[j][k] -= coeff * vnum[i][k];
        }
        v[j] -= coeff * v[i];
      }
    }
    cout << "Case #" << (cnt+1) << ": ";
    REP(i,10) {
      if (round(v[i]) > 0) cout << string(round(v[i]), '0'+i);
    }
    cout << endl;
  }
  return 0;
}
