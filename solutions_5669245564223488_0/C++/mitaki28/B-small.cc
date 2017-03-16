#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    cin >> n;
    vector<string> a(n);
    vector<int> b(n);
    vector<bool> cant(26);
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      b[i] = i;
      s.erase(unique(s.begin(), s.end()), s.end());
      a[i] = s;
    }
    int r = 0;
    do {
      vector<int> ct(26);
      bool ok = true;
      string s;
      for (int i = 0; i < n; i++) {
        s.append(a[b[i]]);
      }
      int len = s.length();
      int p = 0, q = 0;
      while (p < len) {
        if (ct[s[q] - 'a'] != 0) {
          ok = false;
          break;
        }
        ct[s[q] - 'a']++;
        while (p < len && s[p] == s[q]) p++;
        q = p;
      } 
      if (ok) r++;
    } while (next_permutation(b.begin(), b.end()));
    cout << r << endl;
  }
}