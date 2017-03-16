#include <bits/stdc++.h>
using namespace std;

char s[105];

bitset<105> bmflip(bitset<105> bm, int k) {
  for (int i = 0; i <= k; i ++)
    bm.flip(i);
  bitset <105> nm = bm;
  for (int i = 0; i <= k; i ++)
    nm.set(i, bm.test(k - i));
  return nm;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int ct = 1; ct <= T; ct ++) {
    scanf(" %s", s);

    int len = strlen(s);

    bitset <105> mask;
    for (int i = 0; i < len; i ++)
      if (s[i] == '+')
	mask.set(i);

    int lr = len;
    while (lr && mask.test(lr - 1))
      lr --;

    int ans = 0;
    while (lr) {
      if (!mask.test(0)) {
	ans ++;
	mask = bmflip(mask, lr - 1);

	while (lr && mask.test(lr - 1))
	  lr --;
      } else {
	ans ++;
	int np = lr - 1;
	while (np >= 0 && !mask.test(np))
	  np --;
	mask = bmflip(mask, np);
      }
    }
    
    printf("Case #%d: %d\n", ct, ans);
  }
  return 0;
}
