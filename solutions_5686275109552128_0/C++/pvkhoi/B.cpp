#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int a[MAXN];
int nTest, d, maxVal;

int solve() {
   int res = maxVal;
   for (int minVal = 1; minVal <= maxVal; minVal++) {
      int ans = 0;
      for (int i = 0; i < d; i++)
         ans += (a[i] / minVal) + (((a[i] % minVal) > 0) ? 1 : 0) - 1;
      res = min(res, ans + minVal);
   }
   return res;
}

int main() {
   freopen("B-small-attempt1.in", "r", stdin);
   freopen("output.txt", "w", stdout);

   ios::sync_with_stdio(false);
   cin >> nTest;
   for (int t = 1; t <= nTest; t++) {
      maxVal = -1;
      cin >> d;
      for (int i = 0; i < d; i++) {
         cin >> a[i];
         maxVal = max(maxVal, a[i]);
      }
      cout << "Case #" << t << ": " << solve() << endl;
   }

   return 0;
}
