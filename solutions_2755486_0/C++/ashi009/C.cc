#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Attack {
  int d, n, w, e, s, t;
  Attack(int d, int w, int e, int s, int t) :
    d(d), w(w), e(e), s(s), t(t) {}
  bool operator <(const Attack &rhv) const {
    return d < rhv.d;
  }
};

int main() {
  int T;
  cin >> T;
  for (int CASE = 1; CASE <= T; CASE++) {
    vector<Attack> atts;
    vector<int> heights(801, 0);
    int N, res = 0;
    cin >> N;
    int d, n, w, e, s, dd, dp, ds;
    for (int i = 0; i < N; i++) {
      cin >> d >> n >> w >> e >> s >> dd >> dp >> ds;
      for (int j = 0; j < n; j++) {
        atts.push_back(Attack(d, 400+w*2, 400+e*2, s, i));
        d += dd;
        w += dp;
        e += dp;
        s += ds;
      }
    }
    sort(atts.begin(), atts.end());
    int curday = -1;
    vector<int> nheights(801, 0);
    bool curday_fail = false;

    for (int i = 0; i < atts.size(); i++) {
      Attack &att = atts[i];
      if (att.d != curday) {
        if (curday_fail) {
          for (int j = 0; j < nheights.size(); j++)
            heights[j] = max(heights[j], nheights[j]);
          curday_fail = false;
        }
        curday = att.d;
      }
      for (int j = att.w; j <= att.e; j++) {
        if (heights[j] < att.s) {
          for (int k = j; k <= att.e; k++)
            nheights[k] = max(nheights[k], att.s);
          curday_fail = true;
          // cout << "tribe " << att.t << " day " << att.d << " [" << att.w << ", " << att.e << "] = " << att.s << " succeed" << endl;
          res++;
          break;
        }
      }
    }
    cout << "Case #" << CASE << ": " << res << endl;
  }
}
