#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <cstring>
using namespace std;

char transtable[26] = {
  'y', 'h', 'e', 's', 'o', 'c',
  'v', 'x', 'd', 'u', 'i', 'g',
  'l', 'b', 'k', 'r', 'z', 't',
  'n', 'w', 'j', 'p', 'f', 'm',
  'a', 'q'
};
int n;
int main() {
  cin >> n;
  string s;
  getline(cin, s);
  for (int i = 0; i < n; ++i) {
    getline(cin, s);
    cout << "Case #" << (i+1) << ": ";
    for (int j = 0; j < s.length(); ++j) {
      if (s[j] != ' ')
        cout << transtable[s[j] - 'a'];
      else
        cout << ' ';
    }
    cout << endl;
  }
}
