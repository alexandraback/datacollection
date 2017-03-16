#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ll;

int solve(ll a, ll b){
  ll g = __gcd(a,b);
  a/=g;
  b/=g;
  int ans = 0;
  while(a < b){
    if(b%2LL) return -1;
    b /= 2LL;
    ans++;
  }

  if(a==1&&b==1) return ans;
  int tmp = solve(a-b,b);
  return (tmp==-1?-1:ans);
}

int main(){
  int tc;
  cin >> tc;
  for(int x = 0; x < tc; x++){
    ll num, den;
    scanf("%Ld/%Ld",&num,&den);
    ll ans = solve(num,den);
    cout << "Case #" << x+1 << ": ";
    if(ans == -1) cout << "impossible" << endl;
    else cout << ans << endl;
  }
  return 0;
}
