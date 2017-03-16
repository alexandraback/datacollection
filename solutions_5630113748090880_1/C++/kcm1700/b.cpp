#include <cstdio>
#include <set>
#include <vector>
#include <deque>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
  int T;
  scanf("%d", &T);
  for (int testcase = 1; testcase <= T; testcase++)
  {
    int n;
    scanf("%d", &n);
    set<int> ans;
    for (int i = 0; i < 2 * n - 1; i++) {
      for (int j = 0; j < n; j++) {
        int val;
        scanf("%d", &val);
        if (ans.count(val)) {
          ans.erase(val);
        }
        else {
          ans.insert(val);
        }
      }
    }
    printf("Case #%d:", testcase);
    for (auto v : ans) {
      printf(" %d", v);
    }
    puts("");
  }
  return 0;
}