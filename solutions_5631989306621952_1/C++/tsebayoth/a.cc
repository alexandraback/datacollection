#include <iostream>
#include <string>

using namespace std;

string gen(string s) {
  string r = "";

  for (int i = 0; i < s.size(); ++i) {
    if (r.size() == 0 || r[0] > s[i])
      r += s[i];
    else
      r = s[i] + r;
  }
  return r;
}

int main() {
  int t = 0, T;

  cin >> T;
  while (T--) {
    string s;
    cin >> s;

    cout << "Case #" << ++t << ": " << gen(s) << endl;
  }
  return 0;
}
