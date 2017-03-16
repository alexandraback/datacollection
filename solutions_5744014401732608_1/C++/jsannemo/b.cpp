#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < int(b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define D(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tc) {
  printf("Case #%d: ", tc);
  ll B, M;
  scanf("%lld%lld", &B, &M);
  if (M > (1LL << (B - 2))) printf("IMPOSSIBLE\n");
  else {
    printf("POSSIBLE\n");
    ll at = 1;
    rep(i,0,B-3) at *= 2;
    printf("0");
    rep(i,0,B-1) {
      if (M >= at) {
        printf("1");
        M -= at;
      } else {
        printf("0");
      }
      at /= 2;
      if (at == 0) at = 1;
    }
    printf("\n");
    rep(i,1,B) {
      rep(j,0,i+1) printf("0");
      rep(j,i+1,B) printf("1");
      printf("\n");
    }
  }
}

int main() {
  int N;
  scanf("%d", &N);
  rep(i,1,N+1) solve(i);
}
