#include <bits/stdc++.h>

using namespace std;

long long ways[55];
int graph[55][55];

int main() {
  #ifdef LOCAL
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
  #endif // LOCAL

  int t;
  cin >> t;
  int c = 0;
  while (t--) {
    cout << "Case #" << ++c << ": ";
    int n;
    long long k;
    cin >> n >> k;
    ways[n] = 1;
    memset(graph, 0, sizeof graph);
    for (int i = n - 1; i >= 2; i--) {
      ways[i] = 0;
      for (int j = i + 1; j <= n; j++) {
        graph[i][j] = 1;
        ways[i] += ways[j];
      }
    }
    for (int i = 2; i <= n; i++) {
      if (ways[i] <= k) {
        k -= ways[i];
        graph[1][i] = 1;
      }
    }
    if (k > 0) {
      puts("IMPOSSIBLE");
      continue;
    }
    puts("POSSIBLE");
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cout << graph[i][j];
      }
      cout << endl;
    }
  }

  return 0;
}