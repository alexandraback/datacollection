#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    string s; cin >> s;

    string out;
    char c;
    stringstream ss(s);
    while(ss >> c) {
      if (out.length() < 1) {
        out.push_back(c);
      } else if (out[0] > c) {
        out.push_back(c);
      } else {
        out.insert(0, 1, c);
      }
    }

    cout << out << endl;
  }
  return 0;
}
