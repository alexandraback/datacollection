#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int ci = 1; ci <= t; ++ci) {
    int n;
    cin >> n;
    map<string, vector<string> > aside;
    map<string, bool> bside;
    for (int ni = 1; ni <= n; ++ni) {
      string a, b;
      cin >> a >> b;

      if (aside.find(a) == aside.end()) {
        aside[a] = vector<string>();
      }
      aside[a].push_back(b);
      if (bside.find(b) == bside.end()) {
        bside[b] = false;
      }
    }

    int res = 0;
    map<string, vector<string> >::iterator iter;
    for (iter = aside.begin(); iter != aside.end(); ++iter) {
      vector<string>& vec = iter->second;
      bool checked = false;
      for (int i = 0; i < vec.size(); ++i) {
        string str = vec[i];
        if (bside[str]) ++res;
        else {
          bside[str] = true;
          checked = true;
        }
      }
      if (!checked) --res;
    }

    cout << "Case #" << ci << ": " << res << endl;
  }

  return 0;
}
