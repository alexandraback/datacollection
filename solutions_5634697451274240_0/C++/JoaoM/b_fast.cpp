#include <bits/stdc++.h>
using namespace std;

int len;
char s[105];

void printmask(int bm) {
  for (int i = 0; i < len; i ++)
    if (bm & (1 << i)) printf("+");
    else printf("-");
  printf("\n");
}

int bmflip(int bm, int k) {
  for (int i = 0; i <= k; i ++)
    bm ^= 1 << i;
  //printf("interm: "); printmask(bm); 
  int nm = bm;
  for (int i = 0; i <= k; i ++)
    nm ^= (-((bm & (1 << (k - i))) ? 1 : 0) ^ nm) & (1 << i);
  return nm;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int ct = 1; ct <= T; ct ++) {
    scanf(" %s", s);

    len = strlen(s);

    int mask = 0;
    for (int i = 0; i < len; i ++)
      if (s[i] == '+')
	mask |= (1 << i);

    int lr = len;
    while (lr && (mask & (1 << (lr - 1))))
      lr --;

    //printf("\n\n---------------\n\n");
    //printmask(mask);
    
    int ans = 0;
    while (lr) {
      if (!(mask & 1)) {
	//printf("flip type 1\n");
	ans ++;
	mask = bmflip(mask, lr - 1);
	//printmask(mask);
	while (lr && (mask & (1 << (lr - 1))))
	  lr --;
      } else {
	//printf("flip type 2\n");
	ans += 2;
	int np = lr - 1;
	while (np >= 0 && !(mask & (1 << np)))
	  np --;
	mask = bmflip(mask, np);
	//printmask(mask);
	mask = bmflip(mask, lr - 1);
	//printmask(mask);
	while (lr && (mask & (1 << (lr - 1))))
	  lr --;
      }
    }
    
    printf("Case #%d: %d\n", ct, ans);
  }
  return 0;
}
