#include <cstdio>
#include <vector>
using namespace std;

vector <int> max_val[31], surprise_flag[31];

int dp[110][110];

inline void relax (int &a, int b) {
  if (b > a) {
    a = b;
  }
}

int main (void) {
  for (int a = 0; a <= 10; a++) {
    for (int b = a; b <= a + 2 && b <= 10; b++) {
      for (int c = b; c <= a + 2 && c <= 10; c++) {
        int sum = a + b + c;
        max_val[sum].push_back (c);
        surprise_flag[sum].push_back (c == a + 2);
      }
    }
  }

  int tn;
  scanf ("%d", &tn);
  for (int tt = 1; tt <= tn; tt++) {
    int n, s, p;
    scanf ("%d%d%d", &n, &s, &p);
    memset (dp, -1, sizeof (dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      int sum;
      scanf ("%d", &sum);
      for (int j = 0; j <= i && j <= s; j++) {
        if (dp[i][j] != -1) {
          for (int k = 0; k < (int)max_val[sum].size(); k++) {
            relax (dp[i + 1][j + surprise_flag[sum][k]], dp[i][j] + (max_val[sum][k] >= p));
          }
        }
      }
    }
    printf ("Case #%d: %d\n", tt, dp[n][s]);
  }

  return 0;
}