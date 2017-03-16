#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int T, Case = 1;
  scanf("%d", &T);
  while (T--) {
    printf("Case #%d: ", Case++);
    int N;
    scanf("%d", &N);
    vector<double> w[2];
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < N; j++) {
        double weight;
        scanf("%lf", &weight);
        w[i].push_back(weight);
      }
      sort(w[i].begin(), w[i].end());
    }
    int y = 0, z = 0;
    for (int i = 0; i < N; i++) {
      int count = 0;
      for (int j = i; j < N; j++) {
        count += (w[0][j] > w[1][j - i]);
      }
      y = max(y, count);
    }
    for (int i = 0; i < N; i++) {
      bool win = true;
      for (int j = 0; j < w[1].size(); j++) {
        if (w[1][j] > w[0][i]) {
          w[1].erase(w[1].begin() + j);
          win = false;
          break;
        }
      }
      if (win) {
        z++;
      }
    }
    printf("%d %d\n", y, z);
  }
  return 0;
}
