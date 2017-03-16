#include <iostream>
using namespace std;

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    string s;
    cin >> s;
    s += "+";
    int n = s.size();
    int res = 0;
    for (int i = 0; i + 1 < n; ++i) {
      if (s[i] != s[i + 1]) {
        ++res;
      }
    }
    cout << "Case #" << cas << ": " << res << endl;
  }
}
