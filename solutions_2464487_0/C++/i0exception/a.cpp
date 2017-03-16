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
#define LL unsigned long long
#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a,b) (a)>(b)?(a):(b)
#define LMAX 1000000000000000000LL
#define IMAX 1000000000
using namespace std;

LL needed(LL r, LL num) {
  return 2LL*r*num + num + (num*(num-1))*2;
}

LL solve(LL r, LL t) {
  LL lo = 0, hi = (1LL<<63);
  while (hi - lo > 5) {
    //cout<<lo<<" "<<hi<<endl;
    LL mid = (hi+lo)/2;
    LL x = needed(r, mid);
    if (x > t) {
      hi = mid-1;
    } else {
      lo = mid;
    }
  }
  while (hi != lo) {
    if (needed(r, hi) <= t)
      break;
    hi--;
  }
  return hi;
}

int main() {
  int T;
  GI(T);
  FORN(i, T) {
    LL r, t;
    cin >> r >> t;
    printf("Case #%d: %lld\n", i+1, solve(r, t));
  }
  return 0;
}
