#include <bits/stdc++.h>

using namespace std;


int main() {
      freopen ("input.txt", "r", stdin);
      freopen ("output.txt", "w", stdout);

      int T, caseNo = 1;
      scanf ("%d", &T);
      while (T--) {
            int A, B, K;
            cin >> A >> B >> K;
            int ans = 0;
            for (int i = 0; i < A; i++)
            for (int j = 0; j < B; j++) {
                  int val = i & j;
                  if (val < K)
                        ans ++;
            }
            printf ("Case #%d: %d\n", caseNo ++, ans);
      }

      return 0;
}
