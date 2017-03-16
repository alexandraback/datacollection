#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int get_best(string& s, int end) {
  int best = 0;
  for (int i = 1; i < end; i++) {
    if (s[i] >= s[best]) best = i;
  }
  return best;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    string s;
    cin >> s;
    string pref = "";
    string suffix = "";
    int end = s.size();
    while (end > 0) {
      int id = get_best(s, end);
      pref += s[id];
      suffix = s.substr(id+1, end - id - 1) + suffix;
      end = id;
    }
    cout << "Case #" << t << ": " << (pref + suffix) << endl;
  }
  return 0;
}
