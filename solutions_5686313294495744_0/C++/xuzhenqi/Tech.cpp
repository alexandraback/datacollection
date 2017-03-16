#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int N;
vector<pair<string, string> > total;

int res;

void dfs(int idx, vector <pair<string, string> > &total2,  vector <pair<string, string> > &st, vector <string> &left, vector <string> &right) {
  int cnt = 0;
  if (idx >= N) {
    for (int j = 0; j < total2.size(); j++) {
      if (find(left.begin(), left.end(), total2[j].first) != left.end() &&
          find(right.begin(), right.end(), total2[j].second) != right.end() )
        cnt++;
    }
    res = max(res, cnt);
    return;
  }
  st.push_back(total[idx]);
  left.push_back(total[idx].first);
  right.push_back(total[idx].second);

  auto iter = find(total2.begin(), total2.end(), total[idx]);
  total2.erase(iter);
  dfs(idx + 1, total2, st, left, right);
  st.pop_back();
  left.pop_back();
  right.pop_back();
  total2.push_back(total[idx]);
  dfs(idx + 1, total2, st, left, right);
  return;
}

int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    cin >> N;
    total.clear();
    for (int j = 0; j < N; ++j) {
      string a, b;
      cin >> a >> b;
      total.push_back(pair<string, string> (a, b));
    }
    vector <pair<string, string> > st;
    vector <pair<string, string> > total2(total);
    vector <string> left;
    vector <string> right;
    res = 0;
    dfs(0, total2, st, left, right);
    cout << "Case #" << i << ": " << res << endl;
  }
  return 0;
}
