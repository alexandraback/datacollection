#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int motes[100];
int A, N, T;
short dp[111][1111111];

pair<int, int> doubles(int n, int m) {
  int k = 0;
  while (n <= m) {
    n += n-1;
    k++;
  }
  return make_pair(k, n);
}

int main() {

  scanf("%d", &T);

  for (int k = 1; k <= T; k++) {
    scanf("%d %d", &A, &N);
    for (int i = 0; i < N; i++)
      scanf("%d", &motes[i]);

    sort(motes, motes + N);

    int maxSize = max(motes[N-1], A) + 10;
    for (int i = 0; i <= N; i++)
      for (int j = 0; j <= maxSize; j++)
        dp[i][j] = 100;

    int next;
    dp[0][A] = 0;
    for (int i = 0; i < N; i++)
      for (int j = 0; j <= maxSize; j++)
        if (dp[i][j] != 100) {
          if (motes[i] < j) {
            next = min(j + motes[i], maxSize);
            dp[i+1][next] = min(dp[i+1][next], dp[i][j]);
          } else {
            dp[i+1][j] = min(dp[i+1][j], (short)(dp[i][j] + 1));

            if (j != 1) {
              pair<int, int> d = doubles(j, motes[i]);
              next = min(d.second + motes[i], maxSize);
              dp[i+1][next] = min(dp[i+1][next], (short)(dp[i][j] + d.first));
            }
          }
        }

    short minn = 100;
    for (int i = 0; i <= maxSize; i++)
      minn = min(minn, dp[N][i]);

    printf("Case #%d: %d\n", k, minn);
  }
}
