#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
   ios_base::sync_with_stdio(0);
   freopen("B-large.in", "r", stdin);
   freopen("2.out", "w", stdout);
   int t; cin >> t;
   for(int a=1; a<=t; a++) {
      int d; cin >> d;
      vector<int> v(d);
      int max1 = -1;
      for(int x=0; x<d; x++) {
         cin >> v[x];
         max1 = max(v[x], max1);
      }
      long long ans = 1e9;
      for(int x=1; x<=max1; x++) {
         long long tmp = 0;
         for(int y=0; y<v.size(); y++) {
            tmp+=ceil(v[y]/(x+0.0))-1;
         }
         ans = min(x+tmp, ans);
      }
      cout << "Case #" << a << ": " << ans << endl;
   }
}
