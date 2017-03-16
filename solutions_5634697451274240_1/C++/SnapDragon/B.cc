#include <iostream>
#include <string>
using namespace std;

int main() {
  int T, prob = 1;
  for (cin >> T; T--;) {
    string s;
    cin >> s;
    s += '+';
    int ret = 0;
    for (int i = 0; i+1 < s.size(); i++) if (s[i] != s[i+1]) ret++;
    cout << "Case #" << prob++ << ": " << ret << endl;
  }
}
