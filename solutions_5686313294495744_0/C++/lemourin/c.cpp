#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
#define scanf(args...) (scanf(args) ? : 0)
const int MAXN = 1000005;

char buffer1[MAXN], buffer2[MAXN];

int solve() {
  std::vector<std::pair<std::string, std::string>> vec;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s%s", buffer1, buffer2);
    vec.push_back({buffer1, buffer2});
  }
  
  int res = 0;
  for (unsigned mask = 0; mask < (1 << n); mask++) {
    std::set<std::string> s1, s2;
    for (int i = 0; i < n; i++)
      if (mask & (1 << i)) {
        s1.insert(vec[i].first);
        s2.insert(vec[i].second);
      }
    
    int cnt = 0;
    for (int i = 0; i < n; i++)
      if (!(mask & (1 << i))) {
        if (s1.find(vec[i].first) != s1.end() && s2.find(vec[i].second) != s2.end()) {
          cnt++;
        }
      }
    res = std::max(cnt, res);
  }
  return res;
}

int main() {
  int t;
  scanf("%d", &t);

  for (int i = 1; i <= t; i++) {
    printf("Case #%d: %d\n", i, solve());
  }
}
