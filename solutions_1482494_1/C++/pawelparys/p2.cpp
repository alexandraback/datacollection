#include <string>
#include <vector>
 
#include <cmath> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
 
using namespace std;
 
#define REP(a,n) for(int a=0; a<(n); ++a)
#define FOR(a,b,c) for(int a=(b); a<=(c); ++a)
#define FORD(a,b,c) for(int a=(b); a>=(c); --a)

#define INF 1000000000

#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
template<class T>
inline int size(const T&t){return t.size();}
 
//////////////////////////////////////////

int N,ai[1000], bi[1000], rozw[1000];
int ile, wyn;

int main() {
  int TT;
  scanf("%d", &TT);
  REP(tt, TT) {
    scanf("%d", &N);
    ile = wyn = 0;
    REP(a, N) {
      scanf("%d%d", &ai[a], &bi[a]);
      rozw[a] = 0;
    }
    while (wyn<2*N) {
      int pam = wyn;
      int best = -1;
      REP(a, N) {
        if (bi[a]<=wyn && rozw[a]<2) {
          wyn += 2-rozw[a];
          rozw[a] = 2;
          ++ile;
        }
        if (!rozw[a] && ai[a]<=wyn)
          if (best<0 || bi[a]>bi[best])
            best = a;
      }
      if (pam!=wyn) 
        continue;
      if (best<0)
        break;
      ++wyn;
      ++ile;
      rozw[best] = 1;
    }
    if (wyn<2*N)
      printf("Case #%d: Too Bad\n", tt+1);
    else
      printf("Case #%d: %d\n", tt+1, ile);
  }
}
