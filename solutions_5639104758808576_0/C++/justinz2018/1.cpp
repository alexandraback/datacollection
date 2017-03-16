#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
   ios_base::sync_with_stdio(0);
   freopen("A-small-attempt0.in", "r", stdin);
   freopen("1.out", "w", stdout);
   int t; cin >> t;
   for(int a=1; a<=t; a++) {
      int n; string s;
      cin >> n >> s;
      long long ans=0, sum=0;
      for(int x=0; x<s.length(); x++) {
         if(sum<x) {
            ans+=x-sum;
            sum=x;
         }
         sum+=(s[x]-'0');
      }
      cout << "Case #" << a << ": " << ans << endl;
   }
}
