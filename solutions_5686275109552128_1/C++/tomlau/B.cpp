#include <iostream>
#include <algorithm>
using namespace std;

const int MAX=1024;
int T, D, split[MAX][MAX], dp[MAX][MAX], P[MAX];

int main() {
  memset(split, 0, sizeof(split));
  for (int i=2; i<MAX; i++)
    for (int j=1; j<i; j++) {
      split[i][j] = MAX;
      for (int k=1; k<=j; k++)
        split[i][j] = min(split[i][j], split[k][j] + split[i-k][j] + 1);
    }

  cin >> T;
  for (int t=1; t<=T; t++) {
    cin >> D;
    int Pmax = 0;
    for (int i=0; i<D; i++) {
      cin >> P[i];
      Pmax = max(Pmax, P[i]);
    }

    for (int i=0; i<D; i++)
      for (int r=1; r<=Pmax; r++)
        dp[i][r] = i==0 ? split[P[i]][r] : dp[i-1][r]+split[P[i]][r];

    int minTime = Pmax;
    for (int r=1; r<=Pmax; r++)
      minTime = min(minTime, dp[D-1][r] + r);

    cout << "Case #" << t << ": " << minTime << endl;
 }
}
