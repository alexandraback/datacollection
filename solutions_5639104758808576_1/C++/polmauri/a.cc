#include <iostream>
#include <string>
using namespace std;

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    int smax;
    string s;
    cin >> smax >> s;
    int t = 0;
    int res = 0;
    for (int i = 0; i <= smax; ++i) {
      int x = s[i] - '0';
      if (t < i) {
        res += i - t;
        t = i;
      }
      t += x;
    }
    cout << "Case #" << cas << ": " << res << endl;
  }
}
