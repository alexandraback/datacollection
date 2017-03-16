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

vector<vector<int> > res;
map<pair<int, int>, int> jp;
map<pair<int, int>, int> js;
map<pair<int, int>, int> ps;

vector<int> jps;
int k;

void Check(int n, vector<int> cand) {
  if (n == 3) {
    pair<int, int> jp_c = make_pair(cand[0], cand[1]);
    pair<int, int> js_c = make_pair(cand[0], cand[2]);
    pair<int, int> ps_c = make_pair(cand[1], cand[2]);

    if (jp[jp_c] < k &&
        js[js_c] < k &&
        ps[ps_c] < k) {
      res.push_back(cand);
      ++jp[jp_c];
      ++js[js_c];
      ++ps[ps_c];
    }

    return;
  }

  for (int i = 0; i < jps[n]; ++i) {
    cand.push_back(i + 1);
    Check(n + 1, cand);
    cand.pop_back();
  }
}


int main() {
  int t;
  cin >> t;
  for (int ci = 1; ci <= t; ++ci) {
    res.clear();
    jp.clear();
    js.clear();
    ps.clear();
    jps.clear();

    int j, p, s;
    cin >> j >> p >> s >> k;
    jps.push_back(j);
    jps.push_back(p);
    jps.push_back(s);

    vector<int> cand;
    Check(0, cand);

    cout << "Case #" << ci << ": " << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
      for (int j = 0; j < res[i].size(); ++j) {
        cout << res[i][j];
        if (j < 2) cout << " ";
      }
      cout << endl;
    }
  }

  return 0;
}
