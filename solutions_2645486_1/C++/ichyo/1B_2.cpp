#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main(){
  int T;
  cin >> T;
  REP(CASE, T){
    printf("Case #%d: ", CASE + 1);
    static ll dp[10001][10002] = {};
    memset(dp, 0, sizeof(dp));
    ll E, R, N;
    cin >> E >> R >> N;
    vector<ll> v(N);
    REP(i, N) cin >> v[i];
    ll ans = 0;
    for(int i = 0; i < N; i++){
      ll max_d = 0;
      for(int j = 0; j < i; j++){
        max_d = max(max_d, dp[j + 1][i]);
      }
      vector<pair<ll, ll> > ps;
      ps.push_back(make_pair(E, max_d + E * v[i]));
      for(int j = 0; j < i; j++){
        ll cur = (i - j) * R;
        if(cur >= E) cur = E;
        ps.push_back(make_pair(cur, dp[j + 1][N] + (cur - 0) * v[i]));
      }
      sort(ps.begin(), ps.end());
      reverse(ps.begin(), ps.end());
      vector<pair<ll, ll> > ps2;
      ps2.push_back(ps[0]);
      for(int j = 1; j < ps.size(); j++){
        if(ps2.back().second < ps[j].second) ps2.push_back(ps[j]);
      }
      dp[i + 1][N] = ps2.back().second;
      ans = max(ans, dp[i + 1][N]);
      for(int j = i + 1; j < N; j++){
        ll cur = E - (j - i) * R;
        if(cur < 0) continue;
        if(cur >= E) cur = E;
        int lb = 0, ub = ps2.size();
        while(ub - lb > 1){
          int mid = (lb + ub) / 2;
          if(ps2[mid].first >= cur){
            lb = mid;
          }else{
            ub = mid;
          }
        }
        dp[i + 1][j] = ps2[lb].second - cur * v[i];
        ans = max(ans, dp[i + 1][j]);
      }
    }
      cout << ans << endl;
  }
  
  return 0;
}
