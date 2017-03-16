#include <iostream>
using namespace std;

string mapping = "yhesocvxduiglbkrztnwjpfmaq";

int main() {
  int t; cin >> t;
  string s; getline(cin, s);
  for (int c = 1; c <= t; c++) {
    getline(cin, s);
    string ss = "";
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') ss += s[i];
      else ss += mapping[s[i]-'a'];
    }
    cout << "Case #" << c << ": " << ss << endl;
  }
  return 0;
}
