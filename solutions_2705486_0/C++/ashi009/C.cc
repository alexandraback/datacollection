#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <fstream>

using namespace std;
unordered_set<string> dict;
map<pair<string, int>, int> memo;
int maxlen = 0;

int dfs(string s, int alt_index) {
  if (s.empty())
    return 0;
  auto key = make_pair(s, alt_index);
  auto it = memo.find(key);
  if (it != memo.end())
    return it->second;
  int res = 1 << 20;
  for (int i = 1; i <= maxlen && i <= s.size(); i++) {
    if (dict.find(s.substr(0, i)) != dict.end()) {
      res = min(res, dfs(s.substr(i), 0));
    } else {
      for (int j = alt_index; j < i; j++) {
        char old = s[j];
        for (char k = 'a'; k <= 'z'; k++) if (k != old) {
          s[j] = k;
          if (dict.find(s.substr(0, i)) != dict.end()) {
            res = min(res, 1 + dfs(s.substr(i), max(j + 5 - i, 0)));
          }
        }
        s[j] = old;
      }
    }
  }
  return memo[key] = res;
}

int main() {
  {
    ifstream fin("dict.txt");
    string s;
    while (fin >> s) {
      dict.insert(s);
      maxlen = max(maxlen, (int)s.size());
    }
  }

  int T;
  cin >> T;
  string s;
  for (int CASE = 1; CASE <= T; CASE++) {
    cin >> s;
    cout << "Case #" << CASE << ": " << dfs(s, 0) << endl;
  }
}