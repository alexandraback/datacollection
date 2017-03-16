#include <iostream>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <algorithm>
#include <functional>
#include <limits.h>
#include <bitset>

#include <tuple>
#include <unordered_map>

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int INF = 1 << 29;
const double EPS = 1e-9;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
const int MAX_N = 20;
void solve(const int case_id) {
  int N;
  cin >> N;
  vector<pair<string, string>> topics;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    string str1, str2;
    cin >> str1 >> str2;
    topics.emplace_back(mp(str1, str2));
  }
  for (int bit = 0; bit < (1 << N); bit++) {
    set<string> listed;
    set<string> f_list, s_list;
    set<int> idx_liar, idx_honest;
    for (int i = 0; i < N; i++) {
      if (((bit >> i) & 1)) { // uso
        idx_liar.insert(i);
      } else {
        idx_honest.insert(i);
        // listed.insert(topics[i].first + "-" + topics[i].second);

        f_list.insert(topics[i].first);
        s_list.insert(topics[i].second);
      }
    }
    if (idx_honest.empty())
      continue;

    bool ok = true;
    for (const int index : idx_honest) {
      string first_word, second_word;
      first_word = topics[index].first;
      second_word = topics[index].second;
      bool first, second;
      first = second = false;
      for (const int tar_index : idx_honest) {
        if (index == tar_index)
          continue;
        if (first_word == topics[tar_index].first) {
          first = true;
        }
        if (second_word == topics[tar_index].second) {
          second = true;
        }
      }
      if (first and second) { // liar
        ok = false;
        break;
      }
    }

    if (not ok)
      continue;
    set<int> idx_ok;
    int cnt = 0;
    while (cnt++ < 10) {
      for (const int index : idx_liar) {
        string first_word, second_word;
        first_word = topics[index].first;
        second_word = topics[index].second;
        if (f_list.count(first_word) > 0 and
            s_list.count(second_word) > 0) { // liar

          f_list.insert(first_word);
          s_list.insert(second_word);
          // cout << "unko" << endl;
          idx_ok.insert(index);
        }
      }
    }

    for (const int index : idx_liar) {
      if (idx_ok.count(index) == 0) {
        ok = false;
        break;
      }
    }
    // cout << bit << " " << ok << endl;
    if (not ok)
      continue;
    ans = max(ans, (int)idx_liar.size());
  }
  printf("Case #%d: %d\n", case_id, ans);
}
int main() {
  int T;
  cin >> T;
  for (int case_id = 1; case_id <= T; case_id++) {
    solve(case_id);
  }
  return 0;
}