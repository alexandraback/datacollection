#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <iomanip>

using namespace std;

int C, D, V;
int coin[100];
bool afford[100];

void fill(int i, int sum) {
  if (sum > V) return;
  afford[sum] = true;
  if (i == D) return;
  fill(i + 1, sum);
  fill(i + 1, sum + coin[i]);
}

void solve() {
  int ans = 0;
  cin >> C >> D >> V;
  for (int i = 0; i < D; i++) {
    cin >> coin[i];
  }
  sort(&coin[0], &coin[D]);
  for (int v = 0; v <= V; v++) {
    afford[v] = false;
  }
  fill(0, 0);
  for (int v = 0; v <= V; v++) {
    if (!afford[v]) {
      ans++;
      for (int i = V; i >= 0; i--) {
        if (afford[i] && i + v <= V) {
          afford[i + v] = true;
        }
      }
    }
  }
  cout << ans << endl;
}

int main(void) {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}