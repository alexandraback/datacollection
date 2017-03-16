#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1000000000;
const int MOD = INF + 7;
const int MAXN = 10;

int k, l, s;

string x, y;

int a[MAXN];

double solve() {
   double maxi = 0.0;
   double sum = 0.0;
   int n = 1;
   for(int i = 0 ; i < s ; i++){
      n *= k;
   }
   //generate all combinations
   for(int i = 0 ; i < n ; i++){
      string aux(s,' ');
      int m = i;
      for(int j = 0 ; j < s ; j++){
         aux[j] = x[m % k];
         m /= k;
      }

      int c = 0;
      for(int k = 0 ; k <= s - l ; k++) {
         bool sw = true;
         for(int q = 0 ; q < l ; q++) {
            sw &= aux[k+q] == y[q];
         }
         c += sw;
      }
      sum += c;
      maxi = max(maxi, (double)c);
   }

   return maxi - sum / (double)n;
}

int main(){
#ifndef ONLINE_JUDGE
   // freopen("in","r",stdin);
   freopen("B-small-attempt0x.in","r",stdin);
   freopen("B-small-attempt0x.out","w",stdout);
#endif
   cout.precision(7);
   int casos;
   cin >> casos;
   for (int caso = 1 ; caso <= casos ; caso++){
      cin >> k >> l >> s >> x >> y;
      cout << "Case #" << caso << ": " << fixed << solve() << endl;
   }
   return 0;
}