#include <iostream>

using namespace std;

bool isVow[128] = {false};

long long calc(const string &str, int n) {
  long long res = 0, substrEndsAtLastChar = 0;
  int curLen = 0;
  for (int i = 0; i < str.size(); i++) {
    if (isVow[str[i]]) {
      res += substrEndsAtLastChar;
      curLen = 0;
    } else {
      if (++curLen >= n) {
        // just found one
        res += 1 + i + 1 - n;
        substrEndsAtLastChar += 1 + i + 1 - n - substrEndsAtLastChar;
      } else {
        res += substrEndsAtLastChar;
      }
    }
  }
  return res;
}

int main() {
  int T, n;
  string s;
  cin >> T;
  isVow['a'] = isVow['e'] = isVow['i'] = isVow['o'] = isVow['u'] = true;
  for (int CASE = 1; CASE <= T; CASE++) {
    cin >> s >> n;
    cout << "Case #" << CASE << ": " << calc(s, n) << endl;
  }
}
