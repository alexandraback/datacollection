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
long long J, P, S, K, best, best_i;

int main(void) {
  cin >> T;
  REP(t,T){
    cin >> J >> P >> S >> K;
    vector< pair<int, pair<int,int> > > pos;
    REP(i, J) REP(j, P) REP(k, S) pos.push_back( make_pair(i, make_pair(j,k)) );
    int p[J+1][P+1][S+1];

    best = 0;
    best_i = 0;
    
    for(long long i=0; i < (1LL << SIZE(pos)); ++i) {
      memset(p, 0, sizeof(p));
      bool ok = true;
      int x = 0;
      REP(j, SIZE(pos)) {
        if (i & (1LL << j)) {
          ++x;
          long long a = pos[j].first;
          long long b = pos[j].second.first;
          long long c = pos[j].second.second;

          ++p[a][b][S];
          ++p[a][P][c];
          ++p[J][b][c];
          
          if (p[a][b][S] > K || p[a][P][c] > K || p[J][b][c] > K) {
            ok = false;
            break;
          }
        }
      }
      if (ok && best < x) {
        best = x;
        best_i = i;
      }
    }
    cout << "Case #" << t+1 << ": " << best << endl;
    REP(i, SIZE(pos)) {
      if (best_i & (1LL << i)) {
        cout << pos[i].first+1 << " " << pos[i].second.first+1 << " " << pos[i].second.second+1 << endl;
      }
    }
  }
  return 0;
}
