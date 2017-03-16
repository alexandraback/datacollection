#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>
using namespace std;

const int MAXN = 111;

int lists[2 * MAXN][MAXN];
vector<vector<int> > vec;
unordered_map<int, int> mp;

bool cmp(const vector<int>& a, const vector<int>& b) {
  int n = a.size();
  for (int i = 0; i < n; ++i) {
    if (a[i] > b[i]) {
      return false;
    } else if (a[i] < b[i]) {
      return true;
    }
  }
  return false;
}

int main() {
  int cases;
  scanf("%d", &cases);
  for (int T = 1; T <= cases; ++T) {
    int n;
    scanf("%d", &n);
    mp.clear();
    vec.resize(2 * n - 1);
    for (int i = 0; i < 2 * n - 1; ++i) {
      vec[i].clear();
      for (int j = 0; j < n; ++j) {
        int tmp;
        scanf("%d", &tmp);
        vec[i].push_back(tmp);
        mp[vec[i][j]] ++;
      }
    }
    vector<int> last;
    for (auto x : mp) {
      // printf("haha%d: %d\n", x.first, x.second);
      if (x.second % 2 == 1) {
        last.push_back(x.first);
      }
    }
    sort(last.begin(), last.end());
    vec.push_back(last);
    // sort(vec.begin(), vec.end(), cmp);
    // for (int i = 0; i < 2 * n; ++i) {
    //   for (int j = 0; j < n; ++j) {
    //     printf("%d ", vec[i][j]);
    //   }
    //   puts("");
    // }
    printf("Case #%d: ", T);
    for (int i = 0; i < n; ++i) {
      if (i) putchar(' ');
      printf("%d", last[i]);
    }
    puts("");
  }
}