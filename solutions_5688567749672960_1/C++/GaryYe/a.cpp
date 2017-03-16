#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N;
ll g[20];

int T;
int d[20];
ll rev(ll x){
  ll y=0;
  while(x > 0){
    y = y * 10 + (x % 10);
    x /= 10;
  }
  return y;
}

ll solve(){
  if(N <= 10)
    return N;
  ll x = N;
  ll res = 10;
  ll cur = 10;
  int n = 0;
  while(x > 0){
    d[n++] = x % 10;
    x /= 10;
  }

  for(int i = 2; i <= n - 1; i++){
    res += g[(i + 1) / 2] + 1 + g[i / 2];
    cur = cur * 10;
  }

  if(cur == N)
    return res;
  // printf("res = %lld\n", res);
  ll res2 = N - cur;
  for(int i = n - 1; i >= 1; i--){
    ll tak = 0;
    for(int j = n - 1; j >= i; j--)
      tak = tak * 10 + d[j];
    ll oth = 0;
    for(int j = i - 1; j >= 0; j--)
      oth = oth * 10 + d[j];
    if(oth == 0)
      tak = tak - 1;
    tak = rev(tak);
    ll r = tak;
    x = rev(cur + tak);
    r ++;
    r += N - x;
    // printf("r = %lld x = %lld cur = %lld tak = %lld\n", r, x, cur, tak);
    res2 = min(res2, r);
  }
  return res + res2;
}

int main(){
  scanf("%d", &T);
  g[0] = 0;
  for(int i = 1; i <= 16; i++)
    g[i] = g[i - 1] * 10 + 9;

  for(int cn = 1; cn <= T; cn++){
    scanf("%lld", &N);
    printf("Case #%d: %lld\n", cn, solve());
  }
  return 0;
}
