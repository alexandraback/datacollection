#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

typedef vector<double> Vd;

int war(const Vd& v1, const Vd& v2) {
  int res = 0;
  int n = v1.size();
  set<double> s2(v2.begin(), v2.end());
  for (int i = 0; i < n; ++i) {
    set<double>::iterator it = s2.lower_bound(v1[i]);
    if (it == s2.end()) {
      s2.erase(s2.begin());
      ++res;
    }
    else {
      s2.erase(it);
    }
  }
  return res;
}

int deceitful_war(const Vd& v1, const Vd& v2) {
  int res = 0;
  int n = v1.size();
  int p = n - 1;
  for (int i = n - 1; i >= 0; --i)
    if (v1[p] > v2[i]) {
      --p;
      ++res;
    }
  return res;
}

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    int n;
    cin >> n;
    Vd v1(n), v2(n);
    for (int i = 0; i < n; ++i) cin >> v1[i];
    for (int i = 0; i < n; ++i) cin >> v2[i];
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int dw = deceitful_war(v1, v2);
    int w = war(v1, v2);
    cout << "Case #" << cas << ": " << dw << " " << w << endl;
  }
}
