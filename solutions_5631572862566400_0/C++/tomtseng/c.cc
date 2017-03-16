#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int bffs[1003];
bool bh[1003];
int bhbest[1003];
bool visited[1003];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  ll T, N;
  int ans;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    cin >> N;
    for (int i = 1; i <= N; i++)
      cin >> bffs[i];
    for (int i = 1; i <= N; i++)
      bh[i] = (i == bffs[bffs[i]]);
    memset(bhbest, 0, 1003*sizeof(int));

    ans = 0;

    for (int src = 1; src <= N; src++) {
      memset(visited, 0, 1003*sizeof(bool));
      int len = 0;

      int curr = src;
      while (!visited[curr] && !bh[curr]) {
        len++;
        visited[curr] = true;
        curr = bffs[curr];
      }

      if (bh[curr]) { // BH
        bhbest[curr] = max(len+1, bhbest[curr]);
      } else if (curr == src) { // full cycle
        ans = max(ans, len);
      }
    }

    int bhsum = 0;
    for (int i = 1; i <= N; i++)
      bhsum += bhbest[i];

    ans = max(ans, bhsum);

    cout << "Case #" << t << ": " << ans << "\n";
  }

  return 0;
}
