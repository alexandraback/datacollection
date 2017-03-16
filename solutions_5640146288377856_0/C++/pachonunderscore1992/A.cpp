#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1000000000;
const int MOD = INF + 7;
const int MAXN = 100010;

int r,c,w;

int solve() {
   int ans = w-1;
   for(int i = 1 ; i <= c ; i += w){
      ans += 1;
   }
   return ans;
}

int main(){
#ifndef ONLINE_JUDGE
   // freopen("in","r",stdin);
   freopen("A-small-attempt0.in","r",stdin);
   freopen("A-small-attempt0.out","w",stdout);
#endif
   //cout.precision(7);

   int casos;
   cin >> casos;
   for (int caso = 1 ; caso <= casos ; caso++){
      cin >> r >> c >> w;
      cout << "Case #" << caso << ": " << solve() << endl;
   }
   return 0;
}