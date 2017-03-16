#include <string>
#include <iostream>

using namespace std;

bool v(char c) {
  switch (c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      return true;
  }
  return false;
}

long long solve(string s, int n) {
  int c = 0;
  int i = 0;
  // cerr << "s: " << s << "\n";
  for (int i = 0; i < s.length(); i++) {
    if (v(s[i])) {
      c = 0;
      continue;
    }
    c++;    
    if (c < n) continue;
    // cerr << "i " << i << "\n";
    // cerr << (i - n + 2) << " x" << (s.length() - i) << "\n";
    long long r = (i - n + 2) * (s.length() - i);
    if (i - n + 2 < s.length()) {
      r += solve(s.substr(i - n + 2), n);
    }    
    return r;
  }  
  return 0;
}

int main() {
  int cases;
  cin >> cases;
  for (int c = 0; c < cases; c++) {
    string s;
    cin >> s;
    int n;
    cin >> n;
    long long r = solve(s, n);
    cout << "Case #" << c+1 << ": " << r << "\n";
  }
  return 0;
}