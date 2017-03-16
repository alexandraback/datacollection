#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

int solve() {
  int N;
  scanf("%d", &N);
  vector<ll> start;
  vector<ll> duration;
  REP(i,N) {
    int D, H, M;
    scanf("%d%d%d", &D, &H, &M);
    REP(j,H) {
      start.push_back(D);
      duration.push_back(M + j);
    }
  }

  if (duration.size() < 2 || duration[0] == duration[1]) {
    return 0;
  }

  ll d1 = duration[0];
  ll d2 = duration[1];
  ll s1 = start[0];
  ll s2 = start[1];
  if (d1 > d2) {
    swap(d1, d2);
    swap(s1, s2);
  }
  ll fasterAtStart1 = (360 - s1) * d1;
  ll fasterAtStart2 = fasterAtStart1 + d1 * 360;
  ll slowerAtStart = (360 - s2) * d2;
  if (fasterAtStart2 <= slowerAtStart) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  int T;
  scanf("%d", &T);
  REP(t,T) {
    printf("Case #%d: %d\n", t+1, solve());
  }
  return 0;
}
