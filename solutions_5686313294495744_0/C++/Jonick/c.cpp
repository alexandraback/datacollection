#include <bits/stdc++.h>

using namespace std;

void solveTest() {
  int n;
  cin >> n;
  vector<pair<string, string>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }

  vector<int> best(1 << n, 0);
  best[0] = 0;
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      if ((i | (1<<j)) == i) {
	continue;
      }
      bool uniq1 = true;
      bool uniq2 = true;
      bool usew1 = false;
      bool usew2 = false;
      for (int k = 0; k < n; k++) {
	if (k != j && (i & (1<<k)) != 0) {
	  if (a[j].first == a[k].first)
	    uniq1 = false;
	  if (a[j].second == a[k].second)
	    uniq2 = false;
	  if (a[k].first == a[j].second)
	    usew1 = true;
	  if (a[k].second == a[j].first)
	    usew2 = true;
	}
      }
      int dd = uniq1 || uniq2 || usew1 || usew2 ? 0 : 1;
      best[i | (1 << j)] = std::max(best[i | (1<<j)], best[i] + dd);
    }
  }
  cout << best[(1 << n) - 1] << "\n";
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << "Case #" << i << ": ";
    solveTest();
  }
  return 0;
}
