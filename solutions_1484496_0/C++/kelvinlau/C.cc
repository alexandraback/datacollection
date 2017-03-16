#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;

const int N = 512;

int n;
int a[N];

void output(int mask1, int mask2) {
  int flag = 0;
  for (int i = 0; i < n; i++) if (mask1 & (1 << i))
    printf("%s%d", flag++ ? " " : "", a[i]);
  puts("");
  flag = 0;
  for (int i = 0; i < n; i++) if (mask2 & (1 << i))
    printf("%s%d", flag++ ? " " : "", a[i]);
  puts("");
}

int main() {
  int T, tc = 0;
  scanf("%d", &T);
  while (T--) {
    printf("Case #%d:\n", ++tc);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    map<int, int> ss;
    int ok = 0;
    for (int x = 1; x < (1 << n); x++) {
      int s = 0;
      for (int i = 0; i < n; i++) if (x & (1 << i))
        s += a[i];
      if (ss.count(s)) {
        int y = ss[s];
        output(x ^ (x & y), y ^ (x & y));
        ok = 1;
        break;
      } else {
        ss[s] = x;
      }
    }
    if (!ok)
      puts("Impossible");
  }
  return 0;
}
