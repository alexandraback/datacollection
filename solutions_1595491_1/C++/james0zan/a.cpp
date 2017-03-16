#include<cstdio>
using namespace std;

int main() {
  int T, x, ans, a, t, i, p, s, n;
  scanf("%d", &T);
  for  (int TC=1; TC<=T; TC++) {
    scanf("%d%d%d", &n, &s, &p);
    ans = 0;
    for (i=0; i<n; i++) {
      scanf("%d", &x);
      t = x/3;
      if (t + ((x%3)!=0) >= p) ans++;
      else if (s) {
        if (x%3 == 0) if (t) t+=1;
        if (x%3 == 1)t+=1;
        if (x%3 == 2) t+=2;
        if (t>=p) ans++, s--;
      }
    }
    printf("Case #%d: %d\n", TC, ans);
  }
}
