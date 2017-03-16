#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   int T; cin >> T;
   for (int caseNo = 1; caseNo <= T; caseNo++)
   {
      long long a, n; cin >> a >> n;
      vector<int> ms(n);
      for (int i = 0; i < n; i++) cin >> ms[i];
      sort(ms.begin(), ms.end());

      int ix = 0;
      long long low = 0;
      long long high = 100000000;
      
      while(true)
      {
         if (ix >= ms.size()) break;
         if (low >= high) break;
         if (a > ms[ix])
         {
            a += ms[ix];
            ix++;
         }
         else
         {
            a += a - 1;
            high = min(high, low + (long long)ms.size() - ix);
            low++;
         }
      }
      int ans = low;
      cout << "Case #" << caseNo << ": " << ans << endl;
   }
   
   return 0;
}
