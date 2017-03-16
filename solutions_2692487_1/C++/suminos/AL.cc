#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
typedef long long ll;
const int inf = (1<<28);

int solve(ll A, const vector<ll> &v) {
  const int N = v.size();
  if(A == 1) return N;

  int ans = inf;

  int op = 0;
  rep(i, N) {
    ans = min(ans, N-i+op);
    
    while(v[i] >= A) {
      A += A - 1;
      op++;
    }
    
    A += v[i];
  }

  return min(op, ans);
}

int main() {
  int T; cin >> T;
  for(int t=1; t<=T; t++) {
    ll A; int N; cin >> A >> N;
    vector<ll> v(N); rep(i, N) cin >> v[i];
    sort(all(v));
    cout << "Case #" << t << ": " << solve(A, v) << endl;
  }
}
