#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int r, c, w, t;

int main() {
  scanf("%d", &t);
  for (int ca=1; ca<=t; ca++) {
    int ans = 0;
    scanf("%d %d %d", &r, &c, &w);
    ans = r * (int)floor(c / w);
    ans += c%w==0?w-1:w;
    printf("Case #%d: %d\n", ca, ans);
  }
  return 0;
}

