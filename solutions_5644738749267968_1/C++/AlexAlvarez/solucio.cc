#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int solve_war(vector<double>& v1, vector<double>& v2) {
  set<double> aux(v2.begin(), v2.end());
  int res = 0;
  for (int i = 0; i < v1.size(); ++i) {
    set<double>::iterator it = aux.upper_bound(v1[i]);
    if (it == aux.end()) {
      ++res;
      aux.erase(aux.begin());
    }
    else aux.erase(it);
  }
  return res;
}

int solve_deceitful(vector<double>& v1, vector<double>& v2) {
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  int res = 0;
  int i = v1.size() - 1;
  int j = i;
  while (i >= 0 and j >= 0) {
    if (v1[i] > v2[j]) {
      --i;
      --j;
      ++res;
    }
    else --j;
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  vector<double> v1(n), v2(n);
  for (int i = 0; i < n; ++i) cin >> v1[i];
  for (int i = 0; i < n; ++i) cin >> v2[i];
  cout << solve_deceitful(v1, v2) << " " << solve_war(v1, v2) << endl;
}

int main() {
  int casos;
  cin >> casos;
  for (int cas = 1; cas <= casos; ++cas) {
    cout << "Case #" << cas << ": ";
    solve();
  }
}
