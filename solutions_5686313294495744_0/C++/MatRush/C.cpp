#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

const int MAXN = 17;

pair<string, string> topics[MAXN];
unordered_map<string, int> firstTopics;
unordered_map<string, int> secondTopics;

int main() {
  int cases;
  scanf("%d", &cases);
  for (int T = 1; T <= cases; ++T) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> topics[i].first >> topics[i].second;
    }
    int ans = 0;
    for (int i = 0; i < 1 << n; ++i) {
      firstTopics.clear();
      secondTopics.clear();
      for (int j = 0; j < n; ++j) {
        if (!((i >> j) & 1)) {
          firstTopics[topics[j].first]++;
          secondTopics[topics[j].second]++;
        }
      }
      bool flag = true;
      for (int j = 0; j < n; ++j) {
        if ((i >> j) & 1) {
          if (!firstTopics.count(topics[j].first)) {
            flag = false;
            break;
          }
          if (!secondTopics.count(topics[j].second)) {
            flag = false;
            break;
          }
        }
      }
      if (flag) {
        ans = max(ans, __builtin_popcount(i));
      }
    }
    printf("Case #%d: %d\n", T, ans);
  }
}