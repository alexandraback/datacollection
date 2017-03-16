#include <stdio.h>

int main() {
  freopen("B-input.txt", "r", stdin);
  freopen("B-small.txt", "w", stdout);
  int test;
  scanf("%d", &test);
  for(int t=1; t<=test; ++t) {
    printf("Case #%d: ", t);
    int n, *p, maxi = 0, optcost = -1;
    scanf("%d", &n);
    p = new int[n+1];
    for(int i=1; i<=n; ++i) {
      scanf("%d", p+i);
      if(p[i] > maxi)
        maxi = p[i];
    }
    for(int i=1; i<=maxi; ++i) {
      int cost = 0;
      for(int j=1; j<=n; ++j) {
        if(p[j] <= i) continue;
        int diff = p[j]-i;
        cost += diff/i;
        if(diff % i != 0) cost++;
      }
      cost += i;
      if(optcost == -1 || cost < optcost)
        optcost = cost;
    }
    printf("%d\n", optcost);   
    delete [] p;
  }
  return 0;
}