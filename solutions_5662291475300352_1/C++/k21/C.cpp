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
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
  REP(i,N) {
    int D, H, M;
    scanf("%d%d%d", &D, &H, &M);
    REP(j,H) {
      q.push({(360LL - D) * (M+j), (int)start.size()});
      start.push_back(D);
      duration.push_back(M + j);
    }
  }
  
  N = start.size();
  vector<bool> seen(N, false);

  int best = N;
  int current = N;
  ll prevTime = 0;
  REP(ei, 3 * N) {
    ll time;
    int i;
    tie(time, i) = q.top();
    if (time != prevTime) {
      best = min(best, current);
    }
    prevTime = time;
    q.pop();
    q.push({time + 360LL * duration[i], i});
    if (!seen[i]) {
      --current;
      seen[i] = true;
    } else {
      ++current;
    }
  }

  return best;
}

int main() {
  int T;
  scanf("%d", &T);
  REP(t,T) {
    printf("Case #%d: %d\n", t+1, solve());
  }
  return 0;
}
