#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <string>
 
using namespace std;

string s[1000];

const long long mod = 1000000007LL;

int gonx[50];
int gopr[50];

void solve(int tcase) {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  cout << "Case #" << tcase << ": ";

  vector <int> used(26, 0);
  vector <int> us(n, 0);

  long long res = 1;

  memset(gonx, -1, sizeof(gonx));
  memset(gopr, -1, sizeof(gopr));

 for (int i = 0; i < 26; ++i) {
      vector <string> good;
      for (int j = 0; j < n; ++j) {
        int have = false;
        for (int k = 0; k < s[j].length(); ++k) {
          if (s[j][k] == 'a' + i) {
            have = true;
            break;
          }
        }
        if (have) {
          good.push_back(s[j]);
        }
      }

      if (good.size() == 0) {
        used[i] = 1;
        continue;
      } else if (good.size() == 1) {
        string cur = good[0];
        if (cur[0] != 'a' + i && cur[cur.length() - 1] != 'a' + i) {
          used[i] = 1;
        }
        continue;
      }
 }

  for (int i = 0; i < 26; ++i) {
    if (!used[i]) {
      vector <string> good;
      for (int j = 0; j < n; ++j) {
        int have = false;
        for (int k = 0; k < s[j].length(); ++k) {
          if (s[j][k] == 'a' + i) {
            have = true;
            break;
          }
        }
        if (have) {
          good.push_back(s[j]);
        }
      }

      int cnt = good.size();
      int cntall = 0;
      vector <string> curs;
      for (int j = 0; j < good.size(); ++j) {
        int gd = true;
        for (int k = 0; k < good[j].length(); ++k) {
          if (good[j][k] != 'a' + i) {
            gd = false;
            break;
          }
        }
        if (gd) cntall += gd; else {
          curs.push_back(good[j]);
        }
      }

      if (cnt > cntall + 2) {
        cout << "0" << endl;
        return;
      }

      for (int j = 1; j <= cntall; ++j) {
        res *= (long long)(j);
        res %= mod;
      }

      int havenxt = -1, havepr = -1;

      for (int j = 0; j < curs.size(); ++j) {
        string buf = curs[j];

        if (buf[0] != 'a' + i && buf[buf.length() - 1] != 'a' + i) {
          cout << "0" << endl;
          return;
        }

        if (buf[0] == 'a' + i) {
          int ind = 0;
          while (ind < buf.size() && buf[ind] == 'a' + i) ++ind;

          int gd = true;
          while (ind < buf.size() && used[buf[ind] - 'a']) ++ind;
          
          char c = buf[ind];
          while (ind < buf.size() && buf[ind] == c) ++ind;
          if (ind != buf.size()) {
            cout << "0" << endl;
            return;
          }
          if (havenxt != -1) {
            cout << "0" << endl;
            return;
          }
          gonx[i] = c - 'a';
          havenxt = 1;
        } else {
          int ind = buf.size() - 1;
          while (ind >= 0 && buf[ind] == 'a' + i) --ind;

          int gd = true;
          while (ind >= 0 && used[buf[ind] - 'a']) --ind;
          
          char c = buf[ind];
          while (ind >= 0 && buf[ind] == c) --ind;
          if (ind != -1) {
            cout << "0" << endl;
            return;
          }
          if (havepr != -1) {
            cout << "0" << endl;
            return;
          }
          gopr[i] = c - 'a';
          havepr = 1;
        }
      }
    }
  }

  int cycles = 0;
  vector <int> used2(26, 0);
  for (int i = 0; i < 26; ++i) {
    if (!used[i]) {
      if (!used2[i]) {
        ++cycles;
        int cur = i;
        while (true) {
          if (used2[cur]) {
            cout << "0" << endl;
            return;
          }
          used2[cur] = 1;
          cur = gonx[cur];
          if (cur == -1) {
            break;
          }
        }
        cur = gopr[i];
        while (true) {
          if (cur == -1) break;
          if (used2[cur]) {
            cout << "0" << endl;
            return;
          }
          used2[cur] = 1;
          cur = gopr[cur];
          if (cur == -1) {
            break;
          }
        }
      }
    }
  }

  for (int i = 1; i <= cycles; ++i) {
    res *= i;
    res %= mod;
  }
  cout << res << endl;
}

int main() {
 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
 
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
      solve(t + 1);
      cerr << t << endl;
    }
 
   
 
    return 0;
}