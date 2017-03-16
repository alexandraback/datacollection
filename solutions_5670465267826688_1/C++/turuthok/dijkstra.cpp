#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

const char* m[4] = {
  "hijk", "iHkJ", "jKHi", "kjIH"
};
const char* ev = "ik";

int neg[256];
char f[256][256];

void init() {
  for (int i = 'H'; i <= 'K'; i++) neg[i] = tolower(i);
  for (int i = 'h'; i <= 'k'; i++) neg[i] = toupper(i);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      f['h'+i]['h'+j] = m[i][j];
      f['h'+i]['H'+j] = neg[m[i][j]];
      f['H'+i]['h'+j] = neg[m[i][j]];
      f['H'+i]['H'+j] = m[i][j];
    }
  }
}

int main() {
  init();

  int t; cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    int l; long long x; cin >> l >> x;
    string s; cin >> s;

    char group = 'h';
    for (int i = 0; i < s.size(); i++) group = f[group][s[i]];

    vector<char> period;
    period.push_back('h');
    char curr = 'h';
    while (true) {
      curr = f[curr][group];
      if (curr == 'h') break;
      period.push_back(curr);
    }

    bool valid = false;
    if (period[x % period.size()] == 'H') {
      int limit = period.size() * 2;
      if (limit > x) limit = x;
      curr = 'h';
      int events = 0;
      for (int i = 0; events < 2 && i < limit; i++) {
        for (int j = 0; events < 2 && j < s.size(); j++) {
          curr = f[curr][s[j]];
          if (curr == ev[events])
            events++;
        }
      }
      valid = (events == 2);
    }
    
    cout << "Case #" << tt << ": " << (valid ? "YES" : "NO") << endl;
  }

  return 0;
}

