#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

void nodup(string &s) {
  int o = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[o] != s[i])
      s[++o] = s[i];
  }
  s.erase(s.begin() + o + 1, s.end());
}

int main() {
  int T;
  cin >> T;
  for (int CASE = 1; CASE <= T; CASE++) {
    int N;
    cin >> N;
    vector<string> sets(N);
    vector<int> idx(N);
    int length = 0;
    for (int i = 0; i < N; i++) {
      cin >> sets[i];
      nodup(sets[i]);
      idx[i] = i;
    }
    int res = 0;
    do {
      string s;
      for (int i = 0; i < N; i++) {
        s += sets[idx[i]];
      }
      vector<int> met(256, -1);
      bool ok = true;
      for (int i = 0; i < s.size(); i++) {
        if (met[s[i]] > -1 && met[s[i]] != i - 1) {
          ok = false;
          break;
        }
        met[s[i]] = i;
      }
      if (ok)
        res++;
    } while (next_permutation(idx.begin(), idx.end()));
    cout << "Case #" << CASE << ": " << res << endl;
  }
  return 0;
}
