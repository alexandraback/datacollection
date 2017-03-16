#include <vector>
#include <string>

using namespace std;

int main(void) {
  int t;
  int case_cnt = 1;
  scanf("%d", &t);
  while (t--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int cnt = 0;
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        if ((i & j) < c) cnt++;
      }
    }
    printf("Case #%d: %d\n", case_cnt++, cnt);
  }
  return 0;
}

