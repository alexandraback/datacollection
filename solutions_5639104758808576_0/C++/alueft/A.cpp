#include <iostream>
using namespace std;

int main() {
  int t; cin >> t;
  for (int T = 1; T <= t; T++) {
    cout << "Case #" << T << ": ";
    int m;
    string s;
    cin >> m >> s;
    int a = 0;
    int c = 0;
    for (int i = 0; i <= m; i++) {
      c += s[i]-'0';
      if (!c) {
        c++;
        a++;
      }
      c--;
    }
    cout << a << "\n";
  }
  return 0;
}
