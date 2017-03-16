#include <iostream>
#include <string>
using namespace std;

int main() {
  int T;
  char pm[2] = {'-', '+'};
  string s;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> s;
    cout << "Case #" << i + 1 << ": ";
    int l = s.length();
    int p = 0;
    int c = 0;
    for (int j = l - 1; j >= 0; j--) {
      if (s[j] == pm[p]) {
        ++c;
        p = !p;
      }
    }
    cout << c << endl;
  }
}
