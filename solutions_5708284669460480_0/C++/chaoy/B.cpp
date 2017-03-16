#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

int K, L, S;
string k, t;
int n, mx, m;

void go(string& now) {
  if (now.length() >= S) {
    int match = 0;
    for (int s = now.find(t); s != string::npos; s = now.find(t, s + 1)) {
      match++;
    }
    n++;
    mx = max(match, mx);
    m += match;
    return;
  }
  for (auto c : k) {
    now.push_back(c);
    go(now);
    now.pop_back();
  }
}

double run() {
  cin >> K >> L >> S;
  cin >> k >> t;
  string now = "";
  n = mx = m = 0;
  go(now);
  return mx - static_cast<double>(m) / n;
}

int main() {
  int T;
  cin >> T;
  cout << setprecision(9);
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": " << run() << endl;
  }
}
