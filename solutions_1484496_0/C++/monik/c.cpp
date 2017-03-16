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

vector<long long> V;
map<long long,long long> M;
int T,N;
long long x,y;

int main(void) {
  cin >> T;
  REP(t,T) {
    V.resize(0);
    M.clear();

    cin >> N;
    V.resize(N,0);
    REP(n,N) cin >> V[n];

    bool ok = false;
    for(long long i=1;i<(1LL<<N);++i) {
      long long s=0;
      REP(j,N) if ((i&(1LL<<j))!=0) {
        s+=V[j];
      }
      if (M.find(s)!=M.end()) {
        ok = true; 
        x = i;
        y = M[s];
        break;
      }
      else M[s] = i;
    }

    cout << "Case #" << t+1 << ":" << endl;
    if (ok) {
      vector<int> v1,v2;
      REP(i,N) {
        if ((x&(1LL<<i))!=0) v1.push_back(V[i]);
        if ((y&(1LL<<i))!=0) v2.push_back(V[i]);
      }
      REP(i,SIZE(v1)) cout << v1[i] << (i==SIZE(v1)-1?"\n":" ");
      REP(i,SIZE(v2)) cout << v2[i] << (i==SIZE(v2)-1?"\n":" ");
    }
    else {
      cout << "Impossible" << endl;
    }

    
  }
  return 0;
}
