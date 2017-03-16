#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
//   freopen("input.txt", "r", stdin);

   int tc;
   cin >> tc;
   for (int cs = 1; cs <= tc; cs ++) {
      cout << "Case #" << cs << ": ";
      ll n, m;
      cin >> n >> m;
      if (1LL << n - 2 < m) {
         cout << "IMPOSSIBLE" << endl;
      } else {
         vector <string> edge(n);
         for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
               if (j > i) edge[i] += '1';
               else edge[i] += '0';
            }
         }
         if (1LL << n - 2 > m) {
            edge[0][n-1] = '0';
            for (int i = n - 3; i >= 0; i --) if ((m & 1LL << i) == 0) {
               edge[i+1][n-1] = '0';
            }
         }
         cout << "POSSIBLE" << endl;
         for (int i = 0; i < n; i ++) {
            cout << edge[i] << endl;
         }
      }
   }
}
