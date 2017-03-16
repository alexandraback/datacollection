#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  size_t T;
  std::cin >> T;
  for (size_t t = 1; t <= T; ++t) {
    size_t J, P, S, K;
    std::cin >> J >> P >> S >> K;
    std::cout << "Case #" << t << ": ";
    std::map<std::vector<size_t>, size_t> count;
    std::map<std::pair<size_t, size_t>, size_t> count_jp;
    std::map<std::pair<size_t, size_t>, size_t> count_ps;
    std::map<std::pair<size_t, size_t>, size_t> count_js;
    std::vector<std::vector<size_t> > answer;
    while (true) {
      bool found = false;
      for (size_t j = 0; j < J && !found; ++j) {
        for (size_t p = 0; p < P && !found; ++p) {
          for (size_t s = 0; s < S && !found; ++s) {
            std::vector<size_t> new_state{j, p, s};
            std::pair<size_t, size_t> jp(j, p);
            std::pair<size_t, size_t> ps(p, s);
            std::pair<size_t, size_t> js(j, s);
            if (!count[new_state] && count_jp[jp] < K && count_ps[ps] < K && count_js[js] < K) {
              ++count[new_state];
              ++count_jp[jp];
              ++count_ps[ps];
              ++count_js[js];
              answer.push_back(new_state);
              found = true;
            }
          }
        }
      }
      if (!found) {
        break;
      }
    }
    std::cout << answer.size() << "\n";
    for (auto &ans : answer) {
      for (size_t i = 0; i < ans.size(); ++i) {
        std::cout << (ans[i] + 1) << ((i == (ans.size() - 1)) ? "\n" : " ");
      }
    }
  }
  return 0;
}
