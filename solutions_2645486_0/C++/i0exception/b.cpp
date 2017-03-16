#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<list>
#include<stack>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cassert>
#define CLRM(x) memset(x,-1,sizeof(x))
#define CLR(x) memset(x,0,sizeof(x))
#define ALL(x) x.begin(),x.end()
#define GI(x) scanf("%d", &x);
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FOR(i, start, end) for(int i = start; i < end; i++)
#define PB push_back
#define MP make_pair
#define VI vector<int> 
#define VVI vector<vector<int> >
#define PII pair<int,int>
#define SZ(x) (int)x.size()
#define LL long long
#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a,b) (a)>(b)?(a):(b)
#define LMAX 1000000000000000000LL
#define IMAX 1000000000
using namespace std;

#define MX 12
int v[MX];
int N;
int E, R;
LL dp[MX][MX];

LL solve(int pos, int energy) {
  //cout<<pos<<" "<<energy<<endl;
  if (pos >= N) {
    return 0;
  }
  LL& ret = dp[pos][energy];
  if (ret != -1) {
    return ret;
  }
  ret = 0;
  FORN(i, energy+1) {
    ret = MAX(ret, solve(pos+1, MIN(E, energy-i+R)) + v[pos]*i);
  }
  //cout<<pos<<" "<<energy<<" "<<ret<<endl;
  return ret;
}

LL getans() {
  CLRM(dp);
  LL ans = solve(0, E);
  return ans;
}

int main() {
  int T;
  GI(T);
  FORN(i, T) {
    GI(E);GI(R);GI(N);
    FORN(j, N) {
      GI(v[j]);
    }
    LL ans = getans();
    printf("Case #%d: %lld\n", i+1, ans);
  }
  return 0;
}
