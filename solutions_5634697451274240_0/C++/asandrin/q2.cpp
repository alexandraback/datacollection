
#include <iostream>
#include <string>

using namespace std;

int main() {

  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    string s;
    cin >> s;

    int S = s.size();
    char c = s[0];
    char l = c;
    int o = 0;
    for (int j = 1; j < S; j++) {
      c = s[j];
      if (c != l) {
        o++;
        l = c;
      }
    }
    if (l == '-') {
      o++;
    }
    cout << "Case #" << i+1 << ": " << o << endl;
  }

  return 0;
}
