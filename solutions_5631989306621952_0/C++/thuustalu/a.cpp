#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
  int testc;
  cin >> testc;

  for (int t = 1; t <= testc; t++) {
    string source;
    cin >> source;

    vector<char> largest (source.size());
    largest[0] = source[0];
    for (int i = 1; i < (int) source.size(); i++) {
      largest[i] = max(source[i], largest[i - 1]);
    }

    string ans = "";
    ans += source[0];
    for (int i = 1; i < (int) source.size(); i++) {
      if (source[i] == largest[i]) {
        ans.insert(ans.begin(), source[i]);
      } else {
        ans += source[i];
      }
    }

    cout << "Case #" << t << ": " << ans << endl;
  }
}
