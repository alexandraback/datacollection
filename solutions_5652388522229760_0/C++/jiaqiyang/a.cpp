#include <iostream>
#include <sstream>
#include <set>

int tcase;

int main() {
  freopen("in.txt", "r", stdin);
  std::cin >> tcase;
  for (int tid = 1; tid <= tcase; ++tid) {
    int n;
    std::cin >> n;
    std::set<char> pool;
    if (!n) {
      printf("Case #%d: INSOMNIA\n", tid);
      continue;
    }
    int ans;
    for (ans = n;; ans += n) {
      std::stringstream ss;
      ss << ans;
      std::string temp;
      ss >> temp;
      for (int j = 0; j < temp.length(); ++j) pool.insert(temp[j]);
      if (pool.size() == 10) break;
    }
    printf("Case #%d: %d\n", tid, ans);
  }
  return 0;
}
