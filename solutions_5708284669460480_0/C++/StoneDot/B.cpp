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

int K, L, S;
string Key;
string Target;
string str;
int maxCount;
double banana;
void generate(int i) {
  if (i == S) {
    int count = 0;
    for (int j = 0; j < S - Target.size() + 1; j++) {
      bool ok = true;
      for (int k = 0; k < Target.size(); k++) {
        if (str[j + k] != Target[k]) {
          ok = false;
          break;
        }
      }
      if (ok) count++;
    }
    banana += count;
    maxCount = max(count, maxCount);
    return;
  }
  for (auto ch : Key) {
    str[i] = ch;
    generate(i + 1);
  }
}

void solve() {
  double ans;
  maxCount = 0;
  banana = 0;
  cin >> K >> L >> S;
  cin >> Key >> Target;
  str.clear();
  str.resize(S);
  generate(0);
  ans = maxCount - banana / pow(K, S);
  cout << setprecision(10) << ans << endl;
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