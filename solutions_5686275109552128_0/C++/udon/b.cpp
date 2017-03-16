#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF = 1 << 30;
#define PB push_back
#define sz(a) (a).size()
#define reps(i,n,m) for(int (i)=(n);(i)<int(m);++(i))
#define rep(i,n) reps(i,0,n)
#define N 1010
ll T;
ll cost[N];

int main(){
  cin >> T;
  reps(times, 1, T+1) {
    int d;
    vector<int> vec;
    int ans;
    int maxn = 0;
    cin >> d;
    rep(i, d) {
      int p;
      cin >> p;
      vec.PB(p);
      maxn = max(p, maxn);
    }
    ans = maxn;
    reps(mx, 1, maxn) {
      int sp = 0;
      rep(i, sz(vec)){
        int c = (int)(((double)vec[i] / (double)mx) + 0.999999);
        sp += c-1;
      }
      ans = min(ans, sp + mx);
    }
    printf("Case #%d: %d\n", times, ans);
  }
}
