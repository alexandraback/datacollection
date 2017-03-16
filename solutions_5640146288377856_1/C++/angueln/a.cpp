#include <cstdio>

using namespace std;

void run(int case_number) {
  int r, c, w;
  scanf("%d %d %d", &r, &c, &w);
  printf("Case #%d: %d\n", case_number,
         r * (c / w) +
         w -
         (c % w == 0 ? 1 : 0)
         );
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    run(i + 1);
  }
  return 0;
}
