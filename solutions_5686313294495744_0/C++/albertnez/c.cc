#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
typedef unordered_map<string, int> MSI;
typedef vector<int> VI;
struct S {
  int ind, id1, id2, used;
  S(){}
  S(int ind, int i1, int i2) : ind(ind), id1(i1), id2(i2), used(0) {}
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T; cin >> T;
  for (int ncase = 1; ncase <= T; ++ncase) {
    int n; cin >> n;
    MSI ids;
    VI first, second;
    vector<S> vs(n);
    int id = 0;
    for (int i = 0; i < n; ++i) {
      string s1, s2; cin >> s1 >> s2;
      if (ids.find(s1) == ids.end()) {
        ids[s1] = id++;
        first.push_back(0);
        second.push_back(0);
      }
      if (ids.find(s2) == ids.end()) {
        ids[s2] = id++;
        first.push_back(0);
        second.push_back(0);
      }
      first[ids[s1]]++;
      second[ids[s2]]++;
      vs[i] = S(i, ids[s1], ids[s2]);
    }
    VI seenfirst(id+1, 0), seensecond(id+1, 0);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int best = 0;
      int mnc = 100000;
      for (auto & s : vs) if (!s.used) {
        int m = min(first[s.id1], second[s.id2]);
        if (m < mnc) {
          mnc = m;
          best = s.ind;
        }
      }
      S &s = vs[best];
      s.used = 1;
      if (seenfirst[s.id1] && seensecond[s.id2]) ++ans;
      seenfirst[s.id1] = 1;
      seensecond[s.id2] = 1;
      --first[s.id1];
      --second[s.id2];
    }
    cout << "Case #" << ncase << ": " << ans << endl;
  }
}


