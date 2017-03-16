#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> Vi;
typedef vector<Vi> Mi;

int find_largest(const string& s, int n) {
  char maxi = s[0];
  int pos = 0;
  for (int i = 1; i < n; ++i) {
    if (s[i] >= maxi) {
      maxi = s[i];
      pos = i;
    }
  }
  return pos;
}

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    string s;
    cin >> s;
    int n = s.size();
    string front, back;
    int p = n;
    while (p > 0) {
      int t = find_largest(s, p);
      front += s[t];
      back = s.substr(t + 1, p - t - 1) + back;
      p = t;
    }
    string res = front + back;
    if (res.size() != s.size()) {
      cerr << "ERROR" << endl;
    }
    cout << "Case #" << cas << ": " << res << endl;
  }
}
