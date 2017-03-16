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
bool palind(ll n){
  stringstream ss;
  ss << n;
  string t = ss.str();
  reverse(t.begin(), t.end());
  return t == ss.str();
}
vector<ll> num;
int count(ll n){
  return upper_bound(num.begin(), num.end(), n) - num.begin();
}

int main(){
  num.clear();
  for(ll i = 1; i * i <= 100000000000000; i++){
    if(palind(i) && palind(i * i)){
      num.push_back(i * i);
    }
  }
  int T;
  cin >> T;
  REP(CASE, T){
    printf("Case #%d: ", CASE + 1);
    ll A, B; cin >> A >> B;
    int ans = count(B) - count(A - 1);
    cout << ans << endl;
  }
  return 0;
}
