#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int main() {
  int cases;
  scanf("%i", &cases);
  for (int ncase = 1; ncase <= cases; ++ncase) {
    int a, b;
    scanf("%i%i", &a, &b);

    int cnt = 0;
    for (int i = a; i <= b; ++i) {
      char num[20];
      sprintf(num, "%i", i);
      int len = strlen(num);
      set<int> good;
      for (int j = 0; j < len; ++j) {
        rotate(&num[0], &num[len - 1], &num[len]);
        int value = atoi(num);
        if (i < value && value <= b)
          good.insert(value);
      }
      cnt += good.size();
    }
    printf("Case #%i: %i\n", ncase, cnt);
  }
  return 0;
}
