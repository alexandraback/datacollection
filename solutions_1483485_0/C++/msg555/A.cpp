#include <map>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  string s = "ejp mysljylc kd kxveddknmc re jsicpdrysi"
      "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
      "de kr kd eoya kw aej tysr re ujdr lkgc jv qeyz";
  string t = "our language is impossible to understand"
      "there are twenty six factorial possibilities"
      "so it is okay if you want to just give up zoaq";
  map<char, char> ch;
  for(int i = 0; i < s.size(); i++) {
    ch[s[i]] = t[i];
  }
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  s.resize(unique(s.begin(), s.end()) - s.begin());
  t.resize(unique(t.begin(), t.end()) - t.begin());

  int T; cin >> T;
  string ln; getline(cin, ln);
  for(int tt = 1; tt <= T; tt++) {
    getline(cin, ln);
    for(int i = 0; i < ln.size(); i++) ln[i] = ch[ln[i]];
    cout << "Case #" << tt << ": " << ln << endl;
  }
}
