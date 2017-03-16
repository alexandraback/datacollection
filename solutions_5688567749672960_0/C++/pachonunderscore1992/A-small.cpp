#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1000000000;
const int MOD = INF + 7;
const int MAXN = 1000010;

int dp[MAXN];

int reverse(int x) {
   int r = 0;
   while( x ){
      r *= 10;
      r += x % 10;
      x /= 10;
   }
   return r;
}

int main(){
#ifndef ONLINE_JUDGE
   // freopen("in","r",stdin);   
   freopen("A-small-attempt0.in","r",stdin);
   freopen("A-small-attempt0.out","w",stdout);
#endif
   for(int i = 0 ; i < MAXN ; i++) {
      dp[i] = INF;
   }
   queue<int> q;
   dp[1] = 1;
   q.push(1);
   while( !q.empty() ){
      int x = q.front();q.pop();
      if(x < MAXN && dp[x + 1] == INF) {
         dp[x + 1] = dp[x] + 1;
         q.push(x + 1);
      }
      int r = reverse(x);
      if(r < MAXN && dp[r] == INF) {
         dp[r] = dp[x] + 1;
         q.push(r);
      }
   }

   int casos;
   cin >> casos;
   for(int caso = 1 ; caso <= casos ; caso++){
      int n;
      cin >> n;
      int ans = dp[n];
      cout << "Case #" << caso << ": " << ans << endl;
   }
   return 0;
}