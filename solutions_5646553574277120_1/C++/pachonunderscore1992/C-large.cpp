#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1000000000;
const int MOD = INF + 7;
const int MAXN = 110;

int c, d;
ll v;
ll a[MAXN];
bool dp[MAXN];
bool used[MAXN];

int solve(){
   int ans = 0;
   sort(a, a + d);
   ll sum = 0;
   ll y = 1;
   int i = 0;
   while( sum < v ){
      while(i < d && sum + 1LL >= a[i]) {
         sum += (ll)c * (ll)a[i];
         i++;
      }
      if(sum < y){
         sum += (ll)c * (ll)y;
         ans++;
      }
      y = sum + 1LL;
   }
   return ans;
}

int main(){
#ifndef ONLINE_JUDGE
   // freopen("in","r",stdin);
   freopen("C-large.in","r",stdin);
   freopen("C-large.out","w",stdout);
#endif
   int casos;
   cin >> casos;
   for (int caso = 1 ; caso <= casos ; caso++){
      cin >> c >> d >> v;
      for(int i = 0 ; i < d ; i++){
         cin >> a[i];
      }
      cout << "Case #" << caso << ": " << solve() << endl;
   }
   return 0;
}