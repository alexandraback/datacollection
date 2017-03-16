#include <cstdio>
#include <climits>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int CanDo(int *diners, int count_diners, int special, int height) {
  vector<int> a(diners, diners + count_diners);

  //printf("Trying for %d %d\n", special, height);
  int splits = 0;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] > height) {
      ++splits;
      if (splits > special) {
        //printf("Failed\n");
        return INT_MAX;
      }

      a.push_back(a[i] - height);
      a[i] = height;
    }
  }

  //printf("Done! %d\n", splits + height);
  return splits + height;
}

int main(void) {
  int test_cases;
  scanf("%d", &test_cases);

  for (int i = 1; i <= test_cases; ++i) {
    int count_diners;
    scanf("%d", &count_diners);

    int *diners = new int[count_diners];
    for (int j = 0; j < count_diners; ++j) {
      scanf("%d", &diners[j]);
    }
    sort(diners, diners + count_diners, greater<int>());

    int min_time = diners[0];
    for (int special = 1; special < diners[0]; ++special) {
      int mi = 0;
      int lo = 1;
      int hi = diners[0];
      while (lo < hi) {
        mi = (lo + hi) / 2;
        if (CanDo(diners, count_diners, special, mi) != INT_MAX) {
          hi = mi;
        } else {
          lo = mi + 1;
        }
      }
      //printf("FOUND MIN for %d and %d: %d\n", special, mi, CanDo(diners, count_diners, special, lo));

      min_time = min(min_time, CanDo(diners, count_diners, special, lo));
    }

    printf("Case #%d: %d\n", i, min_time);
  }

  return 0;
}
