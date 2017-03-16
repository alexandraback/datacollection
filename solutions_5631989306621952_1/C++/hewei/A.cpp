#include <string>
#include <iostream>

using namespace std;

string solve (string s)
{
  string p;
  for (int i = 0; i < s.length(); ++i) {
    string a = p + s[i];
    string b = s[i] + p;
    if (a < b) {
      p = b;
    } else {
      p = a;
    }
  }
  return p;
}

int main()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    cout << "Case #" << i << ": " << solve(s) << endl;
  }
  return 0;
}
