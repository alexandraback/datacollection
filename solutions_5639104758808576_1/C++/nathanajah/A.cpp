#include <bits/stdc++.h>
using namespace std;

int t;
int n;
char c[100005];


int main() {
  scanf("%d", &t);
  int cs = 0;
  while (t--) {
    ++cs;
    scanf("%d", &n);
    scanf("%s", c);
    int cur = 0;
    int res = 0;
    for (int i = 0; i <= n; i++) {
      int num = c[i] - '0';
      if (num > 0) {
        if (cur < i) {
          res += i - cur;
          cur = i;
        }
        cur += num;
      }
    }
    printf("Case #%d: %d\n", cs, res);
  }
}
