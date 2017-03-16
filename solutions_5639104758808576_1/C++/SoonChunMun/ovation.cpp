#include <bits/stdc++.h>
using namespace std;

int t, f, n, c;
char buf[1100];
char digits[1100];

int main() {
  scanf("%d\n", &t);
  for (int ca=1; ca<=t; ca++) {
    fgets(buf, 1100, stdin);
    sscanf(buf, "%d %s", &n, digits);
    f = 0;
    c = 0;
    for (int i=0; i<n+1; i++) {
      int v = (int)(digits[i]-'0');
      if (c < i) {
        f += i-c;
        c += i-c+v;
      } else {
        c+=v;
      }
    }

    printf("Case #%d: %d\n", ca, f);
  }
}
