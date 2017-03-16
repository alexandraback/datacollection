#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;

int n;

bool correct(VS& v, VI& p) {
  VI ch(256);
  int k = 0, pos = 0;
  while (k < n) {
    char current = v[p[k]][pos];
    if (ch[current]) return false;
    while (k < n and v[p[k]][pos] == current) {
      int size = v[p[k]].size();
      while (pos < size and v[p[k]][pos] == current) ++pos;
      if (pos == size) {
        ++k;
        pos = 0;
      }
    }
    ch[current] = true;
  }
  return true;
}

void solve() {
  cin >> n;
  VS v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  VI p(n);
  for (int i = 0; i < n; ++i) p[i] = i;
  
  int res = 0;
  do {
    if (correct(v, p)) ++res;
  } while (next_permutation(p.begin(), p.end()));
  
  cout << res << endl;
}

int main() {
  int t;
  cin >> t;
  for (int z = 0; z < t; ++z) {
    cout << "Case #" << z + 1 << ": ";
    solve();
  }
}