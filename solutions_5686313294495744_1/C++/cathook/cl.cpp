#include <stdio.h>

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>


using std::pair;
using std::string;
using std::unordered_map;
using std::vector;


const int WLEN_MAX = 20;


bool FindNewMatch(int a, const vector<vector<int>> &bs,
                  vector<bool>& visited, vector<int>& last) {
  for (auto b : bs[a]) {
    if (!visited[b]) {
      visited[b] = true;
      if (last[b] == -1 || FindNewMatch(last[b], bs, visited, last)) {
        last[b] = a;
        return true;
      }
    }
  }
  return false;
}


int GetMaxMatch(int n, int m, const vector<pair<int, int>> &edges) {
  vector<vector<int>> bs(n);
  for (auto edge : edges) {
    bs[edge.first].push_back(edge.second);
  }

  int ret = 0;

  vector<int> last(m, -1);
  vector<bool> visited;
  for (int a = 0; a < n; ++a) {
    visited.assign(m, false);
    if (FindNewMatch(a, bs, visited, last)) {
      ret += 1;
    }
  }
  return ret;
}


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

    int max_num_ind_es = GetMaxMatch(g1.size(), g2.size(), terms);
    int min_num_cov_es = g1.size() + g2.size() - max_num_ind_es;
    int max_num_fake_terms = terms.size() - min_num_cov_es;

    printf("Case #%d: %d\n", case_idx, max_num_fake_terms);
  }

  return 0;
}
