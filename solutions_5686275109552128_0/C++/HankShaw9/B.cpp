#include <iostream>
#include <cstdio>
#include <algorithm>    // std::sort
#include <vector>       // std::vector

using namespace std;

bool JustInTime(std::vector<int> v, int limit) {
  for (int special = 0; special < limit; ++special) {
    int cnt = 0;
    int max = limit - special;
    for (int a : v) {
      cnt += (a - 1) / max;
    }
    if (cnt <= special)
      return true;
  }
  return false;
}

int main(int argc, char* argv[]) {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int d; 
    scanf("%d", &d);
    std::vector<int> v;
    for (int j = 0; j < d; ++j) {
      int a;
      scanf("%d", &a);
      v.push_back(a);
    }
    std::sort(v.begin(), v.end());
    // for (int j = 0; j < d; ++j)
    //   fprintf(stderr, "%d ", v[j]);
    int yl = 0;
    int yr = v.back();    
    // fprintf(stderr, "%d %d \n", yl, yr);
    while (yl < yr) {
      int mid = (yl + yr) / 2;
      if (JustInTime(v, mid)) {
        yr = mid;
      } else {
        yl = mid + 1;
      }
    }
    printf("Case #%d: %d\n", i + 1, yl);
  }
}
