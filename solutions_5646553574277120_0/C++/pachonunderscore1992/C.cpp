#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1000000000;
const int MOD = INF + 7;
const int MAXN = 110;

int c, d, v;
int a[MAXN];
bool dp[MAXN];
bool used[MAXN];

int solve(){
   int ans = 0;
   while( true ){
      memset(dp, 0, sizeof dp);
      dp[0] = 1;
      for(int i = 0 ; i < d ; i++){
         for(int j = v ; j >= a[i] ; j--){
            dp[j] |= dp[j-a[i]];
         }
      }
      bool sw = true;
      int x = 0;
      for(int i = 0 ; i <= v && sw ; i++){
         sw &= dp[i];
         if(!sw) x = i;
      }
      if(sw) break;
      a[d] = x;
      d++;
      used[x] = 1;
      ans++;
   }
   return ans;
}

int main(){
#ifndef ONLINE_JUDGE
   // freopen("in","r",stdin);
   freopen("C-small-attempt1x.in","r",stdin);
   freopen("C-small-attempt1x.out","w",stdout);
#endif
   int casos;
   cin >> casos;
   for (int caso = 1 ; caso <= casos ; caso++){
      cin >> c >> d >> v;
      memset(used, 0, sizeof used);
      for(int i = 0 ; i < d ; i++){
         cin >> a[i];
         used[a[i]] = 1;
      }
      cout << "Case #" << caso << ": " << solve() << endl;
   }
   return 0;
}