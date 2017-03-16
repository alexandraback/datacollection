#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool palindrome(int n) {
  stringstream ss;
  ss << n;
  string s = ss.str();
  int m = s.size();
  for (int i = 0; i < m; ++i)
    if (s[i] != s[m - 1 - i])
      return false;
  return true;
}

bool fun(int n) {
  int r = int(sqrt(n));
  if (r*r != n) return false;
  return palindrome(n) and palindrome(r);
}

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    cout << "Case #" << cas << ": ";
    int a, b;
    cin >> a >> b;
    int res = 0;
    for (int i = a; i <= b; ++i)
      if (fun(i)) ++res;
    cout << res << endl;
  }
}
