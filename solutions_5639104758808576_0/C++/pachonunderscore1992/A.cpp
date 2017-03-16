#include <bits/stdc++.h>

using namespace std;

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1000000000;
const int MOD = INF + 7;
const int MAXN = 100010;

int main(){
#ifndef ONLINE_JUDGE
   freopen("A-small-attempt0.in","r",stdin);
   freopen("A-small-attempt0.out","w",stdout);
#endif
   int casos, n, ans, c, r;
   string s;
   cin >> casos;
   for(int caso = 1 ; caso <= casos ; caso++){
      cin >> n >> s;
      ans = c = 0;
      for(int i = 0 ; i <= n ; i++){
         if(s[i] != '0'){  
            if(c < i){
               r = i - c;
               ans += r;
               c += r;
            }
            c += (s[i] - '0');
         }
      }
      cout << "Case #"<< caso <<": " << ans << endl;
   }
   return 0;
}