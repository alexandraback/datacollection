#include <iostream>

using namespace std;

bool check(int n, const string& s) {
  for (int i = s.length() - 1; i >= 0; --i, n /= 10)
    if (!(s[i] == '?' || s[i] == (n % 10 + '0')))
      return false;
  return true;
}

void set(int n, string& s) {
  for (int i = s.length() - 1; i >= 0; --i, n /= 10)
    s[i] = n % 10 + '0';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests;
  cin >> tests;
  for (int test = 0; test < tests; ++test) {
    string a, b;
    cin >> a >> b;
    int mx = 1;
    for (int i = 0; i < (int) a.length(); ++i)
      mx *= 10;
    int ansa = -1, ansb = -1;
    for (int i = 0; i < mx; ++i)
      for (int j = 0; j < mx; ++j)
        if (check(i, a) && check(j, b) && (ansa == -1 || (abs(ansa - ansb) > abs(i - j)))) {
          ansa = i;
          ansb = j;
        }

    set(ansa, a);
    set(ansb, b);
    cout << "Case #" << test + 1 << ": " << a << " " << b << endl;
  }
  return 0;
}
