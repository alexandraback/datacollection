#include <bits/stdc++.h>
using namespace std;

int main() {
  int T, n, i, bm;
  scanf("%d", &T);
  for (int ct = 1; ct <= T; ct ++) {
    scanf("%d", &n);
    for (i = 1, bm = 0; i <= 100; i ++) {
      for (auto& c : to_string(i * n))
	bm |= (1 << (int)(c - '0'));
      if (bm == (1 << 10) - 1) break;
    }    
    if (i > 100) printf("Case #%d: INSOMNIA\n", ct);
    else printf("Case #%d: %d\n", ct, i * n);
  }
  return 0;
}
