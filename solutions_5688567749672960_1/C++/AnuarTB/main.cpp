#include <bits/stdc++.h>

#define F first
#define S second
#define llong long long
#define ullong unsigned long long
#define pb push_back
#define mp make_pair
#define y1 asdasd

using namespace std;

const int MXN = (int)2e6 + 10;
const int INF = (int)1e9 + 7;
const double EPS = (double)1e-9;

int T;
llong n;
llong ans;

inline llong rev(llong x){
  llong res = 0LL;
  while(x){
    res = res * 10LL + (x % 10LL);
    x /= 10LL;
  }
  return res;
}

inline void solve(){
  ans = 0LL;
  while(n){
    if(rev(n) < n){
      ++ans;
      n = rev(n);
    }
    else {
      --n;
      ++ans;
    }
  }
}

int main(){
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  scanf("%d", &T);
  for(int test = 1; test <= T; ++test){
    scanf("%lld", &n);
    solve();
    printf("Case #%d: %lld\n", test, ans);
  }
  return 0;
}
