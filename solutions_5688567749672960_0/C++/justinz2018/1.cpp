#include <bits/stdc++.h>
#include <unordered_map>
#define pb push_back
using namespace std;

typedef long long ll;
ll memo[(int)1e6+5];
ll rev(ll a) {
   ll ret = 0;
   bool b = 0;
   while(a>0) {
      if(!b && !(a%10)) return 1e15;
      ret = ret*10+(a%10);
      a/=10;
      b=1;
   }
   return ret;
}
ll t;
ll dp(ll i, ll c=0) {
  // cout << i << " " << c << endl;
   if(i>t || i<1) return 1e15;
   if(memo[i]){
   return memo[i]+c;}
   if(i==1) return c;
   ll l = rev(i);
   memo[i] = min( dp(i-1, c+1), (l<i?dp(l, c+1):(ll)1e15))-c;
   return memo[i]+c;
}
int main() {
   ios_base::sync_with_stdio(0);
  freopen("A-small-attempt2.in", "r", stdin);
  freopen("1.out", "w", stdout);
   ll t2; cin >> t2; 
   for(int a=1; a<=t2; a++) {
      cin >> t;
      cout << "Case #" << a << ": " << dp(t)+1 << endl;
 //  memset(memo, 0, sizeof memo);
   }
}
