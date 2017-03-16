#include <bits/stdc++.h>

using namespace std;

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1000000000;
const int MOD = INF + 7;
const int MAXN = 1010;

int v[MAXN];

int main(){
#ifndef ONLINE_JUDGE
   freopen("B-large.in","r",stdin);
   freopen("B-large.out","w",stdout);
#endif
   int casos;
   cin >> casos;
   for(int caso = 1 ; caso <= casos ; caso++){
      int n, maxi;
      cin >> n;
      maxi = 0;
      for(int i = 0 ; i < n ; i++){
         cin >> v[i];
         maxi = max(maxi, v[i]);
      }
      int ans = maxi;
      for(int h = 1 ; h <= maxi ; h++){
         int c = 0;
         for(int i = 0 ; i < n ; i++){
            c += (v[i] + h - 1) / h - 1; 
         }
         if(c + h < ans){
            ans = c + h;
         }
      }
      cout << "Case #"<< caso <<": " << ans << endl;
   }
   return 0;
}