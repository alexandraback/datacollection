#include <iostream>
#include <string>

using namespace std;

void get_last_word(string &s, string &t) {
  for (auto c : s) {
    if (c < t[0])
      t += c;
    else
      t.insert(0, 1, c);
  }
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    string s;
    cin >> s;
    string res;
    get_last_word(s, res);
    cout << "Case #" << i << ": " << res << endl;
  }
}
