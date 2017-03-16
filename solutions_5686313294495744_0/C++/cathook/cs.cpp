#include <stdio.h>

#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>


using std::max;
using std::pair;
using std::string;
using std::unordered_map;
using std::vector;


const int WLEN_MAX = 20;


int main(void) {
  int num_cases;
  scanf("%d", &num_cases);

  for (int case_idx = 1; case_idx <= num_cases; ++case_idx) {
    int n;
    scanf("%d", &n);

    vector<pair<int, int>> terms;

    unordered_map<string, int> g1, g2;
    for (int i = 0; i < n; ++i) {
      static char w1[WLEN_MAX + 1], w2[WLEN_MAX + 1];
      scanf("%s %s", w1, w2);

      int a = g1.insert(pair<string, int>(w1, g1.size())).first->second;
      int b = g2.insert(pair<string, int>(w2, g2.size())).first->second;

      terms.emplace_back(a, b);
    }

    int ans = 0;

    vector<bool> used1, used2;
    for (int enu = 0, enu_end = 1 << n; enu < enu_end; ++enu) {
      used1.assign(g1.size(), false);
      used2.assign(g2.size(), false);

      for (int i = 0; i < n; ++i) {
        if (((enu >> i) & 1) == 1) {
          used1[terms[i].first] = true;
          used2[terms[i].second] = true;
        }
      }

      bool ok = true;
      int ct = 0;
      for (int i = 0; i < n; ++i) {
        if (((enu >> i) & 1) == 0) {
          if (!used1[terms[i].first] || !used2[terms[i].second]) {
            ok = false;
            break;
          }
          ++ct;
        }
      }

      if (ok) {
        ans = max(ans, ct);
      }
    }

    printf("Case #%d: %d\n", case_idx, ans);
  }

  return 0;
}
